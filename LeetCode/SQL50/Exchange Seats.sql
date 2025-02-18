CREATE TABLE Seat (
    id INT PRIMARY KEY,
    student VARCHAR(100)
);

INSERT INTO Seat (id, student) VALUES
(1, 'Abbot'),
(2, 'Doris'),
(3, 'Emerson'),
(4, 'Green'),
(5, 'Jeames');

-- solution
SELECT * FROM Seat

WITH Swapped AS (
    SELECT 
        CASE
            WHEN MOD(id, 2) = 1 AND id + 1 <= (SELECT MAX(id) FROM Seat) THEN id + 1
            WHEN MOD(id, 2) = 0 THEN id - 1
            ELSE id
        END AS new_id,
        student
    FROM Seat
)
SELECT new_id AS id, student
FROM Swapped
ORDER BY new_id;


