# Write your MySQL query statement below
#we use in to result back any value that matches that list
#example WHERE col_name IN("", ""), and to negate it put NOT IN

SELECT *
FROM Cinema
WHERE id% 2 = 1 AND description NOT IN("boring")
ORDER BY rating DESC;