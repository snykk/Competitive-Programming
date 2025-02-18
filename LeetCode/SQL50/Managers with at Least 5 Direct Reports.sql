CREATE TABLE Employee (
    id INT PRIMARY KEY,
    name VARCHAR,
    department VARCHAR,
    managerId INT
);

INSERT INTO Employee (id, name, department, managerId) VALUES
(101, 'John', 'A', NULL),
(102, 'Dan', 'A', 101),
(103, 'James', 'A', 101),
(104, 'Amy', 'A', 101),
(105, 'Anne', 'A', 101),
(106, 'Ron', 'B', 101);

-- solution
WITH TargetEmployee AS (
    SELECT managerId
    FROM Employee
    GROUP BY managerId
    HAVING COUNT(managerId) >= 5
)
SELECT e.name
FROM Employee e
JOIN TargetEmployee te
ON e.id = te.managerId