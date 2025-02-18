CREATE TABLE Queries (
    query_name VARCHAR,
    result VARCHAR,
    position INT CHECK (position BETWEEN 1 AND 500),
    rating INT CHECK (rating BETWEEN 1 AND 5)
);

INSERT INTO Queries (query_name, result, position, rating) VALUES
('Dog', 'Golden Retriever', 1, 5),
('Dog', 'German Shepherd', 2, 5),
('Dog', 'Mule', 200, 1),
('Cat', 'Shirazi', 5, 2),
('Cat', 'Siamese', 3, 3),
('Cat', 'Sphynx', 7, 4);

SELECT 
	q.query_name, 
	ROUND(SUM(q.rating::DECIMAL / q.position) / COUNT(*), 2) as quality, -- can use AVG instead of SUM / COUNT
	ROUND(SUM(CASE WHEN q.rating < 3 THEN 1 ELSE 0 END)::DECIMAL / COUNT(*) * 100, 2) AS poor_query_percentage 
FROM Queries q
GROUP BY q.query_name
ORDER BY quality DESC;