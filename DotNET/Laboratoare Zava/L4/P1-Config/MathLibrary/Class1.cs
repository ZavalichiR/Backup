﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MathLibrary
{
    public class SimpleMath : MarshalByRefObject
    {
        public SimpleMath()
        {
            Console.WriteLine("SimpleMath Actor called");
        }
        public int Add(int n1, int n2)
        {
            Console.WriteLine("SimpleMath.Add({0}, {1})", n1, n2);
            return n1 + n2;
        }
        public int Subtract(int n1, int n2)
        {
            Console.WriteLine("SimpleMath.Subtract({0}, {1})", n1, n2);
            return n1-n2;
        }
    }
}
