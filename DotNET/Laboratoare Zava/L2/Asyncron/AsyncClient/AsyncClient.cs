using System;
using System.Drawing;
using System.Collections;
using System.ComponentModel;
using System.Windows.Forms;
using System.Data;
using System.Net;
using System.Net.Sockets;

namespace AsyncClient
{
	/// <summary>
	/// Summary description for Form1.
	/// </summary>
	public class Form1 : System.Windows.Forms.Form
	{
		
		byte[] m_DataBuffer = new byte [10];
		IAsyncResult m_asynResult;
		public AsyncCallback pfnCallBack ;
		public Socket m_socClient;
		private System.Windows.Forms.GroupBox groupBox1;
		private System.Windows.Forms.Label label1;
		private System.Windows.Forms.Label label2;
		private System.Windows.Forms.TextBox txtPort;
		private System.Windows.Forms.Button cmdSend;
		private System.Windows.Forms.TextBox txtDataRx;
		private System.Windows.Forms.GroupBox groupBox2;
		private System.Windows.Forms.GroupBox groupBox3;
		private System.Windows.Forms.Button cmdConnect;
		private System.Windows.Forms.Button cmdClose;
		private System.Windows.Forms.TextBox txtDataTx;
		private System.Windows.Forms.TextBox txtIPAddr;
		/// <summary>
		/// Required designer variable.
		/// </summary>
		private System.ComponentModel.Container components = null;

		public Form1()
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
			if( disposing )
			{
				if (components != null) 
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
			this.groupBox1 = new System.Windows.Forms.GroupBox();
			this.cmdClose = new System.Windows.Forms.Button();
			this.cmdConnect = new System.Windows.Forms.Button();
			this.txtPort = new System.Windows.Forms.TextBox();
			this.label2 = new System.Windows.Forms.Label();
			this.txtIPAddr = new System.Windows.Forms.TextBox();
			this.label1 = new System.Windows.Forms.Label();
			this.txtDataTx = new System.Windows.Forms.TextBox();
			this.cmdSend = new System.Windows.Forms.Button();
			this.txtDataRx = new System.Windows.Forms.TextBox();
			this.groupBox2 = new System.Windows.Forms.GroupBox();
			this.groupBox3 = new System.Windows.Forms.GroupBox();
			this.groupBox1.SuspendLayout();
			this.SuspendLayout();
			// 
			// groupBox1
			// 
			this.groupBox1.Controls.Add(this.cmdClose);
			this.groupBox1.Controls.Add(this.cmdConnect);
			this.groupBox1.Controls.Add(this.txtPort);
			this.groupBox1.Controls.Add(this.label2);
			this.groupBox1.Controls.Add(this.txtIPAddr);
			this.groupBox1.Controls.Add(this.label1);
			this.groupBox1.Location = new System.Drawing.Point(8, 8);
			this.groupBox1.Name = "groupBox1";
			this.groupBox1.Size = new System.Drawing.Size(280, 80);
			this.groupBox1.TabIndex = 0;
			this.groupBox1.TabStop = false;
			this.groupBox1.Text = "Settings";
			// 
			// cmdClose
			// 
			this.cmdClose.Enabled = false;
			this.cmdClose.Location = new System.Drawing.Point(160, 48);
			this.cmdClose.Name = "cmdClose";
			this.cmdClose.Size = new System.Drawing.Size(96, 24);
			this.cmdClose.TabIndex = 5;
			this.cmdClose.Text = "Close";
			this.cmdClose.Click += new System.EventHandler(this.cmdClose_Click);
			// 
			// cmdConnect
			// 
			this.cmdConnect.Location = new System.Drawing.Point(160, 16);
			this.cmdConnect.Name = "cmdConnect";
			this.cmdConnect.Size = new System.Drawing.Size(96, 24);
			this.cmdConnect.TabIndex = 4;
			this.cmdConnect.Text = "Connect";
			this.cmdConnect.Click += new System.EventHandler(this.cmdConnect_Click);
			// 
			// txtPort
			// 
			this.txtPort.Location = new System.Drawing.Point(72, 48);
			this.txtPort.Name = "txtPort";
			this.txtPort.Size = new System.Drawing.Size(40, 20);
			this.txtPort.TabIndex = 3;
			this.txtPort.Text = "8000";
			// 
			// label2
			// 
			this.label2.Location = new System.Drawing.Point(16, 48);
			this.label2.Name = "label2";
			this.label2.Size = new System.Drawing.Size(32, 16);
			this.label2.TabIndex = 2;
			this.label2.Text = "Port:";
			// 
			// txtIPAddr
			// 
			this.txtIPAddr.Location = new System.Drawing.Point(72, 24);
			this.txtIPAddr.Name = "txtIPAddr";
			this.txtIPAddr.Size = new System.Drawing.Size(80, 20);
			this.txtIPAddr.TabIndex = 1;
			this.txtIPAddr.Text = "127.0.0.1";
			// 
			// label1
			// 
			this.label1.Location = new System.Drawing.Point(16, 24);
			this.label1.Name = "label1";
			this.label1.Size = new System.Drawing.Size(48, 16);
			this.label1.TabIndex = 0;
			this.label1.Text = "Host IP:";
			// 
			// txtDataTx
			// 
			this.txtDataTx.Location = new System.Drawing.Point(16, 104);
			this.txtDataTx.Multiline = true;
			this.txtDataTx.Name = "txtDataTx";
			this.txtDataTx.ScrollBars = System.Windows.Forms.ScrollBars.Vertical;
			this.txtDataTx.Size = new System.Drawing.Size(224, 56);
			this.txtDataTx.TabIndex = 1;
			this.txtDataTx.Text = "";
			// 
			// cmdSend
			// 
			this.cmdSend.Location = new System.Drawing.Point(248, 104);
			this.cmdSend.Name = "cmdSend";
			this.cmdSend.Size = new System.Drawing.Size(32, 56);
			this.cmdSend.TabIndex = 2;
			this.cmdSend.Text = "Tx";
			this.cmdSend.Click += new System.EventHandler(this.cmdSend_Click);
			// 
			// txtDataRx
			// 
			this.txtDataRx.Location = new System.Drawing.Point(16, 192);
			this.txtDataRx.Multiline = true;
			this.txtDataRx.Name = "txtDataRx";
			this.txtDataRx.ScrollBars = System.Windows.Forms.ScrollBars.Vertical;
			this.txtDataRx.Size = new System.Drawing.Size(256, 72);
			this.txtDataRx.TabIndex = 3;
			this.txtDataRx.Text = "";
			// 
			// groupBox2
			// 
			this.groupBox2.Location = new System.Drawing.Point(8, 176);
			this.groupBox2.Name = "groupBox2";
			this.groupBox2.Size = new System.Drawing.Size(280, 96);
			this.groupBox2.TabIndex = 4;
			this.groupBox2.TabStop = false;
			this.groupBox2.Text = "Data Arrived";
			// 
			// groupBox3
			// 
			this.groupBox3.Location = new System.Drawing.Point(8, 88);
			this.groupBox3.Name = "groupBox3";
			this.groupBox3.Size = new System.Drawing.Size(280, 80);
			this.groupBox3.TabIndex = 5;
			this.groupBox3.TabStop = false;
			this.groupBox3.Text = "Send Data";
			// 
			// Form1
			// 
			this.AutoScaleBaseSize = new System.Drawing.Size(5, 13);
			this.ClientSize = new System.Drawing.Size(292, 273);
			this.Controls.Add(this.txtDataRx);
			this.Controls.Add(this.cmdSend);
			this.Controls.Add(this.txtDataTx);
			this.Controls.Add(this.groupBox1);
			this.Controls.Add(this.groupBox2);
			this.Controls.Add(this.groupBox3);
			this.Name = "Form1";
			this.Text = "Socket Client in C#";
			this.groupBox1.ResumeLayout(false);
			this.ResumeLayout(false);

		}
		#endregion

