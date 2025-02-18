CREATE TABLE Activities (
    sell_date DATE NOT NULL,
    product VARCHAR(255) NOT NULL
);

INSERT INTO Activities (sell_date, product) VALUES
('2020-05-30', 'Headphone'),
('2020-06-01', 'Pencil'),
('2020-06-02', 'Mask'),
('2020-05-30', 'Basketball'),
('2020-06-01', 'Bible'),
('2020-06-02', 'Mask'),
('2020-05-30', 'T-Shirt');

-- solution
SELECT * FROM Activities

SELECT 
	sell_date,
    COUNT(DISTINCT product) AS num_sold,
    STRING_AGG(DISTINCT product, ',' ORDER BY product) AS products
FROM Activities
GROUP BY sell_date
ORDER BY sell_date;
