using System;
using System.Drawing;
using System.Collections;
using System.ComponentModel;
using System.Windows.Forms;
using System.Net.Sockets;
using System.Net;

namespace SocketServer
{
	/// <summary>
	/// Summary description for SocketServerForm.
	/// </summary>
	public class SocketServerForm : System.Windows.Forms.Form
	{
		private System.Windows.Forms.Button buttonStart;
		/// <summary>
		/// Required designer variable.
		/// </summary>
		private System.ComponentModel.Container components = null;
		private System.Windows.Forms.Button button1;
		private System.Windows.Forms.Button cmdReceiveData;
		private System.Windows.Forms.TextBox txtDataRx;
		private System.Windows.Forms.TextBox txtData;
		private System.Windows.Forms.Button cmdSendData;
		private System.Windows.Forms.Button button2;


		private Socket m_socListener;

		/// <summary>
		/// The main entry point for the application.
		/// </summary>
		[STAThread]
		static void Main() 
		{
			Application.Run(new SocketServerForm());
		}

		public SocketServerForm()
		{
			//
			// Required for Windows Form Designer support
			//
			InitializeComponent();

			//
			// TODO: Add any constructor code after InitializeComponent call
			//
		}

		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		protected override void Dispose( bool disposing )
		{
			if(this.m_socListener != null && this.m_socListener.Connected)
			{
				this.m_socListener.Close();
			}

			if( disposing )
			{
				if(components != null)
				{
					components.Dispose();
				}
			}
			base.Dispose( disposing );
		}

		#region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		private void InitializeComponent()
		{
			this.buttonStart = new System.Windows.Forms.Button();
			this.button1 = new System.Windows.Forms.Button();
			this.cmdReceiveData = new System.Windows.Forms.Button();
			this.txtDataRx = new System.Windows.Forms.TextBox();
			this.txtData = new System.Windows.Forms.TextBox();
			this.cmdSendData = new System.Windows.Forms.Button();
			this.button2 = new System.Windows.Forms.Button();
			this.SuspendLayout();
			// 
			// buttonStart
			// 
			this.buttonStart.Location = new System.Drawing.Point(8, 8);
			this.buttonStart.Name = "buttonStart";
			this.buttonStart.Size = new System.Drawing.Size(400, 23);
			this.buttonStart.TabIndex = 0;
			this.buttonStart.Text = "Start";
			this.buttonStart.Click += new System.EventHandler(this.buttonStart_Click);
			// 
			// button1
			// 
			this.button1.Location = new System.Drawing.Point(144, 184);
			this.button1.Name = "button1";
			this.button1.Size = new System.Drawing.Size(120, 23);
			this.button1.TabIndex = 1;
			this.button1.Text = "Accept Connection";
			this.button1.Click += new System.EventHandler(this.button1_Click);
			// 
			// cmdReceiveData
			// 
			this.cmdReceiveData.Location = new System.Drawing.Point(352, 112);
			this.cmdReceiveData.Name = "cmdReceiveData";
			this.cmdReceiveData.Size = new System.Drawing.Size(56, 56);
			this.cmdReceiveData.TabIndex = 9;
			this.cmdReceiveData.Text = "Rx";
			this.cmdReceiveData.Click += new System.EventHandler(this.cmdReceiveData_Click);
			// 
			// txtDataRx
			// 
			this.txtDataRx.Enabled = false;
			this.txtDataRx.Location = new System.Drawing.Point(8, 112);
			this.txtDataRx.Multiline = true;
			this.txtDataRx.Name = "txtDataRx";
			this.txtDataRx.Size = new System.Drawing.Size(344, 56);
			this.txtDataRx.TabIndex = 8;
			this.txtDataRx.Text = "";
			// 
			// txtData
			// 
			this.txtData.Location = new System.Drawing.Point(8, 40);
			this.txtData.Multiline = true;
			this.txtData.Name = "txtData";
			this.txtData.Size = new System.Drawing.Size(344, 56);
			this.txtData.TabIndex = 7;
			this.txtData.Text = "enter data to send here...";
			// 
			// cmdSendData
			// 
			this.cmdSendData.Location = new System.Drawing.Point(352, 40);
			this.cmdSendData.Name = "cmdSendData";
			this.cmdSendData.Size = new System.Drawing.Size(56, 56);
			this.cmdSendData.TabIndex = 6;
			this.cmdSendData.Text = "Tx";
			this.cmdSendData.Click += new System.EventHandler(this.cmdSendData_Click);
			// 
			// button2
			// 
			this.button2.DialogResult = System.Windows.Forms.DialogResult.OK;
			this.button2.Location = new System.Drawing.Point(336, 184);
			this.button2.Name = "button2";
			this.button2.TabIndex = 10;
			this.button2.Text = "Close";
			this.button2.Click += new System.EventHandler(this.button2_Click);
			// 
			// SocketServerForm
			// 
			this.AutoScaleBaseSize = new System.Drawing.Size(5, 13);
			this.ClientSize = new System.Drawing.Size(416, 219);
			this.Controls.Add(this.button2);
			this.Controls.Add(this.cmdReceiveData);
			this.Controls.Add(this.txtDataRx);
			this.Controls.Add(this.txtData);
			this.Controls.Add(this.cmdSendData);
			this.Controls.Add(this.button1);
			this.Controls.Add(this.buttonStart);
			this.Name = "SocketServerForm";
			this.Text = "SocketServerForm";
			this.ResumeLayout(false);

		}
		#endregion

		private void buttonStart_Click(object sender, System.EventArgs e)
		{
			m_socListener = new Socket(AddressFamily.InterNetwork,SocketType.Stream,ProtocolType.Tcp);		
			IPEndPoint ipLocal = new IPEndPoint ( IPAddress.Any ,8000);
			//bind to local IP Address...
			m_socListener.Bind( ipLocal );
			//start listening...
			m_socListener.Listen (4);
			this.buttonStart.Enabled = false;
		}

		Socket m_commSocket = null;
		private void button1_Click(object sender, System.EventArgs e)
		{
			m_commSocket = m_socListener.Accept();
		}

		private void cmdSendData_Click(object sender, System.EventArgs e)
		{
			try
			{
				Object objData = txtData.Text;
				byte[] byData = System.Text.Encoding.ASCII.GetBytes(objData.ToString ());
				m_commSocket.Send (byData);
			}
			catch(SocketException se)
			{
				MessageBox.Show (se.Message );
			}
		}

		private void cmdReceiveData_Click(object sender, System.EventArgs e)
		{
			try
			{
				byte [] buffer = new byte[1024];
				int iRx = m_commSocket.Receive (buffer);
				char[] chars = new char[iRx];

				System.Text.Decoder d = System.Text.Encoding.UTF8.GetDecoder();
				int charLen = d.GetChars(buffer, 0, iRx, chars, 0);
				System.String szData = new System.String(chars);
				txtDataRx.Text = szData;
			}
			catch(SocketException se)
			{
				MessageBox.Show (se.Message );
			}
		}

		private void button2_Click(object sender, System.EventArgs e)
		{
			if(this.m_commSocket != null && m_commSocket.Connected)
			{
				m_commSocket.Close();
				m_commSocket =null;
			}
		}


	}
}
