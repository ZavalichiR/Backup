using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Excel
{
    public partial class DataGrid : Form
    {
        public DataGrid()
        {
            InitializeComponent();
        }

        private void xLSBindingNavigatorSaveItem_Click(object sender, EventArgs e)
        {


        }

        private void xLSBindingNavigatorSaveItem_Click_1(object sender, EventArgs e)
        {

        }

        private void eXLBindingNavigatorSaveItem_Click(object sender, EventArgs e)
        {
      

        }

        private void DataGrid_Load(object sender, EventArgs e)
        {
            // TODO: This line of code loads data into the 'excelDataSet1.Diseases' table. You can move, or remove it, as needed.
            this.diseasesTableAdapter.Fill(this.excelDataSet1.Diseases);
            // TODO: This line of code loads data into the 'excelDataSet1.Patients_Diseases' table. You can move, or remove it, as needed.
            this.patients_DiseasesTableAdapter.Fill(this.excelDataSet1.Patients_Diseases);
            // TODO: This line of code loads data into the 'excelDataSet1.Patients' table. You can move, or remove it, as needed.
            this.patientsTableAdapter.Fill(this.excelDataSet1.Patients);
            // TODO: This line of code loads data into the 'excelDataSet.EXL' table. You can move, or remove it, as needed.


        }

        private void patientsBindingNavigatorSaveItem_Click(object sender, EventArgs e)
        {
            this.Validate();
            this.patientsBindingSource.EndEdit();
            this.tableAdapterManager.UpdateAll(this.excelDataSet1);

        }
    }
}
