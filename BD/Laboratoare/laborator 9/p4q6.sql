-- sintaxa SQL 1992
SELECT e.last_name Employee, e.employee_id Emp#, m.last_name Manager, m.employee_id Mgr#
FROM Employees e, Employees m
WHERE e.manager_id=m.employee_id;

-- sintaxa SQL 1999
-- folosind clauza ON
SELECT e.last_name Employee, e.employee_id Emp#, m.last_name Manager, m.employee_id Mgr#
FROM Employees e JOIN Employees m
ON (e.manager_id=m.employee_id);