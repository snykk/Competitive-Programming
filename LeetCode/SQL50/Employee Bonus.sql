CREATE TABLE Employee (
    empId INT PRIMARY KEY,
    name VARCHAR,
    supervisor INT,
    salary INT
);

CREATE TABLE Bonus (
    empId INT PRIMARY KEY,
    bonus INT,
    FOREIGN KEY (empId) REFERENCES Employee(empId)
);

INSERT INTO Employee (empId, name, supervisor, salary) VALUES
(3, 'Brad', NULL, 4000),
(1, 'John', 3, 1000),
(2, 'Dan', 3, 2000),
(4, 'Thomas', 3, 4000);

INSERT INTO Bonus (empId, bonus) VALUES
(2, 500),
(4, 2000);

-- solution
SELECT e.name, b.bonus
FROM Employee e
LEFT JOIN Bonus b
ON e.empId = b.empId
WHERE COALESCE(b.bonus, 0) < 1000