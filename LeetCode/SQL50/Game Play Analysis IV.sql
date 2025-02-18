CREATE TABLE Activity (
    player_id INT,
    device_id INT,
    event_date DATE,
    games_played INT,
    PRIMARY KEY (player_id, event_date)
);

INSERT INTO Activity (player_id, device_id, event_date, games_played) VALUES
(1, 2, '2016-03-01', 5),
(1, 2, '2016-03-02', 6),
(2, 3, '2017-06-25', 1),
(3, 1, '2016-03-02', 0),
(3, 4, '2018-07-03', 5);

-- solving
SELECT * 
FROM Activity
ORDER BY event_date

SELECT 
	player_id, 
	MIN(event_date) AS first_login_date
FROM Activity
GROUP BY player_id;

WITH FirstLogin AS (
    SELECT 
        player_id, 
        MIN(event_date) AS first_login_date
    FROM Activity
    GROUP BY player_id
)
SELECT *
FROM Activity A
JOIN FirstLogin F 
ON A.player_id = F.player_id ;

WITH FirstLogin AS (
    SELECT 
        player_id, 
        MIN(event_date) AS first_login_date
    FROM Activity
    GROUP BY player_id
)
SELECT *
FROM Activity A
JOIN FirstLogin F 
ON A.player_id = F.player_id 
WHERE A.event_date = F.first_login_date + INTERVAL '1 day';

WITH FirstLogin AS (
    SELECT 
        player_id, 
        MIN(event_date) AS first_login_date
    FROM Activity
    GROUP BY player_id
)
SELECT DISTINCT A.player_id
FROM Activity A
JOIN FirstLogin F 
ON A.player_id = F.player_id 
WHERE A.event_date = F.first_login_date + INTERVAL '1 day';

WITH FirstLogin AS (
    SELECT 
        player_id, 
        MIN(event_date) AS first_login_date
    FROM Activity
    GROUP BY player_id
),
NextDayLogin AS (
    SELECT DISTINCT A.player_id
    FROM Activity A
    JOIN FirstLogin F 
    ON A.player_id = F.player_id 
    WHERE A.event_date = F.first_login_date + INTERVAL '1 day'
)
SELECT 
    ROUND(COUNT(DISTINCT N.player_id) * 1.0 / COUNT(DISTINCT A.player_id), 2) AS fraction
FROM Activity A
LEFT JOIN NextDayLogin N ON A.player_id = N.player_id;

-- solution
WITH FirstLogin AS (
    SELECT 
        player_id, 
        MIN(event_date) AS first_login_date
    FROM Activity
    GROUP BY player_id
),
NextDayLogin AS (
    SELECT DISTINCT A.player_id
    FROM Activity A
    JOIN FirstLogin F 
    ON A.player_id = F.player_id 
    WHERE A.event_date = F.first_login_date + INTERVAL '1 day'
)
SELECT 
    ROUND(COUNT(DISTINCT N.player_id) * 1.0 / COUNT(DISTINCT A.player_id), 2) AS fraction
FROM Activity A
LEFT JOIN NextDayLogin N ON A.player_id = N.player_id;