using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.IO;
using System.Threading;

namespace WindowsFormsApp11
{
    public partial class Form1 : Form
    {
        int lo = 0;
        string textt = " ";
        public void fout(string str, string text)
        {
            try
            {
                StreamWriter sw = new StreamWriter(@str);
                sw.WriteLine(text);
                sw.Close();
            }
            catch (Exception e)
            {
                Console.WriteLine("Exception: " + e.Message);
            }
            finally
            {
                Console.WriteLine("Executing finally block.");
            }
        }

        public void generation()
        {
            listBox1.Items.Clear();
            listBox1.Items.Add("№ значение массива");
            Random rand = new Random();
            int c = 1000, k = rand.Next() % c;
            int[] arr = new int[c];
            string text = " ", temp;
            lo = c;
            for (int i = 0; i < c; i++)
            {
                arr[i] = k + (rand.Next() % c);// заполняем случайными числами ячейки
                temp = Convert.ToString(i);
                if (i < 10)
                    temp += " ";
                else
                    temp += " ";
                listBox1.Items.Add(temp + Convert.ToString(arr[i]));
                text += Convert.ToString(arr[i]) + " ";
                k = arr[i];
            }
            fout("Сортировка.txt", text);
        }

        public void add()
        {
            if (lo < 100)
            {
                string temp;
                temp = Convert.ToString(lo) + " ";
                textt += Convert.ToString(textBox2.Text) + " ";
                lo++;
                listBox1.Items.Add(temp + Convert.ToString(textBox2.Text));
            }
            else
                label3.Text = "Достигнут максимум элементов";
        }

        public void sort1()
        {
            string text = "", num = "", result = "";
            StreamReader f = new StreamReader("Сортировка.txt");
            while (!f.EndOfStream)
            {
                text = f.ReadLine();
            }
            f.Close();
            int j = 1, flag = 0;
            for (int i = 0; i < lo; i++)
            {
                num = "";
                while (text[j] != ' ')
                {
                    num += text[j];
                    j++;
                }
                j++;
                if (num == textBox1.Text)
                {
                    result += "Ключ " + textBox1.Text + " находится в ячейке " + i + "\n";
                    flag = 1;
                }
            }
            if (flag == 0)
                result = "Мы не нашли ключ " + textBox1.Text + " в массиве";

            label3.Text = result;
            StreamWriter sw = new StreamWriter(@"Результат.txt");
            sw.WriteLine(result);
            sw.Close();
        }

        public void sort2()
        {
            string text = "", num = "", result = "";
            StreamReader f = new StreamReader("Сортировка.txt");
            while (!f.EndOfStream)
            {
                text = f.ReadLine();
            }
            f.Close();
            int j = 1;
            int[] arr = new int[lo];
            for (int i = 0; i < lo; i++)
            {
                num = "";
                while (text[j] != ' ')
                {
                    num += text[j];
                    j++;
                }
                j++;
                arr[i] = Convert.ToInt32(num);
            }
            int tmp = 0, lenD = lo;
            for (int i = 0; i < lenD; i++)
            {
                for (int y = (lenD - 1); y >= (i + 1); y--)
                {
                    if (arr[y] < arr[y - 1])
                    {
                        tmp = arr[y];
                        arr[y] = arr[y - 1];
                        arr[y - 1] = tmp;
                    }
                }
            }
            listBox1.Items.Clear();
            listBox1.Items.Add("№ значение массива");
                for (int i = 0; i < lo; i++)
                {
                    listBox1.Items.Add(i + " " + arr[i]);
                }
            if (Convert.ToInt32(textBox1.Text) < arr[0])
            {
                result = "Мы не нашли ключ " + textBox1.Text + " в массиве";
            }
            else
            {
                int l = 0, r = lo, mid;
                while (l < r)
                {
                    mid = (l + r) / 2;
                    if (arr[mid] > Convert.ToInt32(textBox1.Text))
                        r = mid;
                    else l = mid + 1;
                }
                r--;

                if (arr[r] == Convert.ToInt32(textBox1.Text))
                {
                    result += "Ключ " + textBox1.Text + " находится в ячейке " + r + "\n";
                }
                else
                {
                    result = "Мы не нашли ключ " + textBox1.Text + " в массиве";
                }
            }
               label3.Text = result;
            StreamWriter sw = new StreamWriter(@"Результат.txt");
           sw.WriteLine(result);
           sw.Close();
        }
        public Form1()
        {
            InitializeComponent();
            listBox1.Items.Add("№ значение массива");
        }

        private void button1_Click(object sender, EventArgs e)
        {
            sort1();
        }

        private void button2_Click(object sender, EventArgs e)
        {

            sort2();
        }

        private void button3_Click(object sender, EventArgs e)
        {
            generation();
        }

        private void button4_Click(object sender, EventArgs e)
        {
            add();
            textBox2.Text = "";
        }

        private void button5_Click(object sender, EventArgs e)
        {
            listBox1.Items.Clear();
            listBox1.Items.Add("№ значение массива");
            lo = 0;
            StreamWriter sw = new StreamWriter("Сортировка.txt", false);
            sw.Close();
            textt = " ";
        }

        private void button6_Click(object sender, EventArgs e)
        {
            StreamWriter sw = new StreamWriter("Сортировка.txt", true);
            sw.WriteLine(textt);
            sw.Close();
        }
    }
}
