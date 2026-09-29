# Write your MySQL query statement below
select d.name as Department , e.name as Employee, e.salary as Salary
from employee e
join department d
on e.departmentId = d.id
group by d.name
order by e.salary desc
having limit 3;