CREATE TABLE Users (
    user_id INT PRIMARY KEY,
    name VARCHAR(255) NOT NULL,
    mail VARCHAR(255) NOT NULL
);

INSERT INTO Users (user_id, name, mail) VALUES
(1, 'Winston', 'winston@leetcode.com'),
(2, 'Jonathan', 'jonathanisgreat'),
(3, 'Annabelle', 'bella-@leetcode.com'),
(4, 'Sally', 'sally.come@leetcode.com'),
(5, 'Marwan', 'quarz#2020@leetcode.com'),
(6, 'David', 'david69@gmail.com'),
(7, 'Shapiro', '.shapo@leetcode.com');

-- solution
SELECT user_id, name, mail
FROM Users
WHERE mail LIKE '%@leetcode.com'
  AND mail ~ '^[A-Za-z][A-Za-z0-9._-]*@leetcode.com$';
