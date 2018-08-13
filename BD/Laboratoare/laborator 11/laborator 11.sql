/* CAPITOLUL 10 - Subinterogari */

select department_id, avg(salary) from employees group by department_id;
select first_name, salary from employees e where salary=(select max(salary) from employees e2); -- necorelata
select first_name, salary from employees e where salary=(select max(salary) from employees e2 where e2.department_id=e.department_id); --corelata pt ca e.dept_id


/* EXERCITII */
--1
SELECT last_name, hire_date
FROM Employees
WHERE department_id=(SELECT department_id
                      FROM Employees
                      WHERE last_name='Zlotkey')
      AND last_name<>'Zlotkey';

-- 2
SELECT employee_id, last_name, salary
FROM Employees
WHERE salary > (SELECT AVG(salary)
                FROM Employees)
ORDER BY salary DESC;

-- 3
SELECT outer_emp.employee_id, outer_emp.last_name
FROM Employees outer_emp
WHERE EXISTS(SELECT inner_emp.employee_id
            FROM Employees inner_emp
            WHERE inner_emp.last_name LIKE '%u%' 
              AND outer_emp.department_id=inner_emp.department_id);
              
-- 4
SELECT last_name, department_id, job_id
FROM Employees
WHERE department_id IN (SELECT department_id
                        FROM Departments
                        WHERE location_id=1700);

-- 5
SELECT last_name, salary
FROM Employees
WHERE manager_id=(SELECT employee_id
                  FROM Employees
                  WHERE last_name='King');
                  
-- 6
SELECT department_id, last_name, job_id
FROM Employees
WHERE department_id=(SELECT department_id
                      FROM Departments
                      WHERE department_name='Executive');
                      
-- 7
SELECT outer_emp.employee_id, outer_emp.last_name, outer_emp.salary
FROM Employees outer_emp
WHERE EXISTS(SELECT inner_emp.employee_id
            FROM Employees inner_emp
            WHERE inner_emp.last_name LIKE '%u%' 
              AND outer_emp.department_id=inner_emp.department_id)
      AND outer_emp.salary>(SELECT AVG(outer_emp.salary)
                            FROM Employees);
                            
-- 8
SELECT last_name, department_id, salary
FROM Employees
WHERE (department_id, salary) IN (SELECT department_id, salary
                                  FROM Employees
                                  WHERE commission_pct IS NOT NULL);
                              
-- 9
SELECT outer_e.last_name, outer_d.department_name, outer_e.salary
FROM Employees outer_e, Departments outer_d
WHERE (outer_e.salary, NVL(outer_e.commission_pct, -1)) IN (SELECT inner_e.salary, NVL(inner_e.commission_pct, -1)
                                        FROM Employees inner_e, Departments inner_d
                                        WHERE inner_e.department_id=inner_d.department_id
                                          AND inner_d.location_id=1700)
  AND outer_e.department_id=outer_d.department_id;
  -- NVL(...) pentru tuplele de tipul (salariu, NULL) <-> (salariu, NULL)
  -- NULL != NULL !!! NULL-urile nu pot fi comparate

-- 10
SELECT last_name, hire_date, salary
FROM Employees
WHERE (salary, NVL(commission_pct, -1)) IN (SELECT salary, NVL(commission_pct, -1)
                                    FROM Employees
                                    WHERE last_name='Kochhar')
  AND last_name<>'Kochhar';

-- 11
SELECT last_name, job_id, salary
FROM Employees
WHERE salary>ANY(SELECT salary
                  FROM Employees
                  WHERE job_id='SA_MAN')
ORDER BY salary DESC;

-- 12
SELECT e.employee_id, e.last_name, d.department_id
FROM Employees e, Departments d
WHERE d.location_id IN (SELECT location_id
                      FROM Locations
                      WHERE city LIKE 'T%')
  AND e.department_id=d.department_id;


-- 13
SELECT outer_e.last_name ENAME, outer_e.salary SALARY, outer_e.department_id DEPTNO, ROUND(inner_e.avgsal, 2) DEPT_AVG
FROM Employees outer_e, (SELECT department_id, AVG(salary) avgsal
                          FROM Employees
                          GROUP BY department_id) inner_e
WHERE outer_e.salary>inner_e.avgsal
  AND outer_e.department_id=inner_e.department_id;

-- 14
-- folosind operatorul NOT EXISTS
SELECT outer_e.last_name
FROM Employees outer_e
WHERE NOT EXISTS (SELECT 'X'
                  FROM Departments
                  WHERE NVL(manager_id, -1)=outer_e.employee_id);

-- folosind operatorul NOT IN
SELECT last_name
FROM Employees
WHERE employee_id NOT IN (SELECT NVL(manager_id, -1)
                          FROM Departments);


-- 15
SELECT outer_e.last_name
FROM Employees outer_e
WHERE outer_e.salary<(SELECT AVG(salary)
                      FROM Employees
                      WHERE department_id=outer_e.department_id);

-- 16
SELECT outer_e.last_name
FROM Employees outer_e
WHERE EXISTS (SELECT 'X'
              FROM Employees
              WHERE salary>outer_e.salary
                AND hire_date>outer_e.hire_date
                AND department_id=outer_e.department_id);

-- 17
SELECT outer_e.employee_id, outer_e.last_name, 
  (SELECT department_name 
    FROM Departments
    WHERE department_id=outer_e.department_id) DEPARTMENT
FROM Employees outer_e;

-- 18
WITH SUMMARY AS (SELECT 1/8 * SUM(salary) salTotal
                  FROM Employees)
  SELECT d.department_name, SUM(e.salary)
  FROM Employees e, Departments d
  WHERE e.department_id=d.department_id
  GROUP BY d.department_name
  HAVING SUM(e.salary)>(SELECT * FROM SUMMARY);

-- 19
-- da, sunt procesari ierarhice:
-- primul tabel -> parcurgere de sus in jos
-- al doilea tabel -> parcurgere de jos in sus

-- 20
SELECT last_name, salary, department_id
FROM Employees
WHERE last_name<>'Mourgos'
  AND department_id=(SELECT department_id
                      FROM Employees
                      WHERE last_name='Mourgos')
START WITH last_name='Mourgos'
CONNECT BY PRIOR employee_id=manager_id;

-- 21
SELECT last_name, salary, department_id
FROM Employees
WHERE last_name<>'Lorentz'
START WITH last_name='Lorentz'
CONNECT BY PRIOR manager_id=employee_id;

-- 22
SELECT LPAD(last_name, LENGTH(last_name) + (LEVEL * 2) - 2, '_') NAME, manager_id MGR, department_id DEPTNO
FROM Employees
START WITH last_name='Kochhar'
CONNECT BY PRIOR employee_id=manager_id;

-- 23
SELECT last_name, employee_id, manager_id
FROM Employees
WHERE job_id<>'IT_PROG'
START WITH manager_id IS NULL
CONNECT BY PRIOR employee_id=manager_id
  AND last_name<>'De Haan';
