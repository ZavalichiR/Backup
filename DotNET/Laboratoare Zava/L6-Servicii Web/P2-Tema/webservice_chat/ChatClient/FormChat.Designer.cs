namespace ChatClient
{
    partial class FormChat
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
            this.textBoxMessages = new System.Windows.Forms.TextBox();
            this.textBoxMessageToSend = new System.Windows.Forms.TextBox();
            this.buttonSend = new System.Windows.Forms.Button();
            this.buttonLogin = new System.Windows.Forms.Button();
            this.textBox1 = new System.Windows.Forms.TextBox();
            this.SuspendLayout();
            // 
            // textBoxMessages
            // 
            this.textBoxMessages.BackColor = System.Drawing.SystemColors.ButtonHighlight;
            this.textBoxMessages.Enabled = false;
            this.textBoxMessages.Location = new System.Drawing.Point(12, 113);
            this.textBoxMessages.Multiline = true;
            this.textBoxMessages.Name = "textBoxMessages";
            this.textBoxMessages.ReadOnly = true;
            this.textBoxMessages.Size = new System.Drawing.Size(461, 274);
            this.textBoxMessages.TabIndex = 0;
            this.textBoxMessages.TextChanged += new System.EventHandler(this.textBoxMessages_TextChanged);
            // 
            // textBoxMessageToSend
            // 
            this.textBoxMessageToSend.Enabled = false;
            this.textBoxMessageToSend.Location = new System.Drawing.Point(12, 38);
            this.textBoxMessageToSend.Multiline = true;
            this.textBoxMessageToSend.Name = "textBoxMessageToSend";
            this.textBoxMessageToSend.ReadOnly = true;
            this.textBoxMessageToSend.Size = new System.Drawing.Size(358, 69);
            this.textBoxMessageToSend.TabIndex = 1;
            this.textBoxMessageToSend.KeyUp += new System.Windows.Forms.KeyEventHandler(this.textBoxMessageToSend_KeyUp);
            // 
            // buttonSend
            // 
            this.buttonSend.BackColor = System.Drawing.Color.White;
            this.buttonSend.Enabled = false;
            this.buttonSend.Font = new System.Drawing.Font("Microsoft Sans Serif", 14.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.buttonSend.ForeColor = System.Drawing.Color.DarkOrange;
            this.buttonSend.Location = new System.Drawing.Point(376, 38);
            this.buttonSend.Name = "buttonSend";
            this.buttonSend.Size = new System.Drawing.Size(97, 69);
            this.buttonSend.TabIndex = 2;
            this.buttonSend.Text = "Send";
            this.buttonSend.UseVisualStyleBackColor = false;
            this.buttonSend.Click += new System.EventHandler(this.buttonSend_Click);
            // 
            // buttonLogin
            // 
            this.buttonLogin.BackColor = System.Drawing.Color.White;
            this.buttonLogin.Enabled = false;
            this.buttonLogin.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.buttonLogin.ForeColor = System.Drawing.Color.DarkOrange;
            this.buttonLogin.Location = new System.Drawing.Point(188, 8);
            this.buttonLogin.Name = "buttonLogin";
            this.buttonLogin.Size = new System.Drawing.Size(94, 26);
            this.buttonLogin.TabIndex = 3;
            this.buttonLogin.Text = "SetName";
            this.buttonLogin.UseVisualStyleBackColor = false;
            this.buttonLogin.Click += new System.EventHandler(this.buttonLogin_Click);
            // 
            // textBox1
            // 
            this.textBox1.Location = new System.Drawing.Point(12, 12);
            this.textBox1.Name = "textBox1";
            this.textBox1.Size = new System.Drawing.Size(178, 20);
            this.textBox1.TabIndex = 4;
            // 
            // FormChat
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(192)))), ((int)(((byte)(128)))));
            this.ClientSize = new System.Drawing.Size(485, 400);
            this.Controls.Add(this.textBox1);
            this.Controls.Add(this.buttonLogin);
            this.Controls.Add(this.buttonSend);
            this.Controls.Add(this.textBoxMessageToSend);
            this.Controls.Add(this.textBoxMessages);
            this.Name = "FormChat";
            this.Text = "Chat";
            this.FormClosing += new System.Windows.Forms.FormClosingEventHandler(this.FormChat_FormClosing);
            this.Load += new System.EventHandler(this.FormChat_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox textBoxMessages;
        private System.Windows.Forms.TextBox textBoxMessageToSend;
        private System.Windows.Forms.Button buttonSend;
        private System.Windows.Forms.Button buttonLogin;
        private System.Windows.Forms.TextBox textBox1;
    }
}

