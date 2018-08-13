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
