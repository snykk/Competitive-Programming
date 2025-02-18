CREATE TABLE Employees (
    employee_id INT PRIMARY KEY,
    name VARCHAR(100),
    reports_to INT,
    age INT,
    FOREIGN KEY (reports_to) REFERENCES Employees(employee_id)
);

INSERT INTO Employees (employee_id, name, reports_to, age)
VALUES 
(9, 'Hercy', NULL, 43),
(6, 'Alice', 9, 41),
(4, 'Bob', 9, 36),
(2, 'Winston', NULL, 37);

-- Example 2
INSERT INTO Employees (employee_id, name, reports_to, age)
VALUES 
(1, 'Michael', NULL, 45),
(2, 'Alice', 1, 38),
(3, 'Bob', 1, 42),
(4, 'Charlie', 2, 34),
(5, 'David', 2, 40),
(6, 'Eve', 3, 37),
(7, 'Frank', NULL, 50),
(8, 'Grace', NULL, 48);

-- solution
SELECT 
    manager_id AS employee_id,
    manager_name AS name,
    COUNT(employee_id) AS reports_count,
    ROUND(AVG(employee_age)) AS average_age
FROM (
    SELECT 
        e.employee_id AS manager_id,
        e.name AS manager_name,
        r.employee_id AS employee_id,
        r.name AS employee_name,
        r.age AS employee_age
    FROM Employees e
    JOIN Employees r ON e.employee_id = r.reports_to
) subquery
GROUP BY manager_id, manager_name
ORDER BY manager_id;
