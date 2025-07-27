# Write your MySQL query statement below
# percentage of queries with rating less than 3 find krne k liye avg lelo to upon m total queries nhi likhni pdegi, to apply condition on rating use if since hme no of rating with value < 3 find krna h to hm rating ko 1 consider krenge if it is <3 otherwise 0 
SELECT query_name, round(avg(rating/position),2) AS quality, round(avg(if(rating< 3, 1, 0))*100,2) AS poor_query_percentage
FROM Queries
GROUP BY query_name;