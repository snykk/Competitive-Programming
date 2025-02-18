CREATE TABLE Transactions (
    id INT PRIMARY KEY,
    country VARCHAR,
    state ENUM('approved', 'declined'),
    amount INT,
    trans_date DATE
);

INSERT INTO Transactions (id, country, state, amount, trans_date) VALUES
(121, 'US', 'approved', 1000, '2018-12-18'),
(122, 'US', 'declined', 2000, '2018-12-19'),
(123, 'US', 'approved', 2000, '2019-01-01'),
(124, 'DE', 'approved', 2000, '2019-01-07');

-- solution
WITH new_table AS (
	SELECT 
		t.id,
		t.country,
		t.state,
		t.amount,
		CASE WHEN state = 'approved' THEN amount ELSE NULL END AS approved_amount,
		TO_CHAR(t.trans_date, 'YYYY-MM') AS year_and_mount
	FROM Transactions t
)
SELECT
	year_and_mount as month,
	country AS country,
	COUNT(*) AS trans_count,
	COUNT(approved_amount) AS approved_count,
	SUM(amount) AS trans_total_amount,
	COALESCE(SUM(approved_amount), 0) AS approved_total_amount
FROM new_table
GROUP BY year_and_mount, country