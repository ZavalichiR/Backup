SELECT job_id, ROUND(MAX(salary)) AS "Maxim", ROUND(MIN(salary)) AS "Minim", 
  ROUND(SUM(salary)) AS "Suma", ROUND(AVG(salary)) AS "Media"
FROM Employees
GROUP BY job_id;