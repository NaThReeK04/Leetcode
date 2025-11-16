# Write your MySQL query statement below
SELECT today.id 
FROM Weather yesterday JOIN Weather today
ON DATEDIFF(today.recordDate,yesterday.recordDate)=1
WHERE today.temperature>yesterday.temperature;