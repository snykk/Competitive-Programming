CREATE TABLE Employee (
    employee_id INT,
    department_id INT,
    primary_flag VARCHAR(1) CHECK (primary_flag IN ('Y', 'N')),
    PRIMARY KEY (employee_id, department_id)
);

INSERT INTO Employee (employee_id, department_id, primary_flag) VALUES
(1, 1, 'N'),
(2, 1, 'Y'),
(2, 2, 'N'),
(3, 3, 'N'),
(4, 2, 'N'),
(4, 3, 'Y'),
(4, 4, 'N');

-- solving
SELECT * FROM Employee;

WITH employee_and_department_detail AS (
	SELECT 
		employee_id, 
		CASE WHEN COUNT(*) = 1 THEN 1 ELSE 0 END AS is_only_one_department
	FROM Employee
	GROUP BY employee_id
	ORDER BY employee_id
)
SELECT *
FROM Employee e
JOIN employee_and_department_detail ed
ON e.employee_id = ed.employee_id 

SELECT employee_id
FROM Employee
GROUP BY employee_id 
HAVING COUNT(*) = 1;

SELECT employee_id, department_id
FROM Employee
WHERE primary_flag = 'Y' OR employee_id IN 
		(
			SELECT employee_id
			FROM Employee
			GROUP BY employee_id
			HAVING COUNT(*) = 1
		)
ORDER BY employee_id;

-- solution

SELECT employee_id, department_id
FROM Employee
WHERE primary_flag = 'Y' OR employee_id IN 
		(
			SELECT employee_id
			FROM Employee
			GROUP BY employee_id
			HAVING COUNT(*) = 1
		)
ORDER BY employee_id;
