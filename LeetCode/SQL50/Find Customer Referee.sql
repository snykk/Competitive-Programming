CREATE TABLE Customer (
    id SERIAL PRIMARY KEY,
    name VARCHAR NOT NULL,
    referee_id INT
);

INSERT INTO Customer (id, name, referee_id) VALUES
(1, 'Will', NULL),
(2, 'Jane', NULL),
(3, 'Alex', 2),
(4, 'Bill', NULL),
(5, 'Zack', 1),
(6, 'Mark', 2);

-- solution
SELECT name 
FROM Customer
WHERE referee_id IS NULL OR referee_id != 2;