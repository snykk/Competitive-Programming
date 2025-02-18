CREATE TABLE Insurance (
    pid INT PRIMARY KEY,
    tiv_2015 FLOAT,
    tiv_2016 FLOAT,
    lat FLOAT,
    lon FLOAT
);

INSERT INTO Insurance (pid, tiv_2015, tiv_2016, lat, lon)
VALUES
(1, 10, 5, 10, 10),
(2, 20, 20, 20, 20),
(3, 10, 30, 20, 20),
(4, 10, 40, 40, 40);

-- solving
SELECT * FROM Insurance

SELECT 
	pid, tiv_2015, tiv_2016, lat || '-' || lon AS loc
FROM 
	Insurance

-- solution
WITH Loc AS (
	SELECT 
		pid, tiv_2015, tiv_2016, lat || '-' || lon AS loc
	FROM 
		Insurance
)
SELECT 
	ROUND(SUM(l1.tiv_2016)::DECIMAL, 2) AS tiv_2016
FROM
	Loc l1
WHERE 
	1 = (SELECT COUNT(*) FROM Loc l2 WHERE l2.loc = l1.loc) AND
	(SELECT COUNT(*) FROM Loc l3 WHERE l3.tiv_2015 = l1.tiv_2015) > 1
