# Write your MySQL query statement below
# self join krenge or machine id k corresponding ek col  bnega processing_time, usko nikalne k liye
# same table ko 2 baar consider kro yani join krlo
# join on , yani join kis basis par kar rhe vo btane k liye, join on these condn of col to form one row which will have col as
# 1st condn machine id of both table shd be same , process id also shd be same,  actvity type of one table shd be start and other table shd be end 
#jab ye ek row ban jaegi tab processing time nikalna h or is machine k jitne bhi process hai sabka proces time ko avg karna h 
#isliye we will group by machine id kyuki ek machine id k corresponding ek hi avg proces time chahiye result m isliye avg operation is machine _id wale grp k sare process par hoga
SELECT a1.machine_id, round(avg(a2.timestamp - a1.timestamp),3) as processing_time 
FROM Activity a1
JOIN Activity a2
ON a1.machine_id  = a2.machine_id AND a1.process_id  = a2.process_id AND a1.activity_type  = 'start' AND a2.activity_type  = 'end'

GROUP BY a1.machine_id;
