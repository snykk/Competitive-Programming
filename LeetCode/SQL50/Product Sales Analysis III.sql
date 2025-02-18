CREATE TABLE Product (
    product_id INT PRIMARY KEY,
    product_name VARCHAR(100)
);

CREATE TABLE Sales (
    sale_id INT PRIMARY KEY,
    product_id INT,
    year INT,
    quantity INT,
    price INT,
    FOREIGN KEY (product_id) REFERENCES Product (product_id)
);

INSERT INTO Product (product_id, product_name)
VALUES 
(100, 'Nokia'),
(200, 'Apple'),
(300, 'Samsung');

INSERT INTO Sales (sale_id, product_id, year, quantity, price)
VALUES 
(1, 100, 2008, 10, 5000),
(2, 100, 2009, 12, 5000),
(7, 200, 2011, 15, 9000),
(8, 200, 2012, 20, 9000),
(10, 300, 2015, 30, 10000);


-- solution
WITH RankedSales AS (
    SELECT 
        product_id, 
        year,
        quantity, 
        price,
        RANK() OVER (PARTITION BY product_id ORDER BY year ASC) AS rnk
    FROM Sales
)
SELECT product_id, year as first_year, quantity, price
FROM RankedSales
WHERE rnk = 1;
