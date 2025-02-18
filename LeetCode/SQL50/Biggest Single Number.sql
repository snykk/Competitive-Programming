CREATE TABLE MyNumbers (
    num INT
);

INSERT INTO MyNumbers (num) VALUES
(8), (8), (3), (3), (1), (4), (5), (6);

-- solution
SELECT *
FROM MyNumbers;

SELECT MAX(num) AS num
FROM (
	SELECT num
		FROM MyNumbers
		GROUP BY num
		HAVING COUNT(*) = 1
) AS single_number