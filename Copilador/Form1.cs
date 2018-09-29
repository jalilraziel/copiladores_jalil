using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.IO;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Reflection;
using System.Resources;
using System.Diagnostics;
using System.Management;

namespace Copilador
{
    public partial class Form1 : Form
    {
        string file;
        dynamic compilerDLLInstance;//CopilerCore.Manager copilador;
        public Form1()
        {
            InitializeComponent();
            //copilador = new CopilerCore.Manager();
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }

        private void Form1_Load(object sender, EventArgs e)
        {
            string dllFullPath = "";
            dllFullPath= DllPath();
            var DLL = Assembly.LoadFile(dllFullPath); 
            var DLLType = DLL.GetType("CopilerCore.Manager");
            compilerDLLInstance = Activator.CreateInstance(DLLType);
            dataGridView1.ColumnCount = 3;
            dataGridView1.Columns[0].Name ="Texto";
            dataGridView1.Columns[1].Name ="Tipo";
            dataGridView1.Columns[2].Name ="Linea";
        }

        private void newToolStripMenuItem_Click(object sender, EventArgs e)
        {

            if (textsrc.Text != "" & file != "")
                {
                if (MessageBox.Show("¿Desea guardar el archivo actual?", "Copilador JR", MessageBoxButtons.YesNo) == DialogResult.Yes)
                {
                        Guardarcomo();
                }

            }
            textoutput.Clear();
            textsrc.Clear();

        }

        private void copiladorToolStripMenuItem_Click(object sender, EventArgs e)
        {
        }

        private void copilarToolStripMenuItem_Click(object sender, EventArgs e)
        {
            textoutput.Clear();
            dataGridView1.Rows.Clear();
            string[] copilationDetails = compilerDLLInstance.compileProgram(textsrc.Text);//copilador.copilerProgram(textsrc.Text);
            int j = 0;
            for (j = 0; copilationDetails[j] != "wea magica de separion"; j++){}
                int i = copilationDetails.Length - j;
                String[] NewArray = new String[j];
                String[] NewTokens = new String[i];
            for (int x = 0; x < copilationDetails.Length; x++)
            {
                if (x < NewArray.Length) {
                    NewArray[x] = copilationDetails[x];
                    } 
                    else NewTokens[x-j] = copilationDetails[x];

            }
            textoutput.Lines = NewArray;
            for (int a = 1; NewTokens[a] != null; a++)
            {
                int b = dataGridView1.Rows.Add();
                String[] token = NewTokens[a].Split('@');
                dataGridView1.Rows[b].Cells[0].Value = token[0];
                dataGridView1.Rows[b].Cells[1].Value = token[1];
                dataGridView1.Rows[b].Cells[2].Value = token[2];
            }
            //textoutput.Lines = copilationDetails;
        }

        private void opeToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (textsrc.Text != "" && file != "")
            {
                if (MessageBox.Show("¿Desea guardar el archivo actual?", "Copilador JR", MessageBoxButtons.YesNo) == DialogResult.Yes)
                {
                    if(file != "")
                    {
                        
                    }
                    Guardarcomo();
                }

            }
            textoutput.Clear();
            textsrc.Clear();
            OpenFileDialog opendocument = new OpenFileDialog();
            opendocument.Filter = "txt files (*.txt)|*.txt|All files (*.*)|*.*";
            opendocument.FilterIndex = 1;
            if (opendocument.ShowDialog() == DialogResult.OK)
            {
                textsrc.Text = File.ReadAllText(opendocument.FileName);
                file = Path.GetFullPath(opendocument.FileName);
            }
        }

        private void saveToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (file != "")
            {
                File.WriteAllText(file, textsrc.Text);
            }
            else
            {
                Guardarcomo();
            }
        }

        private void exitToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }

        private void saveAsToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Guardarcomo();
        }

        void Guardarcomo()
        {
            SaveFileDialog savedocument = new SaveFileDialog();
            savedocument.Filter = "txt files (*.txt)|*.txt|All files (*.*)|*.*";
            savedocument.FilterIndex = 1;
            if (savedocument.ShowDialog() == DialogResult.OK)
            {
                file = Path.GetFullPath(savedocument.FileName);
                File.WriteAllText(file, textsrc.Text);
            }
        }

        private string DllPath()
        {
            string direc = "";
            var currentProcess = Process.GetCurrentProcess();
            direc = Environment.CurrentDirectory;
            direc  = direc.Substring(0, direc.Length-24);
            if (System.Environment.Is64BitProcess)
            {
                if (IfDebuggable())
                {
                    direc = direc + "\\DLL\\Binaries\\x64\\Debug\\CopilerCore.dll";
                }
                else
                {
                    direc = direc + "\\DLL\\Binaries\\x64\\Release\\CopilerCore.dll";
                }
            }
            else
            {
                if (IfDebuggable())
                {
                    direc = direc + "\\DLL\\Binaries\\x86\\Debug\\CopilerCore.dll";
                }
                else
                {             
                    direc = direc + "\\DLL\\Binaries\\x86\\Release\\CopilerCore.dll";
                }
            }
            return direc;
        }

        bool IfDebuggable()
        {
            bool es = false;
            object[] attribs = Assembly.GetExecutingAssembly().GetCustomAttributes(typeof(DebuggableAttribute), true);
            if ((attribs != null) && (attribs.Length == 1))
            {
                DebuggableAttribute attribute = attribs[0] as DebuggableAttribute;

                if (attribute.IsJITOptimizerDisabled && attribute.IsJITTrackingEnabled)
                {
                    es = true;
                }
            }
            return es;
        }

        private void menuStrip1_ItemClicked(object sender, ToolStripItemClickedEventArgs e)
        {

        }
    }

}