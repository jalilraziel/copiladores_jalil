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
            dataGridView1.Columns.Add("Texto", "Texto");
            dataGridView1.Columns.Add("Tipo", "Tipo");
            dataGridView1.Columns.Add("Linea", "Linea");
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
            string[] copilationDetails = compilerDLLInstance.compileProgram(textsrc.Text);//copilador.copilerProgram(textsrc.Text);
            //int i = 0;
            //for (i = 0; copilationDetails[i] != "weamagicadeseparacion"; i++) { }
            //String[] NewArray = new String[i+2];
            //copilationDetails.CopyTo(NewArray, i);
            textoutput.Lines = copilationDetails;

            //for (i = i+2; copilationDetails[i] != null; i++)
            //{           
            //    string[] token = copilationDetails[i].Split(',');
            //    dataGridView1.Columns.Add("Texto", token[0]);
            //    dataGridView1.Columns.Add("Tipo", token[1]);
            //    dataGridView1.Columns.Add("Linea", token[2]);
            //}
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

    }

}