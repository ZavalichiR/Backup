/* CAPITOLUL 6 - Expresii aritmetice. Operatori */
-- operatori aritmetici
SELECT last_name, salary, salary + 300
FROM employees;

SELECT last_name, salary, 12 * salary + 100
FROM employees;

SELECT last_name, salary, 12 * (salary + 100)
FROM employees;

-- definirea valorii nule
SELECT last_name, job_id, salary, commission_pct
FROM employees;

-- valoarea nula in expresii aritmetice
SELECT last_name, 12 * salary * commission_pct
FROM employees;

-- definirea alias-urilor pentru coloane
SELECT last_name AS name, commission_pct comm
FROM employees;

-- operatorul de concatenare
SELECT first_name || ' ' || last_name nume
FROM employees;

SELECT last_name || job_id AS "Employees"
FROM employees;

-- siruri de caractere
SELECT last_name || ' is a ' || job_id AS "Employee Details"
FROM employees;

SELECT last_name || ':1 Month salary = ' || salary Monthly
FROM employees;

-- randuri duplicate
SELECT department_id 
FROM employees;

-- eliminarea randurilor duplicate
SELECT DISTINCT department_id 
FROM employees;

SELECT DISTINCT department_id, job_id 
FROM employees;

-- afisarea structurii unei tabele
DESCRIBE employees;

-- restrictionarea si sortarea datelor
SELECT employee_id, last_name, first_name, department_id
FROM employees 
WHERE department_id=90;

SELECT last_name, job_id, department_id 
FROM employees
WHERE last_name='Whalen'; -- sirurile de caractere se scriu intre apostrofuri

-- operatori de comparatie
SELECT last_name, salary
FROM employees
WHERE salary<=3000;

-- operatorul BETWEEN
SELECT last_name, salary
FROM employees
WHERE salary BETWEEN 2500 AND 3500;

-- operatorul IN
SELECT employee_id, last_name, salary, manager_id
FROM employees
WHERE manager_id IN (100,101,201);

SELECT employee_id, manager_id, department_id
FROM employees
WHERE last_name IN ('Harstein', 'Vargas');

-- operatorul LIKE
SELECT first_name
FROM EMPLOYEES
WHERE first_name LIKE 'S%';

SELECT first_name
FROM EMPLOYEES
WHERE first_name LIKE '_h%';

SELECT last_name, hire_date FROM EMPLOYEES
WHERE hire_date LIKE '%95';

-- caracterul ESCAPE
SELECT employee_id,last_name,job_id
FROM EMPLOYEES
WHERE job_id LIKE '%SA\_%' ESCAPE '\';

-- operatorul IS NULL
SELECT last_name, manager_id
FROM EMPLOYEES
WHERE manager_id IS NULL;

SELECT last_name, job_id, commission_pct
FROM EMPLOYEES
WHERE commission_pct IS NULL;

-- operatori logici
SELECT employee_id, last_name, job_id, salary
FROM EMPLOYEES
WHERE salary>=10000 AND job_id LIKE '%MAN%';

SELECT employee_id, last_name, job_id, salary
FROM EMPLOYEES
WHERE salary>=10000 OR job_id LIKE '%MAN%';

SELECT last_name, job_id, salary
FROM EMPLOYEES
WHERE job_id NOT IN ('IT_PROG', 'ST_CLERK', 'SA_REP');

SELECT last_name, job_id, salary 
FROM EMPLOYEES
WHERE job_id='SA_REP'
OR JOB_ID='AD_PRES' AND SALARY>15000;

SELECT last_name, job_id, salary 
FROM EMPLOYEES
WHERE (job_id='SA_REP' OR JOB_ID='AD_PRES') AND SALARY>15000;

-- clauza ORDER BY
SELECT last_name, job_id, department_id, hire_date
FROM EMPLOYEES
ORDER BY hire_date DESC;

-- sortarea dupa un alias creat
SELECT employee_id, last_name, salary*12 annsal
FROM EMPLOYEES ORDER BY annsal;

-- sortarea dupa mai multe coloane
SELECT last_name, department_id, salary
FROM EMPLOYEES 
ORDER BY department_id, salary DESC;

/* EXERCITII */
-- 2
-- adevărat

-- 3
-- adevărat

-- 4
-- fals -> tabelul nu există

-- 5
SELECT first_name, salary x 12 ANNUAL SALARY FROM EMPLOYEES;
/*                        ^          ^
                          |          |
         operatorul corect e "*"     |
                                     |
                alias-urile cu spatii se pun intre ghilimele
-- corect este: */
SELECT first_name, salary * 12 "ANNUAL SALARY" FROM EMPLOYEES;

-- 6
DESCRIBE departments;
SELECT * FROM departments;

-- 7
DESCRIBE employees;
SELECT first_name, job_id, hire_date, employee_id FROM employees;

-- 8
@abc.sql

-- 9
SELECT DISTINCT(job_id)
FROM employees;

-- 10
-- se scrie comanda "ed abc.sql" in consola Oracle (in terminal)
-- se editeaza coloanele
-- se salveaza fisierul
-- se executa script-ul din nou cu comanda "@abc.sql"

-- 11
SELECT first_name || ', ' || job_id AS "EMPLOYEES - JOB and Title"
FROM employees;

-- 12
SELECT employee_id || ', ' || first_name || ', ' || last_name || ', ' || email || ', ' || phone_number || ', ' || hire_date || ', ' || job_id || ', ' || salary || ', ' || commission_pct || ', ' || manager_id || ', ' || department_id THE_OUTPUT
FROM employees;

-- 13
SELECT first_name, salary
FROM employees
WHERE salary > 28500;

@p1.sql

-- 14
SELECT first_name, department_name
FROM employees e, departments d
WHERE employee_id=201 AND e.department_id=d.department_id;

-- 15
SELECT first_name, salary
FROM employees
WHERE salary NOT BETWEEN 15000 AND 28500;

@p3.sql

-- 16
SELECT first_name, job_title, hire_date
FROM employees e, jobs j
WHERE e.job_id=j.job_id
  AND hire_date BETWEEN TO_DATE('20.02.1985', 'dd.mm.yyyy') AND TO_DATE('01.05.1992', 'dd.mm.yyyy')
ORDER BY hire_date;

-- 17
SELECT first_name, department_id
FROM employees
WHERE department_id IN (10, 30)
ORDER BY first_name;

-- 18
SELECT first_name "Angajat", salary "Salariu lunar"
FROM employees
WHERE salary > 15000 AND department_id IN (10, 30);

@p6.sql

-- 19
SELECT first_name, hire_date
FROM employees
WHERE EXTRACT(YEAR FROM hire_date)=1995;

-- 20
SELECT first_name, job_title
FROM employees e, jobs j
WHERE e.job_id=j.job_id AND manager_id IS NULL;

-- 21
SELECT first_name, salary, commission_pct * salary
FROM employees
WHERE commission_pct IS NOT NULL
ORDER BY salary DESC, commission_pct DESC;

-- 22
SELECT first_name
FROM employees
WHERE first_name LIKE '__A%';

-- 23
SELECT first_name
FROM employees
WHERE (first_name LIKE '%l%l%' AND department_id=30)
  OR manager_id=100;

-- 24
SELECT first_name, job_title, salary
FROM employees e, jobs j
WHERE e.job_id=j.job_id AND
  e.job_id IN ('ST_CLERK', 'ST_MAN') AND
  salary NOT IN (10000, 30000, 50000);

-- 25
SELECT first_name, salary, commission_pct * salary
FROM employees
WHERE commission_pct * salary > (salary + 0.1 * salary);

@p13.sql