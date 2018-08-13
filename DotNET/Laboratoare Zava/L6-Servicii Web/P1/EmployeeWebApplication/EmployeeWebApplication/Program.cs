using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

using EmployeeWebApplication.EmployeeServiceReference;


namespace EmployeeWebApplication
{
    class Program
    {
        public static EmployeeService myEmpService = new EmployeeService();



        static void Main(string[] args)
        {

            // Adauga un manager
            Console.Write("Manager: ");
            string nume = Console.ReadLine();
            Console.Write("Varsta: ");
            int varsta = Int32.Parse(Console.ReadLine());
            Employee manager = new Employee();
            manager.age = varsta;
            manager.name = nume;
            myEmpService.AddManager(manager);

            // Adauga 2 angajati la acest manager
            Console.WriteLine("\nSubordonatii managerului");
            Console.Write("\n\t\tNume Angajat: ");
            nume = Console.ReadLine();
            Console.Write("\n\t\tVarsta Angajat: ");
            varsta = Int32.Parse(Console.ReadLine());
            Employee emp1 = new Employee();
            emp1.name = nume;
            emp1.age = varsta;
            myEmpService.AddEmployee(manager, emp1);

            Console.Write("\n\t\tNume Angajat: ");
            nume = Console.ReadLine();
            Console.Write("\n\t\tVarsta Angajat: ");
            varsta = Int32.Parse(Console.ReadLine());
            Employee emp2 = new Employee();
            emp2.name = nume;
            emp2.age = varsta;
            myEmpService.AddEmployee(manager, emp2);

            // Obtine lista de angajati pentru un acest manager
            Console.WriteLine("\n\tAngajatii managerului: " + manager.name + ":");
            Employee[] empList = myEmpService.GetEmployeesOf(manager);
            int i;
            for (i = 0; i < empList.Length; i++)
            {
                if (empList[i] == null)
                {
                    break;
                }
                Console.WriteLine("\nAngajatul " + (i + 1) + ":");
                Console.WriteLine("Nume: " + empList[i].name);
                Console.WriteLine("Varsta: " + empList[i].age);
            }

            // Afiseaza managerii celor 2 angajati
            Console.WriteLine("\n\tManagerii celor 2 angajati: \n");
            for (i = 0; i < empList.Length; i++)
            {
                Console.WriteLine("Managerul pentru " + empList[i].name + ":");
                Employee retM = myEmpService.GetManagerOf(empList[i]);
                Console.WriteLine("Nume: " + retM.name);
                Console.WriteLine("Varsta: " + retM.age);
            }
            Console.WriteLine("\nEnter...");
            Console.Read();

        }
    }
}
