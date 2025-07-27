# Write your MySQL query statement below
#no need of join as one table register is sufficient to find the no of distinct users registered for a contest if we grp by contest_id 
# there may be some users who have not registered for any contest so, for getting the count of total users to find percentage register table ko to group by kr dia ab to operate separately on users table use subquery 
SELECT contest_id , round(COUNT(DISTINCT user_id)*100/ (SELECT COUNT(user_id) FROM Users),2) AS percentage
FROM Register 

GROUP BY contest_id
ORDER BY percentage DESC, contest_id;