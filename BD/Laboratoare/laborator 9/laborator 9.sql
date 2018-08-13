/* CAPITOLUL 8 - Afisarea datelor din tabele multiple */

--
select first_name from employees where department_id is null;
select employee_id, first_name, d.department_id, d.department_name from employees e LEFT OUTER JOIN departments d on e.department_id=d.department_id;
--LEF OUTER--null stanga
--RIGH OUTER --null dreapta
--FULL OUTER--null ambele
--
select employee_id,first_name, d.department_id, d.department_name from employees e JOIN departments d on e.department_id=d.department_id;
select employee_id,first_name, department_id, department_name from employees NATURAL JOIN departments; --verifica singur care coloane sa fie egale
select e1.employee_id,e1.first_name,e2.employee_id as "Manager ID",e2.first_name as "Manager Name"  from employees e1 JOIN employees e2 on e1.manager_id=e2.employee_id;

-- produs cartezian
SELECT last_name, department_name
FROM employees, departments;

/* EXERCITII */
-- 1
-- sintaxa SQL 1992
SELECT last_name, e.department_id, department_name
FROM employees e, departments d
WHERE e.department_id=d.department_id;

-- sintaxa SQL 1999
-- folosind NATURAL JOIN -> afiseaza mai putine inregistrari, pentru ca exista mai mult de o coloana comuna!!!
-- => NATURAL JOIN-ul va fi facut pe toate coloanele comune, deci conditia va restrictiona mai mult inregistrarile
SELECT last_name, department_id, department_name
FROM employees NATURAL JOIN departments;

-- folosind clauza USING
SELECT e.last_name, department_id, d.department_name
FROM employees e JOIN departments d
USING (department_id);

-- folosind clauza ON
SELECT e.last_name, e.department_id, d.department_name
FROM employees e JOIN departments d
ON (e.department_id=d.department_id);


-- 2
-- sintaxa SQL 1992
SELECT DISTINCT(e.job_id), d.department_name, DECODE(d.department_id, 90, d.location_id, NULL) location_id
FROM employees e, departments d
WHERE e.department_id=d.department_id AND e.department_id=10;

-- sintaxa SQL 1999
-- folosind clauza USING
SELECT DISTINCT(e.job_id), d.department_name, DECODE(department_id, 90, d.location_id, NULL) location_id
FROM employees e JOIN departments d
USING (department_id)
WHERE department_id=20;

-- folosind clauza ON
SELECT DISTINCT(e.job_id), d.department_name, DECODE(department_id, 90, d.location_id, NULL) location_id
FROM employees e JOIN departments d
USING (department_id)
WHERE department_id=20;


-- 3
-- sintaxa SQL 1992
SELECT e.last_name, d.department_name, l.location_id, l.city
FROM employees e, departments d, locations l
WHERE e.department_id=d.department_id AND d.location_id=l.location_id AND e.commission_pct IS NOT NULL;

-- sintaxa SQL 1999
-- folosind clauza USING
SELECT e.last_name, d.department_name, location_id, l.city
FROM employees e JOIN departments d USING (department_id) 
    JOIN locations l USING (location_id)
WHERE e.commission_pct IS NOT NULL;

-- folosind clauza ON
SELECT e.last_name, d.department_name, l.location_id, l.city
FROM employees e JOIN departments d ON (e.department_id=d.department_id) 
    JOIN locations l ON (d.location_id=l.location_id)
WHERE e.commission_pct IS NOT NULL;


-- 4 (primul 4)
-- sintaxa SQL 1992
SELECT last_name, department_name
FROM employees e, departments d
WHERE e.department_id=d.department_id 
  AND last_name LIKE '%a%';

-- sintaxa SQL 1999
-- folosind clauza USING
SELECT e.last_name, d.department_name
FROM employees e JOIN departments d
USING (department_id)
WHERE last_name LIKE '%a%';

-- folosind clauza ON
SELECT e.last_name, e.department_id, d.department_name
FROM employees e JOIN departments d
ON (e.department_id=d.department_id)
WHERE last_name LIKE '%a%';


-- 4 (al doilea 4)
-- sintaxa SQL 1992
SELECT e.last_name, e.job_id, d.department_id, d.department_name
FROM employees e, departments d, locations l
WHERE e.department_id=d.department_id AND d.location_id=l.location_id AND l.city='Toronto';

