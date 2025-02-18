CREATE TABLE Movies (
    movie_id INT PRIMARY KEY,
    title VARCHAR(255) UNIQUE
);

CREATE TABLE Users (
    user_id INT PRIMARY KEY,
    name VARCHAR(255) UNIQUE
);

CREATE TABLE MovieRating (
    movie_id INT,
    user_id INT,
    rating INT,
    created_at DATE,
    PRIMARY KEY (movie_id, user_id),
    FOREIGN KEY (movie_id) REFERENCES Movies(movie_id),
    FOREIGN KEY (user_id) REFERENCES Users(user_id)
);

INSERT INTO Movies (movie_id, title) VALUES
(1, 'Avengers'),
(2, 'Frozen 2'),
(3, 'Joker');

INSERT INTO Users (user_id, name) VALUES
(1, 'Daniel'),
(2, 'Monica'),
(3, 'Maria'),
(4, 'James');

INSERT INTO MovieRating (movie_id, user_id, rating, created_at) VALUES
(1, 1, 3, '2020-01-12'),
(1, 2, 4, '2020-02-11'),
(1, 3, 2, '2020-02-12'),
(1, 4, 1, '2020-01-01'),
(2, 1, 5, '2020-02-17'),
(2, 2, 2, '2020-02-01'),
(2, 3, 2, '2020-03-01'),
(3, 1, 3, '2020-02-22'),
(3, 2, 4, '2020-02-25');

-- solving

SELECT * FROM movies;
SELECT * FROM users;
SELECT * FROM movierating;

-- user rate count
SELECT u.user_id, u.name, COUNT(*) AS user_rating_count
FROM MovieRating mr 
JOIN Users u
ON u.user_id = mr.user_id
GROUP BY u.user_id, u.name

-- movie avg rate in february 2020
SELECT m.movie_id, m.title, AVG(mr.rating) AS average_rate
FROM MovieRating mr 
JOIN Movies m
ON m.movie_id = mr.movie_id
WHERE EXTRACT(MONTH FROM created_at) = 2 AND EXTRACT(YEAR FROM created_at) = 2020
GROUP BY m.movie_id, m.title

-- solution
WITH with_user_rating_count AS (
    SELECT u.user_id, u.name, COUNT(*) AS user_rating_count
    FROM MovieRating mr 
    JOIN Users u ON u.user_id = mr.user_id
    GROUP BY u.user_id, u.name
),
with_avg_rate AS (
    SELECT m.movie_id, m.title, AVG(mr.rating) AS average_rate
    FROM MovieRating mr 
    JOIN Movies m ON m.movie_id = mr.movie_id
    WHERE EXTRACT(MONTH FROM created_at) = 2 AND EXTRACT(YEAR FROM created_at) = 2020
    GROUP BY m.movie_id, m.title
)
, top_user AS (
    SELECT wr.name
    FROM with_user_rating_count wr
    ORDER BY wr.user_rating_count DESC, wr.name ASC
    LIMIT 1
)
, top_movie AS (
    SELECT wa.title
    FROM with_avg_rate wa
    ORDER BY wa.average_rate DESC, wa.title ASC
    LIMIT 1
)
SELECT name AS results FROM top_user
UNION ALL
SELECT title AS results FROM top_movie;