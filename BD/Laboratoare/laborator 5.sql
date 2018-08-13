/* CAPITOLUL 5 - Limbajul SQL implementat in Oracle */
-- dictionarul datelor 
SELECT * FROM user_tables; /* afiseaza detalii despre tabelele utilizatorilor */

SELECT * FROM user_objects; /* afiseaza obiectele componente ale utilizatorilor */

SELECT * FROM user_catalog; /* prescurtare de la user_tables */

-- exemplu cu TIMESTAMP
DROP TABLE time_example;
CREATE TABLE time_example (order_date TIMESTAMP WITH LOCAL TIME ZONE);
INSERT INTO time_example VALUES ('15-NOV-00 09:34:28 AM');
SELECT * FROM time_example;

-- stergerea unui tabel
DROP TABLE dept30;

-- crearea unui tabel pe baza unor date existente
CREATE TABLE dept30
AS
SELECT employee_id, last_name, 
salary*12 ANNSAL, hire_date 
FROM employees 
WHERE department_id=80;

SELECT * FROM dept30;

-- modificarea componentei tabelelor
ALTER TABLE dept30 
ADD (job_id VARCHAR2(10));

ALTER TABLE dept30 
MODIFY (first_name VARCHAR2(25));

-- afisarea structurii unui tabel
DESC dept30;

-- stergerea unei coloane
ALTER TABLE dept30
DROP COLUMN job_id;

-- seteaza o coloana ca nefolosita
ALTER TABLE dept30
SET UNUSED COLUMN last_name;

-- sterge coloanele nefolosite
ALTER TABLE dept30
DROP UNUSED COLUMNS;

DESC dept30;

-- redenumirea unui tabel
RENAME departments TO departments_new;

-- trunchierea unui tabel
TRUNCATE departments_new;

/* CONSTRANGERI */

-- afisarea constrangerilor tabelului "EMPLOYEES"
SELECT constraint_name, column_name
FROM user_cons_columns
WHERE table_name = 'EMPLOYEES_COPIE';

-- creare de tabele cu constrangeri
CREATE TABLE departments_copie (
	department_id NUMBER(4),
	department_name VARCHAR2(30)
	CONSTRAINT dept_name_nn NOT NULL,
	manager_id NUMBER(6),
	location_id NUMBER(4),
	CONSTRAINT dept_id_pk PRIMARY KEY (department_id) -- cheie primara
);

CREATE TABLE employees_copie (
	employee_id NUMBER(6),
	first_name VARCHAR2(20),
	job_id VARCHAR2(10) NOT NULL, -- not null
	email VARCHAR2(25),
	salary NUMBER(2)
	CONSTRAINT emp_salary_min CHECK(salary>0),
	commission_pct NUMBER(2,2),
	hire_date DATE NOT NULL, -- not null
  department_id NUMBER(2),
	CONSTRAINT emp_emp_id_pk PRIMARY KEY (employee_id), -- cheie primara
	CONSTRAINT emp_email_uk UNIQUE (email), -- unique
	CONSTRAINT emp_dept_fk FOREIGN KEY (department_id) REFERENCES departments_copie(department_id) -- cheie straina spre tabelul "departments_copie"
);

-- dezactivarea unei constrangeri
ALTER TABLE employees_copie
DISABLE CONSTRAINT emp_emp_id_pk CASCADE;

-- activarea unei constrangeri
ALTER TABLE employees
ENABLE CONSTRAINT emp_emp_id_pk;

-- afisarea constrangerilor
SELECT constraint_name, column_name
FROM user_cons_columns
WHERE table_name = 'EMPLOYEES_COPIE';

/* EXERCITII */
-- 1
CREATE TABLE dept (
	Id NUMBER(7),
	Name VARCHAR2(25)
);
DESCRIBE dept;

-- 2
INSERT INTO dept 
SELECT department_id, department_name 
FROM departments;

-- 3
CREATE TABLE emp (
  ID NUMBER(7),
  LAST_NAME VARCHAR2(25),
  FIRST_NAME VARCHAR2(25),
  DEPT_ID NUMBER(7)
);
DESCRIBE emp;

-- 4
ALTER TABLE emp
MODIFY (LAST_NAME VARCHAR2(40));
DESCRIBE emp;

-- 5
SELECT *
FROM user_tables;

-- 6
CREATE TABLE employee2
AS
SELECT employee_id, first_name, department_id
FROM employees;

ALTER TABLE employee2
RENAME COLUMN employee_id TO id;

ALTER TABLE employee2
RENAME COLUMN first_name TO last_name;

ALTER TABLE employee2
RENAME COLUMN department_id TO dept_id;

-- 7
RENAME employee2 TO employee3;

-- 8
DROP TABLE employee3;

-- 9
ALTER TABLE emp
ADD CONSTRAINT emp_id_pk PRIMARY KEY (id);
ALTER TABLE emp
ENABLE CONSTRAINT emp_id_pk;

-- 10
ALTER TABLE dept
ADD CONSTRAINT dept_id_pk_2 PRIMARY KEY (id);
ALTER TABLE dept
ENABLE CONSTRAINT dept_id_pk_2;

-- 11
ALTER TABLE emp
ADD CONSTRAINT emp_dept_id_fk FOREIGN KEY (dept_id) REFERENCES dept(id);

-- 12
SELECT constraint_name, constraint_type, table_name
FROM user_constraints
WHERE table_name IN ('EMP', 'DEPT');

-- 13
SELECT object_name, object_type
FROM user_objects
WHERE object_name='EMP' OR object_name LIKE 'EMP$_%' ESCAPE '$' OR object_name LIKE 'DEPT%';

-- 14
ALTER TABLE emp
ADD (salary NUMBER(7));

-- 15
ALTER TABLE emp
DROP COLUMN first_name;
DESCRIBE emp;

-- 16
ALTER TABLE emp
SET UNUSED COLUMN dept_id;
DESCRIBE emp;

-- 17
ALTER TABLE emp
DROP UNUSED COLUMNS;
DESCRIBE emp;