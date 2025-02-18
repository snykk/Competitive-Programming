CREATE TABLE Product (
    product_key INT PRIMARY KEY
);

CREATE TABLE Customer (
    customer_id INT NOT NULL,
    product_key INT NOT NULL,
    FOREIGN KEY (product_key) REFERENCES Product(product_key)
);

INSERT INTO Product (product_key) VALUES 
(5), 
(6);

INSERT INTO Customer (customer_id, product_key) VALUES 
(1, 5),
(2, 6),
(3, 5),
(3, 6),
(1, 6);

-- solving
SELECT * FROM Customer;

SELECT * FROM Product;

SELECT 
	*
FROM Customer C
JOIN Product P ON C.product_key = P.product_key

SELECT 
	customer_id,
	COUNT(DISTINCT C.product_key),
	(SELECT COUNT(*) FROM Product)
FROM Customer C
JOIN Product P ON C.product_key = P.product_key
GROUP BY customer_id

-- solution
SELECT customer_id
FROM Customer C
JOIN Product P ON C.product_key = P.product_key
GROUP BY customer_id
HAVING COUNT(DISTINCT C.product_key) = (SELECT COUNT(*) FROM Product);
