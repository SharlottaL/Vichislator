namespace Вычислятор
{
    partial class Form2
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.labelAddressNetwork = new System.Windows.Forms.Label();
            this.labelBroadcastNetwork = new System.Windows.Forms.Label();
            this.labelCountIpAddress = new System.Windows.Forms.Label();
            this.labelCountHosts = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // labelAddressNetwork
            // 
            this.labelAddressNetwork.AutoSize = true;
            this.labelAddressNetwork.Location = new System.Drawing.Point(23, 39);
            this.labelAddressNetwork.Name = "labelAddressNetwork";
            this.labelAddressNetwork.Size = new System.Drawing.Size(35, 13);
            this.labelAddressNetwork.TabIndex = 0;
            this.labelAddressNetwork.Text = "label1";
            // 
            // labelBroadcastNetwork
            // 
            this.labelBroadcastNetwork.AutoSize = true;
            this.labelBroadcastNetwork.Location = new System.Drawing.Point(23, 77);
            this.labelBroadcastNetwork.Name = "labelBroadcastNetwork";
            this.labelBroadcastNetwork.Size = new System.Drawing.Size(35, 13);
            this.labelBroadcastNetwork.TabIndex = 1;
            this.labelBroadcastNetwork.Text = "label2";
            // 
            // labelCountIpAddress
            // 
            this.labelCountIpAddress.AutoSize = true;
            this.labelCountIpAddress.Location = new System.Drawing.Point(23, 116);
            this.labelCountIpAddress.Name = "labelCountIpAddress";
            this.labelCountIpAddress.Size = new System.Drawing.Size(35, 13);
            this.labelCountIpAddress.TabIndex = 2;
            this.labelCountIpAddress.Text = "label3";
            // 
            // labelCountHosts
            // 
            this.labelCountHosts.AutoSize = true;
            this.labelCountHosts.Location = new System.Drawing.Point(23, 155);
            this.labelCountHosts.Name = "labelCountHosts";
            this.labelCountHosts.Size = new System.Drawing.Size(35, 13);
            this.labelCountHosts.TabIndex = 3;
            this.labelCountHosts.Text = "label4";
            // 
            // Form2
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(344, 222);
            this.Controls.Add(this.labelCountHosts);
            this.Controls.Add(this.labelCountIpAddress);
            this.Controls.Add(this.labelBroadcastNetwork);
            this.Controls.Add(this.labelAddressNetwork);
            this.Name = "Form2";
            this.Text = "Form2";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        public System.Windows.Forms.Label labelAddressNetwork;
        public System.Windows.Forms.Label labelBroadcastNetwork;
        public System.Windows.Forms.Label labelCountIpAddress;
        public System.Windows.Forms.Label labelCountHosts;
    }
}