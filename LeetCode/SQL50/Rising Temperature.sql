CREATE TABLE Weather (
    id INT PRIMARY KEY,
    recordDate DATE,
    temperature INT
);

INSERT INTO Weather (id, recordDate, temperature) VALUES
(1, '2015-01-01', 10),
(2, '2015-01-02', 25),
(3, '2015-01-03', 20),
(4, '2015-01-04', 30);

-- solution
SELECT w1.id
FROM Weather w1
JOIN Weather w2
ON  
WHERE w1.temperature > w2.temperature;

-- using LAG
SELECT Id
FROM (
    SELECT id, recordDate, temperature,
           LAG(recordDate) OVER (ORDER BY recordDate) AS prev_date,
           LAG(temperature) OVER (ORDER BY recordDate) AS prev_temp
    FROM Weather
) w
WHERE recordDate = prev_date + INTERVAL '1 day'
AND temperature > prev_temp;
