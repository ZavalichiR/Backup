using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MathLibrary
{
    public class SimpleMath : MarshalByRefObject
    {
        public SimpleMath(string name)
        { 
            Console.WriteLine("SimpleMath ctor called({0})",name); 
        }
        public int Add(int n1, int n2)
        {
            Console.WriteLine("SimpleMath.Add({0}, {1})", n1, n2);
            return n1 + n2;
        }
        public int Subtract(int n1, int n2)
        {
            Console.WriteLine("SimpleMath.Subtract({0}, {1})", n1, n2);
            return n1 - n2;
        }
        public string[] Sort(string []v,int n)
        {
            Console.WriteLine("SimpleMath.Sort({0})", v);
            int ok = 0;
            string aux;
            do
            {
                ok = 0;
            for(int i = 0; i < n - 1;i++)
                {
                    if(String.Compare(v[i],v[i+1])>0)
                    {
                        ok = 1;
                        aux = v[i];
                        v[i] = v[i + 1];
                        v[i + 1] = aux;
                    }
                }
            } while (ok != 0);
     
            return v;
        }
        public int  Search(string []v, int n, string cauta)
        {
            int i, k = -1;
            for (i = 0; i < n; i++)
            {
                if (String.Compare(v[i], cauta) == 0)
                    k= i;
            }
            return k;
        }
        public string[] Delete(string[] numbers, string numToRemove)
        {/*
            int poz = Search(v, n, sters);
        for(int i=poz;i<n-1;i++)
            {
                v[i] = v[i + 1];
            }
    
            return v;
            */
            
            numbers = numbers.Where(val => val != numToRemove).ToArray();
            return numbers;
        }
    }
}
