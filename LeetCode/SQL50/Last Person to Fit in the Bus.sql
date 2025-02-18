CREATE TABLE Queue (
    person_id INT PRIMARY KEY,
    person_name VARCHAR(100),
    weight INT,
    turn INT UNIQUE
);

INSERT INTO Queue (person_id, person_name, weight, turn) VALUES
(5, 'Alice', 250, 1),
(4, 'Bob', 175, 5),
(3, 'Alex', 350, 2),
(6, 'John Cena', 400, 3),
(1, 'Winston', 500, 6),
(2, 'Marie', 200, 4);

-- solving
SELECT * FROM Queue;

WITH CTE AS (
    SELECT person_name, weight, turn, 
           SUM(weight) OVER (ORDER BY turn) AS total_weight
    FROM Queue
)
SELECT person_name
FROM CTE
WHERE total_weight <= 1000
ORDER BY total_weight DESC
LIMIT 1;
