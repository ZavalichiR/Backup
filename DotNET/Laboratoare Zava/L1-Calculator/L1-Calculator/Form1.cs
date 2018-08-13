using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace L1_Calculator
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }
        private void button1_Click(object sender, EventArgs e)
        {
            int x = Int32.Parse(textBox1.Text);
            int y = Int32.Parse(textBox2.Text);
            double rez = 0;
            bool ok = true;
            string error = "Eroare !";
            switch (comboBox1.Text)
            {
                case "-":
                    {
                        rez = x - y;
                        break;
                    }
                case "+":
                    {
                        rez = x + y;
                        break;
                    }
                case "*":
                    {
                        rez = x * y;
                        break;
                    }
                case "/":
                    {
                        if (y == 0)
                        {
                            ok = false;
                            break;
                        }
                        else
                            rez = (double)x / y;
                        break;
                    }

            }
            if (ok == true)
                label1.Text = rez.ToString("F1");
            else
                label1.Text = error;
        }

        private void button2_Click(object sender, EventArgs e)
        {
            int i = 0, k = 0, j = 0;
            bool gasit = false;
            string sir = textBox3.Text;
            sir += '\0';
            char[] post = new char[100];
            Stack<char> S = new Stack<char>();
            /*
            -------Algoritm Calcul forma poloneza-------
            1.Se va folosi o Stiva de OPERATORI( +,-,*,/,(,) )
	            si un sir de caractere: char post[100];

            2.Se parcurge sirul SIR (forma infixata data de la tastatura)
	            de la stanga la dreapta pana intalneste '\0'-se termina

            3.La intalnirea unui operand( 0 to 9) acesta este pus in sirul POST

            3.La intalnirea parantezei deschise '(' aceasta este pusa in stiva

            4.La intalnirea parantezei inchise ')' se extrage tot ce se afla in 
	            stiva( si este pus in sirul POST) pana la intalnirea parantezei
	            deschise ')', ')' se extrage dar nu se pune in sirul POST

            5.La intalnirea unui operator +,-,* sau /
	            se extrag din stiva toti operatorii de prioritate mai mare sau
	            egala si se transfera in sirul POST, pana se ajunge la '('
	            Operatorul curent se plaseaza in stiva

            6.La finalul sirului SIR se goleste stiva si se transfera in sirul 
	            POST

            7.Se pune '\0' in POST, post[k]='\0'
             
             ex:
             * a-b*(c+d) devine abcd+*-
             * (a-b)*c devine ab-c*
            */

            while (sir[i] != '\0')
            {
                int cifre = i;
                for (j = cifre; j <= sir.Count() - 1; ++j) //pune cifre
                {
                    int ii = j;
                    if ((sir[ii] >= '0') && (sir[ii] <= '9') || (sir[ii] == '.')) //(sir[i] >= 'a' && sir[i] <= 'z')
                    {
                        gasit = true;
                        if (sir[ii] != '.')
                        {
                            post[k] = sir[ii];
                            k++;
                        }
                        else
                        {
                            post[k] = sir[ii]; //pune punct
                            k++;
                            ii++;
                            post[k] = sir[ii]; // pune cifra de dupa punct
                            k++;
                            j++;
                        }
                        i = ii;
                    }
                    else
                    {
                        break;
                    }
                }
                if (gasit == true)
                {
                    post[k] = ' '; // pune spatiu dupa cifra
                    k++;
                    gasit = false;
                }

                if (sir[i] == '(')
                    S.Push(sir[i]);
                if (sir[i] == ')')
                {
                    while (S.Peek() != '(')
                    {
                        post[k] = S.Pop();
                        k++;
                        post[k] = ' '; //pune spatiu dupa semn
                        k++;
                    }
                    S.Pop();
                }
                if (sir[i] == '+' || sir[i] == '-')
                {
                    while ((S.Count != 0) && (S.Peek() != '(') && (sir[i] != 0))
                    {
                        post[k] = S.Pop();
                        k++;
                        post[k] = ' '; // pune spatiu dupa semn
                        k++;
                    }
                    S.Push(sir[i]);
                }
                if ((sir[i] == '*') || (sir[i] == '/'))
                {
                    while ((S.Count != 0) && (S.Peek() != '+') && (S.Peek() != '-') && (S.Peek() != '(') && (sir[i] != 0))
                    {
                        post[k] = S.Pop();
                        k++;
                        post[k] = ' '; // pune spatiu dupa semn
                        k++;
                    }
                    S.Push(sir[i]);
                }
                i++;
            }
            while (S.Count != 0)
            {
                post[k] = S.Pop();
                k++;
                post[k] = ' ';// pune spatiu dupa fiecare semn
                k++;
            }
            post[k] = '\0';

            // Forma postfixata POST;
            for (j = 0; j <= post.Count() - 1; j++)
            {
                label3.Text += post[j].ToString();
            }


            /*
            -------Algoritm Evaluare forma poloneza-------
            1.Se va folosi o stiva de OPERANZI(0 to 9)

            2.Se parcurge sirul (forma poloneza/forma postfixata) de la stanga
                la dreapta

            3.La intalnirea unui operand, acesta va fi pus in stiva

            4.La intalnirea unui operator, se vor extrage din stiva 2 operanzi
                si li se atribuie operatorul

            5.Rezultatul obtinut se va pune in stiva

            6.LA finalul sirului rezultatul final va fi pus in stiva

            7.Se extrage din stiva rezultatul final si se afiseaza
            */

            i = 0;
            Stack<double> S2 = new Stack<double>();
            double a, b;
            bool flag2 = true;
            bool precizie = false;
            int n = 0;

            while (post[i] != '\0')
            {

                if ((post[i] >= '0') && (post[i] <= '9') || (post[i] == '.'))
                {
                    if (post[i + 1] != '.')  //pentru un numar mare care are virgula ex: xxx.yyy
                    {
                        if (post[i + 1] >= '0' || post[i + 1] <= '9')
                        {
                            int poz = 0;
                            string nr = post[i].ToString();
                            string nr2 = "";
                            for (poz = 1; poz <= (sir.Count() - 1) - i; ++poz)
                            {
                                if ((post[i + poz] != ' ') && ((post[i + poz] >= '0') || (post[i + poz] <= '9')))
                                {
                                    if (post[i + poz] == '.')
                                    {
                                        nr2 = nr; //nr2 devine xxx si nr yyy
                                        nr = "";
                                        precizie = true;
                                        n = 0;
                                    }
                                    else
                                    {
                                        nr += post[i + poz].ToString(); //se calculeaza xxx sau yyy
                                        if (precizie)
                                            n++;
                                    }


                                }

                                else
                                    break;
                            }
                            nr = nr2 + nr; // nr este xxxyyy
                            double x = (double)Int32.Parse(nr) / (Math.Pow(10, (n))); // x este xxx.yyy
                            n = 0;
                            precizie = false;
                            S2.Push(x);
                            i = i + poz - 1;
                        }

                    }
                    else //pentru un numar de o cifra care are virgula ( nu cred ca mai este necesar ) Ex x.xxx
                    {
                        int poz = 0;
                        string nr = post[i].ToString();
                        for (poz = 1; poz <= (sir.Count() - 1) - i; ++poz)
                        {
                            if ((post[i + poz + 1] != ' ') && ((post[i + poz + 1] >= '0') || (post[i + poz + 1] <= '9')))
                                nr += post[i + poz + 1].ToString();
                            else
                                break;
                        }
                        int x = Int32.Parse(nr);
                        double r = (double)x / (Math.Pow(10, (poz - 1)));
                        S2.Push(r);
                        i = i + 1 + poz;
                    }
                }

                if (post[i] == '+')
                {
                    a = S2.Pop();
                    b = S2.Pop();
                    S2.Push(a + b);
                }
                if (post[i] == '-')
                {
                    a = S2.Pop();
                    b = S2.Pop();
                    S2.Push(b - a);
                }
                if (post[i] == '*')
                {
                    a = S2.Pop();
                    b = S2.Pop();
                    S2.Push(a * b);
                }
                if (post[i] == '/')
                {
                    a = S2.Pop();
                    b = S2.Pop();
                    if (a == 0)
                    {
                        flag2 = false;
                        a = 1;
                    }

                    S2.Push((double)b / a);
                }
                i++;
                if (flag2 == false)
                    break;
            }
            if (flag2 == true)
                label2.Text = S2.Pop().ToString();
            else
            {
                label2.Text = "Error !";
                label3.Text = "Error !";
            }
        }

    }
}
