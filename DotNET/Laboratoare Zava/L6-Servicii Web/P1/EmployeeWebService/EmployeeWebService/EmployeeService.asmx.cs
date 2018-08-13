using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Services;
using System.Xml;
using System.Xml.Serialization;

namespace EmployeeWebService
{
    public class Employee
    {
        public string name;
        public int age, noEmp;
        public List<Employee> empList;  // lista subordonatilor

        public void addSubordinate(Employee e)
        {
            empList.Add(e);
        }
    }

    /// <summary>
    /// Summary description for Service1
    /// </summary>
    [WebService(Namespace = "http://tempuri.org/")]
    [WebServiceBinding(ConformsTo = WsiProfiles.BasicProfile1_1)]
    [System.ComponentModel.ToolboxItem(false)]
    // To allow this Web Service to be called from script, using ASP.NET AJAX, uncomment the following line. 
    // [System.Web.Script.Services.ScriptService]
    public class EmployeeService : System.Web.Services.WebService
    {
   private static List<Employee> managerList = new List<Employee>();

        [WebMethod]
        public void AddManager(Employee m)
        {
            m.empList = new List<Employee > ();
            managerList.Add(m);
        }

        [WebMethod]
        public void AddEmployee(Employee m, Employee e)
        {
            foreach (Employee localManager in managerList)
            {
                if (localManager.name == m.name)    // am facut corelarea intre obiectele de tip Employee dupa nume
                {
                    localManager.addSubordinate(e);
                    break;
                }
            }
        }

        [WebMethod]
        [XmlInclude(typeof(Employee))]  // pentru a serializa obiectele de tip Employee
        public Employee GetManagerOf(Employee e)
        {
            foreach (Employee localManager in managerList)
            {
                foreach(Employee localEmployee in localManager.empList)
                {
                    if (e.name == localEmployee.name)    // am facut corelarea intre obiectele de tip Employee dupa nume
                    {
                        return localManager;
                    }
                }
            }
            return null;
        }

        [WebMethod]
        [XmlInclude(typeof(Employee))]  // pentru a serializa obiectele de tip Employee
        public Employee[] GetEmployeesOf(Employee manager)  // se pot transmite numai array-uri, nu si colectii generice
        {
            foreach (Employee localManager in managerList)
            {
                if (localManager.name == manager.name)
                {
                    return localManager.empList.ToArray();  // transform lista angajatilor in array
                }
            }
            return null;
        }
    }
}