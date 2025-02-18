CREATE TABLE Delivery (
    delivery_id INT PRIMARY KEY,
    customer_id INT,
    order_date DATE,
    customer_pref_delivery_date DATE
);

INSERT INTO Delivery (delivery_id, customer_id, order_date, customer_pref_delivery_date) VALUES
(1, 1, '2019-08-01', '2019-08-02'),
(2, 2, '2019-08-02', '2019-08-02'),
(3, 1, '2019-08-11', '2019-08-12'),
(4, 3, '2019-08-24', '2019-08-24'),
(5, 3, '2019-08-21', '2019-08-22'),
(6, 2, '2019-08-11', '2019-08-13'),
(7, 4, '2019-08-09', '2019-08-09');

-- solving
SELECT *
FROM Delivery;

SELECT 
	d.customer_id, 
	CASE WHEN d.order_date = d.customer_pref_delivery_date THEN 'immediate' ELSE 'scheduled' END AS delivery_status,
	RANK() OVER(PARTITION BY d.customer_id ORDER BY d.order_date) AS rnk
FROM Delivery d
ORDER BY order_date;

WITH new_table AS (
	SELECT 
		d.customer_id, 
		CASE WHEN d.order_date = d.customer_pref_delivery_date THEN 'immediate' ELSE 'scheduled' END AS delivery_status,
		RANK() OVER(PARTITION BY d.customer_id ORDER BY d.order_date) AS rnk
	FROM Delivery d
	ORDER BY order_date
)
SELECT ROUND(AVG(CASE WHEN delivery_status = 'immediate' THEN 1 ELSE 0 END) * 100, 2) AS immediate_percentage
FROM new_table n
WHERE rnk = 1

-- solution
WITH new_table AS (
	SELECT 
		d.customer_id, 
		CASE WHEN d.order_date = d.customer_pref_delivery_date THEN 'immediate' ELSE 'scheduled' END AS delivery_status,
		RANK() OVER(PARTITION BY d.customer_id ORDER BY d.order_date) AS rnk
	FROM Delivery d
	ORDER BY order_date
)
SELECT ROUND(AVG(CASE WHEN delivery_status = 'immediate' THEN 1 ELSE 0 END) * 100, 2) AS immediate_percentage
FROM new_table n
WHERE rnk = 1
