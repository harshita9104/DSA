# Write your MySQL query statement below
#it is given that emloyees table contain id oand name of emplyees in a company
# and employeeuni contain id and unique id and and we need to show unique id of the employeees in result but if they dont have put null at that place
# since there is a common col id bw these tables we use join and since i need to get all the content of left table that is the names of all employees and if their id matches with id in right table then they may have a unique id otherwise there unique id will be null so i will use left join
SELECT EmployeeUNI.unique_id,  Employees.name
FROM Employees
LEFT JOIN EmployeeUNI 
ON Employees.id = EmployeeUNI.id;