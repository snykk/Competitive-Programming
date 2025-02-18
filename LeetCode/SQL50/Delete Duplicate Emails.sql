CREATE TABLE Person (
    id SERIAL PRIMARY KEY,
    email VARCHAR(255) NOT NULL
);

INSERT INTO Person (email) VALUES
('john@example.com'),
('bob@example.com'),
('john@example.com');

-- solution
WITH duplicates AS (
    SELECT MIN(id) AS keep_id
    FROM Person
    GROUP BY email
)
DELETE FROM Person
WHERE id NOT IN (SELECT keep_id FROM duplicates);
