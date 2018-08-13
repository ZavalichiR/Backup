/* CAPITOLUL 9 - Functii de grup */


/* EXERCITII */
-- 1
-- adevarat

-- 2
-- fals

-- 3
-- adevarat

-- 4
SELECT ROUND(MAX(salary)) AS "Maxim", ROUND(MIN(salary)) AS "Minim", 
  ROUND(SUM(salary)) AS "Suma", ROUND(AVG(salary)) AS "Media"
FROM Employees;

-- 5
SELECT job_id, ROUND(MAX(salary)) AS "Maxim", ROUND(MIN(salary)) AS "Minim", 
  ROUND(SUM(salary)) AS "Suma", ROUND(AVG(salary)) AS "Media"
FROM Employees
GROUP BY job_id;

-- 6
SELECT job_id, COUNT(*)
FROM Employees
GROUP BY job_id;

-- 7
SELECT COUNT(DISTINCT(manager_id)) AS "Nr. Manageri"
FROM Employees;

-- 8
SELECT MAX(salary) - MIN(salary) AS "Diferenta"
FROM Employees;

-- 9
SELECT manager_id, MIN(salary)
FROM Employees
WHERE manager_id IS NOT NULL
GROUP BY manager_id
HAVING MIN(salary) >= 6600
ORDER BY MIN(salary) DESC;

-- 10
SELECT d.department_name Dname, d.location_id Loc, COUNT(e.employee_id) "No of People", ROUND(AVG(e.salary), 2) Salary
FROM Employees e, Departments d
WHERE e.department_id=d.department_id
GROUP BY department_name, location_id;

-- 11
SELECT TO_CHAR(hire_date, 'yyyy') AS "An", COUNT(*) AS "Total"
FROM Employees
GROUP BY ROLLUP(TO_CHAR(hire_date, 'yyyy')) --daca pui si last-name, mai adauga linii grupate dupa nume
HAVING TO_CHAR(hire_date, 'yyyy') IN ('1995', '1996', '1997', '1998');
      -- o alta varianta: TO_NUMBER(TO_CHAR(...)) BETWEEN 1995 AND 1998
-- este o varianta intermediara, nu este rezolvarea propriu-zisa a problemei
-- afiseaza rezultatele pe linii, nu pe coloane

-- pentru rezolvarea problemei folosim: SUM(DECODE(TO_CHAR(hire_date, 'yyyy'), '1995', 1))
-- .......... acelasi lucru pentru fiecare an
SELECT COUNT(*) AS "Total", SUM(DECODE(TO_CHAR(hire_date, 'yyyy'), '1995', 1)) AS "1995",
  SUM(DECODE(TO_CHAR(hire_date, 'yyyy'), '1996', 1)) AS "1996",
  SUM(DECODE(TO_CHAR(hire_date, 'yyyy'), '1997', 1)) AS "1997",
  SUM(DECODE(TO_CHAR(hire_date, 'yyyy'), '1998', 1)) AS "1998"
FROM Employees;

-- SAU, cu subinterogari:
SELECT COUNT(*) AS "Total", MIN((SELECT COUNT(*) FROM Employees WHERE EXTRACT(YEAR FROM hire_date) = 1995)) AS "1995",
  MIN((SELECT COUNT(*) FROM Employees WHERE EXTRACT(YEAR FROM hire_date) = 1996)) AS "1996",
  MIN((SELECT COUNT(*) FROM Employees WHERE EXTRACT(YEAR FROM hire_date) = 1997)) AS "1997",
  MIN((SELECT COUNT(*) FROM Employees WHERE EXTRACT(YEAR FROM hire_date) = 1998)) AS "1998"
FROM Employees;


-- 12
SELECT e.job_id Job, 
  (SELECT SUM(salary) FROM Employees WHERE department_id=20 AND job_id=e.job_id) "Dept 20", 
  (SELECT SUM(salary) FROM Employees WHERE department_id=50 AND job_id=e.job_id) "Dept 50",
  (SELECT SUM(salary) FROM Employees WHERE department_id=80 AND job_id=e.job_id) "Dept 80",
  (SELECT SUM(salary) FROM Employees WHERE department_id=90 AND job_id=e.job_id) "Dept 90",
  SUM(e.salary) Total
FROM Employees e
GROUP BY e.job_id, e.department_id;

-- 13
SELECT manager_id, job_id, SUM(salary)
FROM Employees
WHERE manager_id<120
GROUP BY ROLLUP(manager_id, job_id);

-- 14
SELECT manager_id, job_id, SUM(salary), GROUPING(manager_id), GROUPING(job_id)
FROM Employees
WHERE manager_id<120
GROUP BY ROLLUP(manager_id, job_id);

-- 15
SELECT manager_id, job_id, SUM(salary)
FROM Employees
WHERE manager_id<120
GROUP BY CUBE(manager_id, job_id);

-- 16
SELECT manager_id, job_id, SUM(salary), GROUPING(manager_id), GROUPING(job_id)
FROM Employees
WHERE manager_id<120
GROUP BY CUBE(manager_id, job_id);

-- 17
SELECT department_id, manager_id, job_id, SUM(salary) Salary
FROM Employees
GROUP BY GROUPING SETS((department_id, manager_id, job_id),
  (department_id, job_id),
  (manager_id, job_id));