WITH Second AS (
    SELECT managerId
    FROM Employee
    GROUP BY managerId
    HAVING COUNT(*) >= 5
)
SELECT name
FROM Employee JOIN Second ON employee.id= Second.managerId;
