using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Net;
namespace Вычислятор
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void buttonStart_Click(object sender, EventArgs e)
        {
           IPAddress ip = IPAddress.Parse(textBoxIp.Text);
           IPAddress mask = IPAddress.Parse(textBoxMask.Text);

            byte[] ipByte = ip.GetAddressBytes();
            byte[] maskByte = mask.GetAddressBytes();
            byte[] networkBytes = new byte[4];
            byte[] broadcastBytes = new byte[4];
            for (int i = 0; i < 4; i++)
            {
                networkBytes[i] = (byte)(ipByte[i] & maskByte[i]);
                broadcastBytes[i] = (byte)(ipByte[i] | ~maskByte[i]);
            }

            string network = new IPAddress(networkBytes).ToString();
            string broadcast = new IPAddress(broadcastBytes).ToString();

            int col = 0;
            for (int i = 0; i < 4; i++)
            {
                for (int j = 0; j < 8; j++)
                    if ((maskByte[i] & (1 << j)) == 0)
                    {
                        col++;
                    }
            }
            int colNetworks = (int)(Math.Pow(2, col));
            int colHosts = (int)(Math.Pow(2, col)) - 2;

            Form2 form = new Form2();
            form.Show();
            form.labelAddressNetwork.Text = $"Адресс сети {network}";
            form.labelBroadcastNetwork.Text = $"Широковещательный адрес: {broadcast}";
            form.labelCountIpAddress.Text = $"Количество IP-адресов: {colNetworks}";
            form.labelCountHosts.Text = $"Количество узлов в сети: {colHosts}";
        }

      
    }
}