-- sintaxa SQL 1999
-- folosind clauza USING
SELECT e.last_name, e.job_id, department_id, d.department_name
FROM employees e JOIN departments d USING (department_id)
  JOIN locations l USING(location_id)
WHERE l.city='Toronto';

-- folosind clauza ON
SELECT e.last_name, e.job_id, e.department_id, d.department_name
FROM employees e JOIN departments d ON (e.department_id=d.department_id)
  JOIN locations l ON(d.location_id=l.location_id)
WHERE l.city='Toronto';


-- 5
-- sintaxa SQL 1992
SELECT e.last_name Employee, e.employee_id Emp#, m.last_name Manager, m.employee_id Mgr#
FROM Employees e, Employees m
WHERE e.manager_id=m.employee_id;

-- sintaxa SQL 1999
-- folosind clauza ON
SELECT e.last_name Employee, e.employee_id Emp#, m.last_name Manager, m.employee_id Mgr#
FROM Employees e JOIN Employees m
ON (e.manager_id=m.employee_id);


-- 6
-- sintaxa SQL 1992
SELECT e.last_name Employee, e.employee_id Emp#, m.last_name Manager, m.employee_id Mgr#
FROM Employees e, Employees m
WHERE e.manager_id=m.employee_id(+);

-- sintaxa SQL 1999
-- folosind clauza ON
SELECT e.last_name Employee, e.employee_id Emp#, m.last_name Manager, m.employee_id Mgr#
FROM Employees e LEFT OUTER JOIN Employees m
ON (e.manager_id=m.employee_id);


-- 7
-- sintaxa SQL 1992
SELECT d.department_name Departament, e.last_name Angajat, c.last_name Coleg
FROM Employees e, Departments d, Employees c
WHERE e.department_id=d.department_id AND e.department_id=c.department_id
  AND e.last_name<>c.last_name; 
  
-- sintaxa SQL 1999
-- folosind clauza ON
SELECT d.department_name Departament, e.last_name Angajat, c.last_name Coleg
FROM Employees e JOIN Departments d ON(e.department_id=d.department_id) JOIN Employees c ON(d.department_id=c.department_id)
WHERE e.last_name<>c.last_name;

-- folosind clauza USING
SELECT d.department_name Departament, e.last_name Angajat, c.last_name Coleg
FROM Employees e JOIN Departments d USING(department_id) JOIN Employees c USING(department_id)
WHERE e.last_name<>c.last_name;


-- 8
DESC job_grades;
SELECT * FROM job_grades;

-- sintaxa SQL 1992
SELECT e.last_name, j.job_title, d.department_name, e.salary, (SELECT grade_level FROM job_grades WHERE e.salary BETWEEN lowest_sal AND highest_sal) GRADE
FROM Employees e, Jobs j, Departments d
WHERE e.job_id=j.job_id AND d.department_id=e.department_id;

-- sintaxa SQL 1999
-- folosind clauza USING
SELECT e.last_name, j.job_title, d.department_name, e.salary, (SELECT grade_level FROM job_grades WHERE e.salary BETWEEN lowest_sal AND highest_sal) GRADE
FROM Employees e JOIN Jobs j USING(job_id) JOIN Departments d USING(department_id);

-- folosind clauza ON
SELECT e.last_name, j.job_title, d.department_name, e.salary, (SELECT grade_level FROM job_grades WHERE e.salary BETWEEN lowest_sal AND highest_sal) GRADE
FROM Employees e JOIN Jobs j ON(e.job_id=j.job_id) JOIN Departments d ON(d.department_id=e.department_id);


-- 9
SELECT last_name, hire_date 
FROM Employees
WHERE hire_date > (SELECT hire_date FROM Employees WHERE last_name='Davies');

-- 10
-- sintaxa SQL 1992
SELECT e.last_name Employee, e.hire_date Hiredate, m.last_name Manager, m.hire_date "Mgr Hiredate"
FROM Employees e, Employees m
WHERE e.manager_id=m.employee_id AND e.hire_date<m.hire_date;

-- sintaxa SQL 1999
-- folosind clauza ON
SELECT e.last_name Employee, e.hire_date Hiredate, m.last_name Manager, m.hire_date "Mgr Hiredate"
FROM Employees e JOIN Employees m ON(e.manager_id=m.employee_id)
WHERE e.hire_date<m.hire_date;


-- 11
SELECT RPAD(last_name, 15, ' ') || LPAD('*', salary/100, '*') EMPLOYEES_AND_THEIR_SALARIES
FROM Employees
ORDER BY salary DESC;