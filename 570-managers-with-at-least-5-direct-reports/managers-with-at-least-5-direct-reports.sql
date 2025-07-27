# Write your MySQL query statement below
# manager is also an employee to is table ka isi k sath inner join lelo ON e.id = e.manager_id 
# to aise employee mil jaenge jo manager bhi h or unka count bhi lena h to manager_id ka grp bnalo or phir un id ko count krlo
SELECT e1.name
FROM Employee AS e1
INNER JOIN Employee AS e2
ON e1.id = e2.managerID 
GROUP BY e2.managerID 
HAVING COUNT(e2.managerID) >= 5;

#manger ka group bna liya ab same manager ki id kitni baar usko count krna h 
#ek baar hi aayegi manager id to same manager_id ka grp bna lenege phir resultant table m ek manager_id ek baar hi aayega or konsi aayegi vo condition lgane k liye yani grp par condition lagane k liye having use karenge 
