/* CAPITOLUL 7 - Functii pe un singur rand */

/* EXERCITII */
-- 1
SELECT SYSDATE "Date"
FROM dual;

-- 2
SELECT employee_id, first_name, salary, salary + salary * 0.15 "Salariu Nou"
FROM employees;

-- 4
SELECT employee_id, first_name, salary, salary + salary * 0.15 "Salariu Nou", 0.15 * salary "Creştere"
FROM employees;

-- 5
SELECT first_name, hire_date, TO_CHAR(NEXT_DAY(ADD_MONTHS(hire_date, 6), 'Monday'), 'fmDay", the "Ddspth" of "Month", "YYYY') REVIEW
FROM employees;

-- 6
SELECT first_name, ROUND(MONTHS_BETWEEN(SYSDATE, hire_date)) LUNI_DE_ACTIVITATE 
FROM employees
ORDER BY LUNI_DE_ACTIVITATE;

-- 7
SELECT UPPER(first_name) || ' câştigă $' || salary || ' lunar, dar ar dori $' || 3 * salary || '.' "Salariul de vis"
FROM employees;

-- 8
SELECT first_name || ' ' || last_name, LPAD(salary, 15, '$') SALARIU
FROM employees;

-- 9
SELECT INITCAP(first_name), LENGTH(first_name)
FROM employees
WHERE UPPER(SUBSTR(first_name, 1, 1)) IN ('A', 'J', 'M');

-- 10
SELECT first_name, hire_date, TO_CHAR(hire_date, 'fmDay') ZI
FROM employees
ORDER BY DECODE(TO_NUMBER(TO_CHAR(hire_date, 'D')) - 1, 0, 7, TO_NUMBER(TO_CHAR(hire_date, 'D')) - 1);

-- 11
SELECT first_name, DECODE(NVL(commission_pct, 0), 0, 'No commission', commission_pct * salary) COMM
FROM employees;