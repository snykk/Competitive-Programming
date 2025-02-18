CREATE TABLE Courses (
    student VARCHAR NOT NULL,
    class VARCHAR NOT NULL,
    PRIMARY KEY (student, class)
);

INSERT INTO Courses (student, class) VALUES
('A', 'Math'),
('B', 'English'),
('C', 'Math'),
('D', 'Biology'),
('E', 'Math'),
('F', 'Computer'),
('G', 'Math'),
('H', 'Math'),
('I', 'Math');

-- solving
SELECT * 
FROM Courses

-- solution
SELECT 
	class
FROM Courses
GROUP BY class
HAVING COUNT(*) >= 5;

WITH ClassCounts AS ( -- using CTE instead
    SELECT class, COUNT(*) AS student_count
    FROM Courses
    GROUP BY class
)
SELECT class
FROM ClassCounts
WHERE student_count >= 5;

