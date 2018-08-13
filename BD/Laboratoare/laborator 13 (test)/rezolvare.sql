-- 1
SELECT * FROM Countries;
SELECT r.region_name, (SELECT COUNT(country_id) 
                      FROM Countries
                      WHERE region_id=r.region_id) "Numar de tari"
FROM Regions r;

-- 2
SELECT e.last_name, (SELECT COUNT(*)
                    FROM Employees
                    WHERE department_id=e.department_id
                      AND NVL(e.manager_id, -1)<>employee_id -- sa nu fie manager pentru angajatul curent
                      AND e.employee_id<>employee_id) -- sa nu fie coleg cu el insusi
                      "numar colegi"
                      
FROM Employees e;

-- 3
SELECT e.last_name, e.hire_date
FROM Employees e
WHERE SYSDATE-hire_date<(
  SELECT AVG(SYSDATE-hire_date) -- vechimea medie din departamentul angajatului curent
  FROM Employees
  WHERE department_id=e.department_id);
  
-- 4
SELECT e.last_name, e.salary, j.job_title,
  e.salary-j.min_salary "peste minim",
  j.max_salary-e.salary "sub maxim"
FROM Employees e, Jobs j
WHERE e.job_id=j.job_id;