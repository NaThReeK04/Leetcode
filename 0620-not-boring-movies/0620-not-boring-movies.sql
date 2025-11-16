# Write your MySQL query statement below
Select * from Cinema 
Where Cinema.id%2=1 AND Cinema.description!="boring"
Order by rating DESC;