CREATE TABLE Logs (
    id SERIAL PRIMARY KEY,
    num VARCHAR(255) NOT NULL
);

INSERT INTO Logs (num) VALUES
('1'),
('1'),
('1'),
('2'),
('1'),
('2'),
('2');

-- solving
WITH table_with_lag AS (
	SELECT 
		*,
		LAG(num, 1) OVER(ORDER BY id) AS prev_num,
		LAG(num, 2) OVER(ORDER BY id) AS prev_two_num
	FROM Logs
)
SELECT num AS ConsecutiveNums 
FROM table_with_lag t
WHERE t.num = t.prev_num AND t.prev_num = T.prev_two_num;

-- solution
WITH table_with_lag AS (
	SELECT 
		*,
		LAG(num, 1) OVER(ORDER BY id) AS prev_num,
		LAG(num, 2) OVER(ORDER BY id) AS prev_two_num
	FROM Logs
)
SELECT DISTINCT num AS "ConsecutiveNums" 
FROM table_with_lag t
WHERE t.num = t.prev_num AND t.prev_num = T.prev_two_num;

-- another solution
SELECT *
FROM Logs l1
JOIN Logs l2 ON l1.id = l2.id - 1
JOIN Logs l3 ON l1.id = l3.id - 2;

SELECT *
FROM Logs l1
JOIN Logs l2 ON l1.id = l2.id - 1
JOIN Logs l3 ON l1.id = l3.id - 2
WHERE l1.num = l2.num AND l1.num = l3.num;


SELECT DISTINCT l1.num AS ConsecutiveNums
FROM Logs l1
JOIN Logs l2 ON l1.id = l2.id - 1
JOIN Logs l3 ON l1.id = l3.id - 2
WHERE l1.num = l2.num AND l1.num = l3.num;








