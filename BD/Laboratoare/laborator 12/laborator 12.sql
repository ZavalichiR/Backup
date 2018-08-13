/* CAPITOLUL 11 - Instructiuni pentru manipularea datelor (DML) */

/* EXERCITII */
--1
CREATE TABLE MY_EMPLOYEE (
  id NUMBER(5),
  last_name VARCHAR2(25),
  first_name VARCHAR2(25),
  userid VARCHAR2(20),
  salary NUMBER(10, 2)
);
INSERT INTO MY_EMPLOYEE VALUES(1, 'L_E1', 'F_E1', 'UID1', 1000);
INSERT INTO MY_EMPLOYEE VALUES(2, 'L_E2', 'F_E2', 'UID2', 1670);
INSERT INTO MY_EMPLOYEE VALUES(3, 'L_E3', 'F_E3', 'UID3', 800);
INSERT INTO MY_EMPLOYEE VALUES(4, 'L_E4', 'F_E4', 'UID4', 550);

-- 2
DESCRIBE MY_EMPLOYEE;

-- 3
INSERT INTO MY_EMPLOYEE VALUES(5, 'Patel', 'Ralph', 'rpatel', 795);

-- 4
INSERT INTO MY_EMPLOYEE (id, last_name, first_name, userid, salary)
  VALUES ('6', 'Dancs', 'Betty', 'bdancs', 860);
  
-- 5
SELECT *
FROM MY_EMPLOYEE;

-- 6
ACCEPT first_name PROMPT 'Introduceti prenumele: ';
ACCEPT last_name PROMPT 'Introduceti numele: ';
ACCEPT salary PROMPT 'Introduceti salariul: ';

INSERT INTO MY_EMPLOYEE (first_name, last_name, userid, salary) 
	VALUES ('&first_name', '&last_name', SUBSTR('&first_name', 0, 1) || SUBSTR('&last_name', 0, 7), TO_NUMBER('&salary'));

-- 7
@load_EMPLOYEES.sql;
@load_EMPLOYEES.sql;

-- 8
SELECT *
FROM MY_EMPLOYEE;

-- 9
COMMIT;

DELETE FROM MY_EMPLOYEE
WHERE id=2;

UPDATE MY_EMPLOYEE
SET first_name='modificat'
WHERE id=1;

-- 10
UPDATE MY_EMPLOYEE
SET last_name='Drexler'
WHERE id=3;

-- 11
UPDATE MY_EMPLOYEE
SET salary=1000
WHERE salary<900;

-- 12
SELECT *
FROM MY_EMPLOYEE;

-- 13
DELETE FROM MY_EMPLOYEE
WHERE userid='bdancs';

-- 14
SELECT *
FROM MY_EMPLOYEE;

-- 15
COMMIT;

-- 16
@load_EMPLOYEES.sql;

-- 17
SELECT *
FROM MY_EMPLOYEE;

-- 18
SAVEPOINT a_svp;

-- 19
DELETE
FROM MY_EMPLOYEE;

-- 20
SELECT *
FROM MY_EMPLOYEE;

-- 21
ROLLBACK TO a_svp;

-- 22
SELECT *
FROM MY_EMPLOYEE;

COMMIT;

-- 23
CREATE TABLE sal_history(
  employee_id NUMBER(6),
  hire_date DATE,
  salary NUMBER(8, 2)
);

CREATE TABLE mgr_history(
  employee_id NUMBER(6),
  manager_id NUMBER(6),
  salary NUMBER(8, 2)
);

CREATE TABLE special_sal(
  employee_id NUMBER(6),
  salary NUMBER(8, 2)
);

-- 24
-- a
SELECT employee_id, hire_date, manager_id
FROM Employees
WHERE employee_id<125;

INSERT INTO special_sal
  SELECT employee_id, salary
  FROM Employees
  WHERE salary>20000;

INSERT INTO sal_history
  SELECT employee_id, hire_date, salary
  FROM Employees;

INSERT INTO mgr_history
  SELECT employee_id, manager_id, salary
  FROM Employees;

-- b
SELECT *
FROM special_sal;

-- c
SELECT *
FROM sal_history;

-- d
SELECT *
FROM mgr_history;

-- 25
-- a
CREATE TABLE sales_source_data(
  employee_id NUMBER(6),
  week_id NUMBER(2),
  sales_mon NUMBER(8, 2),
  sales_tue NUMBER(8, 2),
  sales_wed NUMBER(8, 2),
  sales_thur NUMBER(8, 2),
  sales_fri NUMBER(8, 2)
);

INSERT INTO sales_source_data
  VALUES (178, 6, 1750, 2200, 1500, 1500, 3000);

-- b
CREATE TABLE sales_info(
  employee_id NUMBER(6),
  week NUMBER(2),
  sales NUMBER(8, 2)
);

-- c
SELECT *
FROM sales_source_data;

INSERT ALL
INTO sales_info VALUES(employee_id, week_id, sales_mon)
INTO sales_info VALUES(employee_id, week_id, sales_tue)
INTO sales_info VALUES(employee_id, week_id, sales_wed)
INTO sales_info VALUES(employee_id, week_id, sales_thur)
INTO sales_info VALUES(employee_id, week_id, sales_fri)
SELECT employee_id, week_id, sales_mon, sales_tue, sales_wed, sales_thur, sales_fri
FROM sales_source_data;

SELECT *
FROM sales_info;

-- problema suplimentara
/*
Sa se modifice salariile managerilor de departamente (MANAGER_ID din DEPARTMENTS) care 
se afla intr-un oras (CITY din LOCATIONS) astfel incat sa creasca cu 1% din maximul functiei 
(MAX_SALARY din JOBS) fiecaruia. Asigurati-va ca parametrul introdus nu este CASE-SENSITIVE.

Afisati coloanele semnificative ptr. inregistrarile modificate (DOAR ACESTEA !!). 
Reveniti la datele initiale. Afisati si acum pentru verificare.

Pentru claritatea afisarii puteti folosi comanda: SET VERIFY OFF.
*/

ACCEPT v_city PROMPT "Introduceti orasul: ";
SAVEPOINT inainte_de_update;

UPDATE Employees e
SET (salary = salary + 0.01 * ( -- aici se lucreaza pe un singur rand!
  SELECT max_salary FROM Jobs WHERE job_id=e.job_id)) -- randurile de aici determina care "job_id" este cautat
WHERE employee_id IN ( -- aici, in exterior, sunt randurile cautate de UPDATE
  SELECT manager_id FROM Departments d, Locations l
  WHERE d.location_id=l.location_id AND l.city='&v_city'); -- conditia pentru cine se modifica
  -- SAU: WHERE location_id IN (SELECT location_id FROM Locations WHERE city='&v_city'));

SELECT e.salary, j.max_salary, d.manager_id, l.city
FROM Employees e, Jobs j, Departments d, Locations l
WHERE e.department_id=d.department_id AND d.location_id=l.location_id AND e.job_id=j.job_id
  AND l.city=INITCAP('&v_city');

ROLLBACK TO inainte_de_update;

SELECT e.salary, j.max_salary, d.manager_id, l.city
FROM Employees e, Jobs j, Departments d, Locations l
WHERE e.department_id=d.department_id AND d.location_id=l.location_id AND e.job_id=j.job_id
  AND l.city=INITCAP('&v_city');