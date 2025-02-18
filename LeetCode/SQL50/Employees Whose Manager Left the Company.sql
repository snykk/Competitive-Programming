CREATE TABLE Employees (
    employee_id INT PRIMARY KEY,
    name VARCHAR(255),
    manager_id INT,
    salary INT
);

INSERT INTO Employees (employee_id, name, manager_id, salary) VALUES
(3, 'Mila', 9, 60301),
(12, 'Antonella', NULL, 31000),
(13, 'Emery', NULL, 67084),
(1, 'Kalel', 11, 21241),
(9, 'Mikaela', NULL, 50937),
(11, 'Joziah', 6, 28485);

-- solution
SELECT * FROM Employees

SELECT e1.employee_id FROM Employees e1
WHERE 
	salary < 30000 AND e1.manager_id IS NOT NULL AND 
	(SELECT COUNT(*) FROM Employees e2 
	 	WHERE e2.employee_id = e1.manager_id) = 0
ORDER BY e1.employee_id

SELECT e.employee_id
FROM Employees e
WHERE e.salary < 30000
  AND e.manager_id NOT IN (SELECT employee_id FROM Employees) -- alternative subquery
ORDER BY e.employee_id;

		
SELECT e.employee_id -- using join (without subquery)
FROM Employees e
LEFT JOIN Employees m ON e.manager_id = m.employee_id
WHERE e.salary < 30000
  AND m.employee_id IS NULL
ORDER BY e.employee_id;

