CREATE TABLE Users (
    user_id INT,
    user_name VARCHAR(255),
    PRIMARY KEY (user_id)
);

CREATE TABLE Register (
    contest_id INT,
    user_id INT,
    PRIMARY KEY (contest_id, user_id),
    FOREIGN KEY (user_id) REFERENCES Users(user_id)
);

INSERT INTO Users (user_id, user_name) VALUES
(6, 'Alice'),
(2, 'Bob'),
(7, 'Alex');

INSERT INTO Register (contest_id, user_id) VALUES
(215, 6),
(209, 2),
(208, 2),
(210, 6),
(208, 6),
(209, 7),
(209, 6),
(215, 7),
(208, 7),
(210, 2),
(207, 2),
(210, 7);

-- solution
SELECT 
    r.contest_id, 
    ROUND(COUNT(DISTINCT r.user_id) * 100.0 / (SELECT COUNT(*) FROM Users), 2) AS percentage
FROM Register r
GROUP BY r.contest_id
ORDER BY percentage DESC, contest_id ASC;

