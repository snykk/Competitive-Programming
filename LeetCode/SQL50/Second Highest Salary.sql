CREATE TABLE Employee (
    id SERIAL PRIMARY KEY,
    salary INT NOT NULL
);

INSERT INTO Employee (salary) VALUES
(100),
(200),
(300);


-- solving
SELECT * FROM Employee

SELECT 
	salary,
	DENSE_RANK() OVER (ORDER BY salary) AS rnk
FROM Employee
GROUP BY salary

WITH salary_rank AS (
	SELECT 
		salary,
		DENSE_RANK() OVER (ORDER BY salary) AS rnk
	FROM Employee
	GROUP BY salary
)
SELECT 
	salary AS "SecondHighestSalary" 
FROm salary_rank
WHERE rnk = 2

-- solution
SELECT MAX(salary) AS SecondHighestSalary
FROM Employee
WHERE salary < (SELECT MAX(salary) FROM Employee);