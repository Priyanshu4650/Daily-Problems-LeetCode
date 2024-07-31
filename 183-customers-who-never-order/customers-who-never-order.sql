# Write your MySQL query statement below
select a.name as Customers 
from customers a
where a.id not in (
    select b.id 
    from customers b
        inner join orders c on c.customerId = b.Id
);