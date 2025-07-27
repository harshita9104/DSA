# Write your MySQL query statement below
# since each student of students table is attending all the courses of Subjects table we need to do CROSS JOIN so that we are able to get all the rows in result with each stduent and attended subject pair 
# now this result table ko left join karo examinations k sath kyuki result table k sare col we need to show jaise stu_id, name, subj , stud_id will be common in result and examinations table so ye btayega konse student n konse subj ka exam diya h so left join will be on stud_id 
# or kyuki ek stud ek subj ka exam multiple times bhi de skta or hme vahi count karna h uska separate col show krna h ki ek stud n ek subj ka exam kitni baar diya uska count, to 
# group by kardo 3 col ko stud_id, name, subj ko , 
#for example , like alice gave math ka exam 3 baar to hme alice or math k combination ko 3 baar nhi likhna pdega if we have grouped by stud, subject name 
# or last m we need to order by stu_id and stu_name as said in q
#jinko group by kar rhe unko as it is selected col m likh dena baad m

SELECT s.student_id, s.student_name, sub.subject_name, COUNT(e.subject_name) as attended_exams
FROM Students s
CROSS JOIN Subjects sub
LEFT JOIN Examinations e 
ON s.student_id = e.student_id AND sub.subject_name = e.subject_name
GROUP BY s.student_id, s.student_name, sub.subject_name 
ORDER BY s.student_id, sub.subject_name;