namespace ClientEditorNamespace
{
    partial class ClientEditor
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
            this.btnConnect = new System.Windows.Forms.Button();
            this.tbToken = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.tbLog = new System.Windows.Forms.RichTextBox();
            this.tbContent = new System.Windows.Forms.RichTextBox();
            this.groupBox1.SuspendLayout();
            this.SuspendLayout();
            // 
            // btnConnect
            // 
            this.btnConnect.Enabled = false;
            this.btnConnect.Location = new System.Drawing.Point(507, 11);
            this.btnConnect.Name = "btnConnect";
            this.btnConnect.Size = new System.Drawing.Size(141, 23);
            this.btnConnect.TabIndex = 1;
            this.btnConnect.Text = "Conectare Server";
            this.btnConnect.UseVisualStyleBackColor = true;
            this.btnConnect.Click += new System.EventHandler(this.btnConnect_Click);
            // 
            // tbToken
            // 
            this.tbToken.Location = new System.Drawing.Point(71, 12);
            this.tbToken.Name = "tbToken";
            this.tbToken.Size = new System.Drawing.Size(430, 20);
            this.tbToken.TabIndex = 2;
            this.tbToken.TextChanged += new System.EventHandler(this.tbToken_TextChanged);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label1.Location = new System.Drawing.Point(12, 12);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(53, 20);
            this.label1.TabIndex = 3;
            this.label1.Text = "Token";
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.tbLog);
            this.groupBox1.Location = new System.Drawing.Point(11, 429);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(637, 142);
            this.groupBox1.TabIndex = 4;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "Logs";
            // 
            // tbLog
            // 
            this.tbLog.Location = new System.Drawing.Point(7, 20);
            this.tbLog.Name = "tbLog";
            this.tbLog.ReadOnly = true;
            this.tbLog.Size = new System.Drawing.Size(624, 116);
            this.tbLog.TabIndex = 0;
            this.tbLog.Text = "";
            this.tbLog.TextChanged += new System.EventHandler(this.tbLog_TextChanged);
            // 
            // tbContent
            // 
            this.tbContent.Enabled = false;
            this.tbContent.Location = new System.Drawing.Point(12, 41);
            this.tbContent.Name = "tbContent";
            this.tbContent.Size = new System.Drawing.Size(637, 382);
            this.tbContent.TabIndex = 0;
            this.tbContent.Text = "Introduceti un token si apasati pe Conectare Server";
            this.tbContent.SelectionChanged += new System.EventHandler(this.tbContent_SelectionChanged);
            this.tbContent.KeyPress += new System.Windows.Forms.KeyPressEventHandler(this.tbContent_KeyPress);
            this.tbContent.KeyUp += new System.Windows.Forms.KeyEventHandler(this.tbContent_KeyUp);
            // 
            // ClientEditor
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(661, 583);
            this.Controls.Add(this.groupBox1);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.tbToken);
            this.Controls.Add(this.btnConnect);
            this.Controls.Add(this.tbContent);
            this.Name = "ClientEditor";
            this.ShowIcon = false;
            this.Text = "Tudor DOCS";
            this.groupBox1.ResumeLayout(false);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion
        private System.Windows.Forms.Button btnConnect;
        private System.Windows.Forms.TextBox tbToken;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.RichTextBox tbLog;
        private System.Windows.Forms.RichTextBox tbContent;
    }
}

