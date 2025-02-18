CREATE TABLE Products (
    product_id INT NOT NULL,
    new_price INT NOT NULL,
    change_date DATE NOT NULL,
    PRIMARY KEY (product_id, change_date)
);

INSERT INTO Products (product_id, new_price, change_date) VALUES
(1, 20, '2019-08-14'),
(2, 50, '2019-08-14'),
(1, 30, '2019-08-15'),
(1, 35, '2019-08-16'),
(2, 65, '2019-08-17'),
(3, 20, '2019-08-18');

-- solving
SELECT * FROM Products

SELECT * FROM Products
WHERE change_date <= '2019-08-16'

SELECT product_id, MAX(change_date) AS newest_change_date FROM Products
WHERE change_date <= '2019-08-16'
GROUP BY product_id;

WITH with_newest_change_date AS (
	SELECT product_id, MAX(change_date) AS newest_change_date FROM Products
		WHERE change_date <= '2019-08-16'
		GROUP BY product_id
), 
with_newest_price AS (
	SELECT p.product_id, new_price AS newest_price
		FROM Products p
		LEFT JOIN with_newest_change_date wn
		ON p.product_id = wn.product_id
		WHERE p.change_date = wn.newest_change_date
)
SELECT 
	p.product_id,
	COALESCE(wp.newest_price, 10) AS price
FROM Products p
LEFT JOIN with_newest_price wp
ON p.product_id = wp.product_id
GROUP BY p.product_id, wp.newest_price
ORDER BY product_id

-- solution
WITH with_newest_change_date AS (
	SELECT product_id, MAX(change_date) AS newest_change_date FROM Products
		WHERE change_date <= '2019-08-16'
		GROUP BY product_id
), 
with_newest_price AS (
	SELECT p.product_id, new_price AS newest_price
		FROM Products p
		LEFT JOIN with_newest_change_date wn
		ON p.product_id = wn.product_id
		WHERE p.change_date = wn.newest_change_date
)
SELECT 
	p.product_id,
	COALESCE(wp.newest_price, 10) AS price
FROM Products p
LEFT JOIN with_newest_price wp
ON p.product_id = wp.product_id
GROUP BY p.product_id, wp.newest_price
ORDER BY product_id

-- best practice using RANK
WITH with_rank AS (
    SELECT 
        product_id, 
        new_price,
        change_date,
        RANK() OVER (PARTITION BY product_id ORDER BY change_date DESC) AS rnk
    FROM Products
    WHERE change_date <= '2019-08-16'
)
SELECT 
    p.product_id, 
    COALESCE(wr.new_price, 10) AS price
FROM (SELECT DISTINCT product_id FROM Products) p
LEFT JOIN with_rank wr ON p.product_id = wr.product_id AND wr.rnk = 1;