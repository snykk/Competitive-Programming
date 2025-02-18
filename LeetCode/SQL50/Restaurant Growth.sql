CREATE TABLE Customer (
    customer_id INT,
    name VARCHAR(255),
    visited_on DATE,
    amount INT,
    PRIMARY KEY (customer_id, visited_on)
);

INSERT INTO Customer (customer_id, name, visited_on, amount) VALUES
(1, 'Jhon', '2019-01-01', 100),
(2, 'Daniel', '2019-01-02', 110),
(3, 'Jade', '2019-01-03', 120),
(4, 'Khaled', '2019-01-04', 130),
(5, 'Winston', '2019-01-05', 110),
(6, 'Elvis', '2019-01-06', 140),
(7, 'Anna', '2019-01-07', 150),
(8, 'Maria', '2019-01-08', 80),
(9, 'Jaze', '2019-01-09', 110),
(1, 'Jhon', '2019-01-10', 130),
(3, 'Jade', '2019-01-10', 150);

-- solving
SELECT * FROM Customer

-- daily total
SELECT 
	visited_on,
	SUM(amount) AS total_amount
FROM 
	Customer
GROUP BY 
	visited_on
ORDER BY 
	

WITH DailyTotal AS (
    SELECT 
        visited_on,
        SUM(amount) AS total_amount
    FROM 
        Customer
    GROUP BY 
        visited_on
)
SELECT
	visited_on,
	SUM(total_amount) OVER (ORDER BY visited_on ROWS BETWEEN 6 PRECEDING AND CURRENT ROW) AS amount,
	ROUND(AVG(total_amount) OVER (ORDER BY visited_on ROWS BETWEEN 6 PRECEDING AND CURRENT ROW), 2) AS average_amount
FROM
	DailyTotal
				
-- solution		
WITH DailyTotal AS (
    SELECT 
        visited_on,
        SUM(amount) AS total_amount
    FROM 
        Customer
    GROUP BY 
        visited_on
),
MovingAverage AS (
    SELECT
        visited_on,
        SUM(total_amount) OVER (ORDER BY visited_on ROWS BETWEEN 6 PRECEDING AND CURRENT ROW) AS amount,
        ROUND(AVG(total_amount) OVER (ORDER BY visited_on ROWS BETWEEN 6 PRECEDING AND CURRENT ROW), 2) AS average_amount
    FROM
        DailyTotal
)
SELECT
    visited_on,
    amount,
    average_amount
FROM
    MovingAverage
WHERE
    visited_on >= (SELECT MIN(visited_on) FROM Customer) + INTERVAL '6 day'
ORDER BY
    visited_on;