		/// <summary>
		/// The main entry point for the application.
		/// </summary>
		[STAThread]
		static void Main() 
		{
			Application.Run(new Form1());
		}
		private void EnableCommands( bool abEnableConnect ) 
		{
			cmdClose.Enabled = !abEnableConnect;
			cmdConnect.Enabled = abEnableConnect;
		}
		private void cmdConnect_Click(object sender, System.EventArgs e)
		{
			
			try
			{
				EnableCommands(true);
				//create the socket instance...
				m_socClient = new Socket (AddressFamily.InterNetwork,SocketType.Stream ,ProtocolType.Tcp );

				// get the remote IP address...
				IPAddress ip = IPAddress.Parse (txtIPAddr.Text);
				int iPortNo = System.Convert.ToInt16 ( txtPort.Text);
				//create the end point 
				IPEndPoint ipEnd = new IPEndPoint (ip.Address,iPortNo);
				//connect to the remote host...
				m_socClient.Connect ( ipEnd );
				EnableCommands(false);
				//watch for data ( asynchronously )...
				WaitForData();
			}
			catch(SocketException se)
			{
				MessageBox.Show (se.Message );
				EnableCommands(true);
			}
		}
		public void WaitForData()
		{
			try
			{
				if  ( pfnCallBack == null ) 
				{
					pfnCallBack = new AsyncCallback (OnDataReceived);
				}
				CSocketPacket theSocPkt = new CSocketPacket ();
				theSocPkt.thisSocket = m_socClient;
				// now start to listen for any data...
				m_asynResult = m_socClient.BeginReceive (theSocPkt.dataBuffer ,0,theSocPkt.dataBuffer.Length ,SocketFlags.None,pfnCallBack,theSocPkt);
			}
			catch(SocketException se)
			{
				MessageBox.Show (se.Message );
			}

		}

		private void cmdSend_Click(object sender, System.EventArgs e)
		{
			try
			{
				Object objData = txtDataTx.Text;
				byte[] byData = System.Text.Encoding.ASCII.GetBytes(objData.ToString ());
				m_socClient.Send (byData);
			}
			catch(SocketException se)
			{
				MessageBox.Show (se.Message );
			}
		
		}

		private void cmdClose_Click(object sender, System.EventArgs e)
		{
			if ( m_socClient != null )
			{
				//m_socClient.Shutdown (SocketShutdown.Send);
				m_socClient.Close ();
				m_socClient = null;
				EnableCommands(true);
			}
		}

		public class CSocketPacket
		{
			public System.Net.Sockets.Socket thisSocket;
			public byte[] dataBuffer = new byte[1];
		}


		

		public  void OnDataReceived(IAsyncResult asyn)
		{
			try
			{
				CSocketPacket theSockId = (CSocketPacket)asyn.AsyncState ;
				//end receive...
				int iRx  = 0 ;
				iRx = theSockId.thisSocket.EndReceive (asyn);
				char[] chars = new char[iRx +  1];
				System.Text.Decoder d = System.Text.Encoding.UTF8.GetDecoder();
				int charLen = d.GetChars(theSockId.dataBuffer, 0, iRx, chars, 0);
				System.String szData = new System.String(chars);
				txtDataRx.Text = txtDataRx.Text + szData;
				WaitForData();
			}
			catch (ObjectDisposedException )
			{
				System.Diagnostics.Debugger.Log(0,"1","\nOnDataReceived: Socket has been closed\n");
			}
			catch(SocketException se)
			{
				MessageBox.Show (se.Message );
			}
		}


		
	
	}
}



