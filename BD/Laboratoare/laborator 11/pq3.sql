SELECT outer_emp.employee_id, outer_emp.last_name
FROM Employees outer_emp
WHERE EXISTS(SELECT inner_emp.employee_id
            FROM Employees inner_emp
            WHERE inner_emp.last_name LIKE '%u%' 
              AND outer_emp.department_id=inner_emp.department_id);