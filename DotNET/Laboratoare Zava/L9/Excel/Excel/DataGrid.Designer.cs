namespace Excel
{
    partial class DataGrid
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
            this.components = new System.ComponentModel.Container();
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(DataGrid));
            this.excelDataSet1 = new Excel.ExcelDataSet1();
            this.patientsBindingSource = new System.Windows.Forms.BindingSource(this.components);
            this.patientsTableAdapter = new Excel.ExcelDataSet1TableAdapters.PatientsTableAdapter();
            this.tableAdapterManager = new Excel.ExcelDataSet1TableAdapters.TableAdapterManager();
            this.patientsBindingNavigator = new System.Windows.Forms.BindingNavigator(this.components);
            this.patientsBindingNavigatorSaveItem = new System.Windows.Forms.ToolStripButton();
            this.patientsDataGridView = new System.Windows.Forms.DataGridView();
            this.dataGridViewTextBoxColumn1 = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.dataGridViewTextBoxColumn2 = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.dataGridViewTextBoxColumn3 = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.dataGridViewTextBoxColumn4 = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.dataGridViewTextBoxColumn5 = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.dataGridViewTextBoxColumn6 = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.dataGridViewTextBoxColumn7 = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.dataGridViewTextBoxColumn8 = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.dataGridViewTextBoxColumn9 = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.patients_DiseasesBindingSource = new System.Windows.Forms.BindingSource(this.components);
            this.patients_DiseasesTableAdapter = new Excel.ExcelDataSet1TableAdapters.Patients_DiseasesTableAdapter();
            this.patients_DiseasesDataGridView = new System.Windows.Forms.DataGridView();
            this.dataGridViewTextBoxColumn10 = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.dataGridViewTextBoxColumn11 = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.dataGridViewTextBoxColumn12 = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.diseasesBindingSource = new System.Windows.Forms.BindingSource(this.components);
            this.diseasesTableAdapter = new Excel.ExcelDataSet1TableAdapters.DiseasesTableAdapter();
            this.diseasesDataGridView = new System.Windows.Forms.DataGridView();
            this.dataGridViewTextBoxColumn13 = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.dataGridViewTextBoxColumn14 = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.dataGridViewTextBoxColumn15 = new System.Windows.Forms.DataGridViewTextBoxColumn();
            ((System.ComponentModel.ISupportInitialize)(this.excelDataSet1)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.patientsBindingSource)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.patientsBindingNavigator)).BeginInit();
            this.patientsBindingNavigator.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.patientsDataGridView)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.patients_DiseasesBindingSource)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.patients_DiseasesDataGridView)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.diseasesBindingSource)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.diseasesDataGridView)).BeginInit();
            this.SuspendLayout();
            // 
            // excelDataSet1
            // 
            this.excelDataSet1.DataSetName = "ExcelDataSet1";
            this.excelDataSet1.SchemaSerializationMode = System.Data.SchemaSerializationMode.IncludeSchema;
            // 
            // patientsBindingSource
            // 
            this.patientsBindingSource.DataMember = "Patients";
            this.patientsBindingSource.DataSource = this.excelDataSet1;
            // 
            // patientsTableAdapter
            // 
            this.patientsTableAdapter.ClearBeforeFill = true;
            // 
            // tableAdapterManager
            // 
            this.tableAdapterManager.BackupDataSetBeforeUpdate = false;
            this.tableAdapterManager.DiseasesTableAdapter = this.diseasesTableAdapter;
            this.tableAdapterManager.Patients_DiseasesTableAdapter = this.patients_DiseasesTableAdapter;
            this.tableAdapterManager.PatientsTableAdapter = this.patientsTableAdapter;
            this.tableAdapterManager.UpdateOrder = Excel.ExcelDataSet1TableAdapters.TableAdapterManager.UpdateOrderOption.InsertUpdateDelete;
            // 
            // patientsBindingNavigator
            // 
            this.patientsBindingNavigator.AddNewItem = null;
            this.patientsBindingNavigator.BindingSource = this.patientsBindingSource;
            this.patientsBindingNavigator.CountItem = null;
            this.patientsBindingNavigator.DeleteItem = null;
            this.patientsBindingNavigator.ImageScalingSize = new System.Drawing.Size(20, 20);
            this.patientsBindingNavigator.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.patientsBindingNavigatorSaveItem});
            this.patientsBindingNavigator.Location = new System.Drawing.Point(0, 0);
            this.patientsBindingNavigator.MoveFirstItem = null;
            this.patientsBindingNavigator.MoveLastItem = null;
            this.patientsBindingNavigator.MoveNextItem = null;
            this.patientsBindingNavigator.MovePreviousItem = null;
            this.patientsBindingNavigator.Name = "patientsBindingNavigator";
            this.patientsBindingNavigator.PositionItem = null;
            this.patientsBindingNavigator.Size = new System.Drawing.Size(963, 27);
            this.patientsBindingNavigator.TabIndex = 0;
            this.patientsBindingNavigator.Text = "bindingNavigator1";
            // 
            // patientsBindingNavigatorSaveItem
            // 
            this.patientsBindingNavigatorSaveItem.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.patientsBindingNavigatorSaveItem.Image = ((System.Drawing.Image)(resources.GetObject("patientsBindingNavigatorSaveItem.Image")));
            this.patientsBindingNavigatorSaveItem.Name = "patientsBindingNavigatorSaveItem";
            this.patientsBindingNavigatorSaveItem.Size = new System.Drawing.Size(24, 24);
            this.patientsBindingNavigatorSaveItem.Text = "Save Data";
            this.patientsBindingNavigatorSaveItem.Click += new System.EventHandler(this.patientsBindingNavigatorSaveItem_Click);
            // 
            // patientsDataGridView
            // 
            this.patientsDataGridView.AutoGenerateColumns = false;
            this.patientsDataGridView.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.patientsDataGridView.Columns.AddRange(new System.Windows.Forms.DataGridViewColumn[] {
            this.dataGridViewTextBoxColumn1,
            this.dataGridViewTextBoxColumn2,
            this.dataGridViewTextBoxColumn3,
            this.dataGridViewTextBoxColumn4,
            this.dataGridViewTextBoxColumn5,
            this.dataGridViewTextBoxColumn6,
            this.dataGridViewTextBoxColumn7,
            this.dataGridViewTextBoxColumn8,
            this.dataGridViewTextBoxColumn9});
            this.patientsDataGridView.DataSource = this.patientsBindingSource;
            this.patientsDataGridView.Location = new System.Drawing.Point(0, 32);
            this.patientsDataGridView.Name = "patientsDataGridView";
            this.patientsDataGridView.RowTemplate.Height = 24;
            this.patientsDataGridView.Size = new System.Drawing.Size(944, 213);
            this.patientsDataGridView.TabIndex = 1;
            // 
            // dataGridViewTextBoxColumn1
            // 
            this.dataGridViewTextBoxColumn1.DataPropertyName = "Id";
            this.dataGridViewTextBoxColumn1.HeaderText = "Id";
            this.dataGridViewTextBoxColumn1.Name = "dataGridViewTextBoxColumn1";
            this.dataGridViewTextBoxColumn1.ReadOnly = true;
            // 
            // dataGridViewTextBoxColumn2
            // 
            this.dataGridViewTextBoxColumn2.DataPropertyName = "FirstName";
            this.dataGridViewTextBoxColumn2.HeaderText = "FirstName";
            this.dataGridViewTextBoxColumn2.Name = "dataGridViewTextBoxColumn2";
            // 
            // dataGridViewTextBoxColumn3
            // 
            this.dataGridViewTextBoxColumn3.DataPropertyName = "LastName";
            this.dataGridViewTextBoxColumn3.HeaderText = "LastName";
            this.dataGridViewTextBoxColumn3.Name = "dataGridViewTextBoxColumn3";
            // 
            // dataGridViewTextBoxColumn4
            // 
            this.dataGridViewTextBoxColumn4.DataPropertyName = "Gender";
            this.dataGridViewTextBoxColumn4.HeaderText = "Gender";
            this.dataGridViewTextBoxColumn4.Name = "dataGridViewTextBoxColumn4";
            // 
            // dataGridViewTextBoxColumn5
            // 
            this.dataGridViewTextBoxColumn5.DataPropertyName = "Phone";
            this.dataGridViewTextBoxColumn5.HeaderText = "Phone";
            this.dataGridViewTextBoxColumn5.Name = "dataGridViewTextBoxColumn5";
            // 
            // dataGridViewTextBoxColumn6
            // 
            this.dataGridViewTextBoxColumn6.DataPropertyName = "Weight";
            this.dataGridViewTextBoxColumn6.HeaderText = "Weight";
            this.dataGridViewTextBoxColumn6.Name = "dataGridViewTextBoxColumn6";
            // 
            // dataGridViewTextBoxColumn7
            // 
            this.dataGridViewTextBoxColumn7.DataPropertyName = "Height";
            this.dataGridViewTextBoxColumn7.HeaderText = "Height";
            this.dataGridViewTextBoxColumn7.Name = "dataGridViewTextBoxColumn7";
            // 
            // dataGridViewTextBoxColumn8
            // 
            this.dataGridViewTextBoxColumn8.DataPropertyName = "Age";
            this.dataGridViewTextBoxColumn8.HeaderText = "Age";
            this.dataGridViewTextBoxColumn8.Name = "dataGridViewTextBoxColumn8";
            // 
            // dataGridViewTextBoxColumn9
            // 
            this.dataGridViewTextBoxColumn9.DataPropertyName = "Email";
            this.dataGridViewTextBoxColumn9.HeaderText = "Email";
            this.dataGridViewTextBoxColumn9.Name = "dataGridViewTextBoxColumn9";
            // 
            // patients_DiseasesBindingSource
            // 
            this.patients_DiseasesBindingSource.DataMember = "Patients_Diseases";
            this.patients_DiseasesBindingSource.DataSource = this.excelDataSet1;
            // 
            // patients_DiseasesTableAdapter
            // 
            this.patients_DiseasesTableAdapter.ClearBeforeFill = true;
            // 
            // patients_DiseasesDataGridView
            // 
            this.patients_DiseasesDataGridView.AutoGenerateColumns = false;
            this.patients_DiseasesDataGridView.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.patients_DiseasesDataGridView.Columns.AddRange(new System.Windows.Forms.DataGridViewColumn[] {
            this.dataGridViewTextBoxColumn10,
            this.dataGridViewTextBoxColumn11,
            this.dataGridViewTextBoxColumn12});
            this.patients_DiseasesDataGridView.DataSource = this.patients_DiseasesBindingSource;
            this.patients_DiseasesDataGridView.Location = new System.Drawing.Point(0, 298);
            this.patients_DiseasesDataGridView.Name = "patients_DiseasesDataGridView";
            this.patients_DiseasesDataGridView.RowTemplate.Height = 24;
            this.patients_DiseasesDataGridView.Size = new System.Drawing.Size(349, 221);
            this.patients_DiseasesDataGridView.TabIndex = 2;
            // 
            // dataGridViewTextBoxColumn10
            // 
            this.dataGridViewTextBoxColumn10.DataPropertyName = "Id";
            this.dataGridViewTextBoxColumn10.HeaderText = "Id";
            this.dataGridViewTextBoxColumn10.Name = "dataGridViewTextBoxColumn10";
            this.dataGridViewTextBoxColumn10.ReadOnly = true;
            // 
            // dataGridViewTextBoxColumn11
            // 
            this.dataGridViewTextBoxColumn11.DataPropertyName = "PId_fk";
            this.dataGridViewTextBoxColumn11.HeaderText = "PId_fk";
            this.dataGridViewTextBoxColumn11.Name = "dataGridViewTextBoxColumn11";
            // 
            // dataGridViewTextBoxColumn12
            // 
            this.dataGridViewTextBoxColumn12.DataPropertyName = "DId_fk";
            this.dataGridViewTextBoxColumn12.HeaderText = "DId_fk";
            this.dataGridViewTextBoxColumn12.Name = "dataGridViewTextBoxColumn12";
            // 
            // diseasesBindingSource
            // 
            this.diseasesBindingSource.DataMember = "Diseases";
            this.diseasesBindingSource.DataSource = this.excelDataSet1;
            // 
            // diseasesTableAdapter
            // 
            this.diseasesTableAdapter.ClearBeforeFill = true;
            // 
            // diseasesDataGridView
            // 
            this.diseasesDataGridView.AutoGenerateColumns = false;
            this.diseasesDataGridView.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.diseasesDataGridView.Columns.AddRange(new System.Windows.Forms.DataGridViewColumn[] {
            this.dataGridViewTextBoxColumn13,
            this.dataGridViewTextBoxColumn14,
            this.dataGridViewTextBoxColumn15});
            this.diseasesDataGridView.DataSource = this.diseasesBindingSource;
            this.diseasesDataGridView.Location = new System.Drawing.Point(608, 298);
            this.diseasesDataGridView.Name = "diseasesDataGridView";
            this.diseasesDataGridView.RowTemplate.Height = 24;
            this.diseasesDataGridView.Size = new System.Drawing.Size(346, 234);
            this.diseasesDataGridView.TabIndex = 3;
            // 
            // dataGridViewTextBoxColumn13
            // 
            this.dataGridViewTextBoxColumn13.DataPropertyName = "Id";
            this.dataGridViewTextBoxColumn13.HeaderText = "Id";
            this.dataGridViewTextBoxColumn13.Name = "dataGridViewTextBoxColumn13";
            this.dataGridViewTextBoxColumn13.ReadOnly = true;
            // 
            // dataGridViewTextBoxColumn14
            // 
            this.dataGridViewTextBoxColumn14.DataPropertyName = "Disease";
            this.dataGridViewTextBoxColumn14.HeaderText = "Disease";
            this.dataGridViewTextBoxColumn14.Name = "dataGridViewTextBoxColumn14";
            // 
            // dataGridViewTextBoxColumn15
            // 
            this.dataGridViewTextBoxColumn15.DataPropertyName = "Conclusion";
            this.dataGridViewTextBoxColumn15.HeaderText = "Conclusion";
            this.dataGridViewTextBoxColumn15.Name = "dataGridViewTextBoxColumn15";
            // 
            // DataGrid
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(963, 578);
            this.Controls.Add(this.diseasesDataGridView);
            this.Controls.Add(this.patients_DiseasesDataGridView);
            this.Controls.Add(this.patientsDataGridView);
            this.Controls.Add(this.patientsBindingNavigator);
            this.Name = "DataGrid";
            this.Text = "DataGrid";
            this.Load += new System.EventHandler(this.DataGrid_Load);
            ((System.ComponentModel.ISupportInitialize)(this.excelDataSet1)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.patientsBindingSource)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.patientsBindingNavigator)).EndInit();
            this.patientsBindingNavigator.ResumeLayout(false);
            this.patientsBindingNavigator.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.patientsDataGridView)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.patients_DiseasesBindingSource)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.patients_DiseasesDataGridView)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.diseasesBindingSource)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.diseasesDataGridView)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private ExcelDataSet1 excelDataSet1;
        private System.Windows.Forms.BindingSource patientsBindingSource;
        private ExcelDataSet1TableAdapters.PatientsTableAdapter patientsTableAdapter;
        private ExcelDataSet1TableAdapters.TableAdapterManager tableAdapterManager;
        private System.Windows.Forms.BindingNavigator patientsBindingNavigator;
        private System.Windows.Forms.ToolStripButton patientsBindingNavigatorSaveItem;
        private ExcelDataSet1TableAdapters.Patients_DiseasesTableAdapter patients_DiseasesTableAdapter;
        private System.Windows.Forms.DataGridView patientsDataGridView;
        private System.Windows.Forms.DataGridViewTextBoxColumn dataGridViewTextBoxColumn1;
        private System.Windows.Forms.DataGridViewTextBoxColumn dataGridViewTextBoxColumn2;
        private System.Windows.Forms.DataGridViewTextBoxColumn dataGridViewTextBoxColumn3;
        private System.Windows.Forms.DataGridViewTextBoxColumn dataGridViewTextBoxColumn4;
        private System.Windows.Forms.DataGridViewTextBoxColumn dataGridViewTextBoxColumn5;
        private System.Windows.Forms.DataGridViewTextBoxColumn dataGridViewTextBoxColumn6;
        private System.Windows.Forms.DataGridViewTextBoxColumn dataGridViewTextBoxColumn7;
        private System.Windows.Forms.DataGridViewTextBoxColumn dataGridViewTextBoxColumn8;
        private System.Windows.Forms.DataGridViewTextBoxColumn dataGridViewTextBoxColumn9;
        private System.Windows.Forms.BindingSource patients_DiseasesBindingSource;
        private ExcelDataSet1TableAdapters.DiseasesTableAdapter diseasesTableAdapter;
        private System.Windows.Forms.DataGridView patients_DiseasesDataGridView;
        private System.Windows.Forms.DataGridViewTextBoxColumn dataGridViewTextBoxColumn10;
        private System.Windows.Forms.DataGridViewTextBoxColumn dataGridViewTextBoxColumn11;
        private System.Windows.Forms.DataGridViewTextBoxColumn dataGridViewTextBoxColumn12;
        private System.Windows.Forms.BindingSource diseasesBindingSource;
        private System.Windows.Forms.DataGridView diseasesDataGridView;
        private System.Windows.Forms.DataGridViewTextBoxColumn dataGridViewTextBoxColumn13;
        private System.Windows.Forms.DataGridViewTextBoxColumn dataGridViewTextBoxColumn14;
        private System.Windows.Forms.DataGridViewTextBoxColumn dataGridViewTextBoxColumn15;
    }
}