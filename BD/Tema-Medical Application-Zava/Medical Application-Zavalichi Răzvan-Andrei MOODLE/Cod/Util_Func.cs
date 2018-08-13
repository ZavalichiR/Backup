using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MedicalDB
{
    public class Util_Func
    {
        public static float IMC;
        public static float w;
        public static float h;
        public static string result;
        public static string conclusion;
        public Util_Func(float weight, float height)
        {
            w = weight;
            h = height;
        }

        public static float IMC_Calculator(float w, float h)
        {
            IMC = (w*10000) / (h * h);
            return IMC;
        }

        public static string Result_IMC(float IMC)
        {
            if (IMC < 18.50)
            {
                result = "Subponderal";
            }
            if (IMC > 18.49 && IMC < 25)
            {
                result = "Normoponderal";
            }
            if (IMC > 24.9 && IMC < 30)
            {
                result = "Supraponderal";
            }
            if (IMC > 29.9 && IMC < 35)
            {
                result = "Obezitate moderata(grad I)";
            }
            if (IMC > 34.9 && IMC < 40)
            {
                result = "Obezitate moderata(grad II)";
            }
            if (IMC > 39.9 && IMC < 50)
            {
                result = "Obezitate moderata(grad III)";
            }
            if (IMC > 50)
            {
                result = "Superobezitate";
            }
            return result;
        }

        public static string Conclusion_Result(string result)
        {
            if (result.Equals("Subponderal"))
            {
                conclusion = "Concluzie...";
            }
            else if (result.Equals("Normoponderal"))
            {
                conclusion = "Concluzie...";
            }
            else if (result.Equals("Supraponderal"))
            {
                conclusion = "Concluzie...";
            }
            else if (result.Equals("Obezitate moderata(grad I)"))
            {
                conclusion = "Concluzie...";
            }
            else if (result.Equals("Obezitate moderata(grad II)"))
            {
                conclusion = "Concluzie...";
            }
            else if (result.Equals("Obezitate moderata(grad III)"))
            {
                conclusion = "Concluzie...";
            }
            else if (result.Equals("Superobezitate"))
            {
                conclusion = "Concluzie...";
            }
            return conclusion;
        }

    }
}
