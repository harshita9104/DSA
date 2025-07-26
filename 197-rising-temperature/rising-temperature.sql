# Write your MySQL query statement below
#take same table twice and find the date diff = 1 with DATEDIFF function , Compare the dates of w1 and w2 using the DATEDIFF() function to check if they are consecutive days (with a difference of 1 day).
#add a condition to only consider the rows where temp of w1 is greater than temp of w2

SELECT w1.id
FROM Weather w1, Weather w2
WHERE DATEDIFF(w1.recordDate, w2.recordDate) = 1 AND w1.temperature > w2.temperature;
