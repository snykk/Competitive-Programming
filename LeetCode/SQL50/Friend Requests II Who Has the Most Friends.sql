CREATE TABLE RequestAccepted (
    requester_id INT,
    accepter_id INT,
    accept_date DATE,
    PRIMARY KEY (requester_id, accepter_id)
);

INSERT INTO RequestAccepted (requester_id, accepter_id, accept_date)
VALUES
(1, 2, '2016-06-03'),
(1, 3, '2016-06-08'),
(2, 3, '2016-06-08'),
(3, 4, '2016-06-09');


-- solving
SELECT * fROM RequestAccepted

SELECT requester_id as user_id, COUNT(*) AS total_frient_from_request
fROM RequestAccepted
GROUP BY requester_id

SELECT accepter_id AS user_id, COUNT(*) AS total_friend_from_acceptant
fROM RequestAccepted
GROUP BY accepter_id

-- solution
WITH WithFromRequest AS (
	SELECT requester_id AS user_id, COUNT(*) AS total_friend_from_request
	fROM RequestAccepted
	GROUP BY requester_id
),
WithFromAcceptant AS (
	SELECT accepter_id AS user_id, COUNT(*) AS total_friend_from_acceptant
	fROM RequestAccepted
	GROUP BY accepter_id
)
SELECT
	COALESCE(fr.user_id, fa.user_id) AS id,
	COALESCE(fr.total_friend_from_request, 0) + COALESCE(fa.total_friend_from_acceptant, 0) AS num
FROM WithFromRequest fr
FULL OUTER JOIN WithFromAcceptant fa ON fr.user_id = fa.user_id
ORDER BY num DESC
LIMIT 1

-- solution 2
WITH WithFriendCounts AS (
    SELECT requester_id AS user_id, COUNT(DISTINCT accepter_id) AS friends_count
    FROM RequestAccepted
    GROUP BY requester_id
    UNION ALL
    SELECT accepter_id AS user_id, COUNT(DISTINCT requester_id) AS friends_count
    FROM RequestAccepted
    GROUP BY accepter_id
),
WithAggregatedCounts AS (
    SELECT user_id, SUM(friends_count) AS total_friends
    FROM WithFriendCounts
    GROUP BY user_id
)
SELECT user_id AS id, total_friends AS num
FROM WithAggregatedCounts
ORDER BY total_friends DESC
LIMIT 1;
