CREATE TABLE Users (
    user_id INT PRIMARY KEY,
    name VARCHAR(100)
);

INSERT INTO Users (user_id, name)
VALUES
(1, 'aLice'),
(2, 'bOB');

-- solution
SELECT 
    user_id, 
    CONCAT(UPPER(LEFT(name, 1)), LOWER(SUBSTRING(name, 2))) AS name
FROM Users
ORDER BY user_id;
