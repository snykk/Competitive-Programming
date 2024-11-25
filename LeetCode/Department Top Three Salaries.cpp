-- Write your PostgreSQL query statement below

WITH RankedSalaries AS (
    SELECT 
        d.name AS Department,
        e.name AS Employee,
        e.salary,
        DENSE_RANK() OVER (PARTITION BY e.departmentId ORDER BY e.salary DESC) AS rank
    FROM 
        Employee e
    JOIN 
        Department d
        ON e.departmentId = d.id
),
TopThreeSalaries AS (
    SELECT 
        Department,
        Employee,
        salary
    FROM 
        RankedSalaries
    WHERE 
        rank <= 3
)
SELECT 
    Department,
    Employee,
    salary AS Salary
FROM 
    TopThreeSalaries;
