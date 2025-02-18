CREATE TABLE Accounts (
    account_id INT PRIMARY KEY,
    income INT
);

INSERT INTO Accounts (account_id, income) VALUES
(3, 108939),
(2, 12747),
(8, 87709),
(6, 91796);

-- solving
SELECT * FROM Accounts

SELECT 
	*,
	is_low,
	is_average,
	is_high
FROM Accounts

SELECT 
	*,
	CASE WHEN income < 20000 
		THEN 'Low Salary' 
		ELSE 
			CASE WHEN income <= 50000
				THEN 'Average Salary'
				ELSE 
					'High Salary'
			END
	END AS category
FROM Accounts a;

SELECT 'Low Salary' AS category
UNION ALL
SELECT 'Average Salary'
UNION ALL
SELECT 'High Salary';

-- solution

WITH with_category AS (
    SELECT 
        account_id,
        CASE WHEN income < 20000 
            THEN 'Low Salary' 
            ELSE 
                CASE WHEN income <= 50000
                    THEN 'Average Salary'
                    ELSE 
                        'High Salary'
                END
        END AS category
    FROM Accounts
),
category_list AS (
    SELECT 'Low Salary' AS category
    UNION ALL
    SELECT 'Average Salary'
    UNION ALL
    SELECT 'High Salary'
)
SELECT c.category, 
       COALESCE(COUNT(w.account_id), 0) AS accounts_count
FROM category_list c
LEFT JOIN with_category w ON c.category = w.category
GROUP BY c.category
ORDER BY c.category;



