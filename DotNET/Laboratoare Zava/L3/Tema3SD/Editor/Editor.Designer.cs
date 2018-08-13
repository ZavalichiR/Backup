namespace Editor
{
    partial class Editor
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
            this.textArea = new System.Windows.Forms.RichTextBox();
            this.SuspendLayout();
            // 
            // textArea
            // 
            this.textArea.Location = new System.Drawing.Point(13, 13);
            this.textArea.Margin = new System.Windows.Forms.Padding(4);
            this.textArea.Name = "textArea";
            this.textArea.Size = new System.Drawing.Size(618, 607);
            this.textArea.TabIndex = 0;
            this.textArea.Text = "";
            this.textArea.TextChanged += new System.EventHandler(this.textArea_TextChanged);
            this.textArea.KeyUp += new System.Windows.Forms.KeyEventHandler(this.OnKeyPress);
            // 
            // Editor
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(644, 633);
            this.Controls.Add(this.textArea);
            this.Margin = new System.Windows.Forms.Padding(4);
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "Editor";
            this.ShowIcon = false;
            this.Text = "Editor colaborativ";
            this.FormClosing += new System.Windows.Forms.FormClosingEventHandler(this.OnFormClose);
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.RichTextBox textArea;
    }
}

