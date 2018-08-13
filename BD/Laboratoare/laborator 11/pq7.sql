SELECT outer_emp.employee_id, outer_emp.last_name, outer_emp.salary
FROM Employees outer_emp
WHERE EXISTS(SELECT inner_emp.employee_id
            FROM Employees inner_emp
            WHERE inner_emp.last_name LIKE '%u%' 
              AND outer_emp.department_id=inner_emp.department_id)
      AND outer_emp.salary>(SELECT AVG(outer_emp.salary)
                            FROM Employees);