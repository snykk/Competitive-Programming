CREATE TABLE Employee (
    id INT PRIMARY KEY,
    name VARCHAR(255),
    salary INT,
    departmentId INT,
    FOREIGN KEY (departmentId) REFERENCES Department(id)
);

CREATE TABLE Department (
    id INT PRIMARY KEY,
    name VARCHAR(255)
);


INSERT INTO Department (id, name)
VALUES
(1, 'IT'),
(2, 'Sales');

INSERT INTO Employee (id, name, salary, departmentId)
VALUES
(1, 'Joe', 85000, 1),
(2, 'Henry', 80000, 2),
(3, 'Sam', 60000, 2),
(4, 'Max', 90000, 1),
(5, 'Janet', 69000, 1),
(6, 'Randy', 85000, 1),
(7, 'Will', 70000, 1);

-- solution
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
