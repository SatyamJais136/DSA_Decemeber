# Write your MySQL query statement below
select(
    select max(salary)
    from employee
    where salary < (select max(salary) from employee)
) as SecondHighestSalary