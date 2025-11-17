#define _CRT_SECURE_NO_WARNINGS
#include<Windows.h>
#include<CommCtrl.h>
#include<cstdio>
#include"resource.h"
#pragma comment(lib, "Comctl32.lib")

BOOL CALLBACK DlgProc(HWND hwnd, UINT uMsg, WPARAM, LPARAM lParam);
CHAR* FormatAddress(CHAR szBuffer[], CONST CHAR szMessage[], DWORD dwAddress);
CHAR* FormatNumber(CHAR szBuffer[], CONST CHAR szMessage[], DWORD dwNumber);


INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInst, LPSTR lpCmdLine, INT nCmdShow)
{
	DialogBoxParam(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), NULL, (DLGPROC)DlgProc, 0);
	return 0;
}

BOOL CALLBACK DlgProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_INITDIALOG:
	{
		InitCommonControls();
		HWND hSpinPrefix = GetDlgItem(hwnd, IDC_SPIN_PREFIX);
		SendMessage(hSpinPrefix, UDM_SETRANGE, 0, 32);
	}
		break;
	case WM_COMMAND:
	{
		HWND hIPaddress = GetDlgItem(hwnd, IDC_IPADDRESS);
		HWND hIPMask = GetDlgItem(hwnd, IDC_IPADDRESS_MASK);
		HWND hEditPrefix = GetDlgItem(hwnd, IDC_EDIT_PREFIX);
		HWND hStaticInfo = GetDlgItem(hwnd, IDC_STATIC_INFO);

		DWORD dwIPaddress = 0;
		DWORD dwIPmask = UINT_MAX;
		DWORD dwIPprefix = 0;
		CHAR szIPprefix[3] = {};

		switch (LOWORD(wParam))
		{
		case IDC_IPADDRESS:
		{
			if (HIWORD(wParam) == EN_CHANGE)
			{
				SendMessage(hIPaddress, IPM_GETADDRESS, 0, (LPARAM)&dwIPaddress);
				DWORD dwFirst = FIRST_IPADDRESS(dwIPaddress);
				if (dwFirst < 128)dwIPprefix = 8;
				else if (dwFirst < 192)dwIPprefix = 16;
				else if (dwFirst < 224)dwIPprefix = 24;

				sprintf(szIPprefix, "%i", dwIPprefix);
				SendMessage(hEditPrefix, WM_SETTEXT, 0, (LPARAM)szIPprefix);
				dwIPmask <<= (32 - dwIPprefix);
				SendMessage(hIPMask, IPM_SETADDRESS, 0, dwIPmask);
			}
		}
		break;
		case IDC_EDIT_PREFIX:
		{
			if (HIWORD(wParam) == EN_CHANGE)
			{
				SendMessage(hEditPrefix, WM_GETTEXT, 3, (LPARAM)szIPprefix);
				dwIPprefix = atoi(szIPprefix);
				if (dwIPprefix > 31)
				{
					dwIPprefix = 31;
					strcpy(szIPprefix, "31");
					SendMessage(hEditPrefix, WM_SETTEXT, 0, (LPARAM)szIPprefix);
				}
				dwIPmask <<= (32 - dwIPprefix);
				SendMessage(hIPMask, IPM_SETADDRESS, 0, dwIPmask);
			}
		}
		break;
		case IDOK:
		{
			SendMessage(hIPaddress, IPM_GETADDRESS, 0, (LPARAM)&dwIPaddress);
			SendMessage(hIPMask, IPM_GETADDRESS, 0, (LPARAM)&dwIPmask);
			DWORD dwNetworkAddress = dwIPaddress & dwIPmask;
			DWORD dwBroadcastAddress = dwIPaddress | ~dwIPmask;
			DWORD dwCapacity = dwBroadcastAddress - dwNetworkAddress + 1;
			DWORD dwHosts = dwCapacity - 2;

			CONST INT SIZE = 256;
			CHAR szInfo[SIZE] = "";
			CHAR szNetwork[SIZE] = "";
			CHAR szBroadcast[SIZE] = "";
			CHAR szCapacity[SIZE] = "";
			CHAR szHosts[SIZE] = "";

			sprintf
			(
				szInfo,
				"Info:\n%s\n%s\n%s\n%s\n",
				FormatAddress(szNetwork, "Адрес сети:\t\t\t", dwNetworkAddress),
				FormatAddress(szBroadcast, "Широковещательный адрес:\t", dwBroadcastAddress),
				FormatNumber(szCapacity, "Кол-во IP-адресов:\t", dwCapacity),
				FormatNumber(szHosts, "Кол-во узлов:\t\t", dwHosts)
			);
			SendMessage(hStaticInfo, WM_SETTEXT, 0, (LPARAM)szInfo);
		}
		break;
		case IDCANCEL:
			EndDialog(hwnd, 0);
			break;
		}
	}
	break;
	case WM_NOTIFY:
	{
		if (((LPNMHDR)lParam)->hwndFrom == GetDlgItem(hwnd, IDC_IPMASK))
		{
			HWND hIPmask = GetDlgItem(hwnd, IDC_IPMASK);
			HWND hEditPrefix = GetDlgItem(hwnd, IDC_EDIT_PREFIX);
			DWORD dwIPmask = UINT_MAX;
			DWORD dwIPprefix = 0;
			CHAR szIPprefix[3] = {};

			SendMessage(hIPmask, IPM_GETADDRESS, 0, (LPARAM)&dwIPmask);
			for (; dwIPmask >> 31; dwIPmask <<= 1)dwIPprefix++;

			sprintf(szIPprefix, "%i", dwIPprefix);
			SendMessage(hEditPrefix, WM_SETTEXT, 0, (LPARAM)szIPprefix);
		}
		break;
	}
	break;
	case WM_CLOSE:
		EndDialog(hwnd, 0);
	}
	return FALSE;
}

CHAR* FormatAddress(CHAR szBuffer[], CONST CHAR szMessage[], DWORD dwAddress)
{
	sprintf
	(
		szBuffer,
		"%s%i.%i.%i.%i;",
		szMessage,
		FIRST_IPADDRESS(dwAddress),
		SECOND_IPADDRESS(dwAddress),
		THIRD_IPADDRESS(dwAddress),
		FOURTH_IPADDRESS(dwAddress)
	);
	return szBuffer;
}
CHAR* FormatNumber(CHAR szBuffer[], CONST CHAR szMessage[], DWORD dwNumber)
{
	sprintf
	(
		szBuffer,
		"%s%i;",
		szMessage,
		dwNumber
	);
	return szBuffer;
}
		