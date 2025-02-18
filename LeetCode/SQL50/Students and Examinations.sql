CREATE TABLE Students (
    student_id INT PRIMARY KEY,
    student_name VARCHAR
);

CREATE TABLE Subjects (
    subject_name VARCHAR PRIMARY KEY
);

CREATE TABLE Examinations (
    student_id INT,
    subject_name VARCHAR,
    FOREIGN KEY (student_id) REFERENCES Students(student_id),
    FOREIGN KEY (subject_name) REFERENCES Subjects(subject_name)
);

INSERT INTO Students (student_id, student_name) VALUES
(1, 'Alice'),
(2, 'Bob'),
(13, 'John'),
(6, 'Alex');

INSERT INTO Subjects (subject_name) VALUES
('Math'),
('Physics'),
('Programming');

INSERT INTO Examinations (student_id, subject_name) VALUES
(1, 'Math'),
(1, 'Physics'),
(1, 'Programming'),
(2, 'Programming'),
(1, 'Physics'),
(1, 'Math'),
(13, 'Math'),
(13, 'Programming'),
(13, 'Physics'),
(2, 'Math'),
(1, 'Math');

-- solution
SELECT st.student_id, st.student_name, sb.subject_name, COUNT(ex.student_id) AS attended_exams
FROM Students st
CROSS JOIN Subjects sb
LEFT JOIN Examinations ex
    ON st.student_id = ex.student_id AND ex.subject_name = sb.subject_name
GROUP BY sb.subject_name, st.student_name, st.student_id
ORDER BY st.student_id, sb.subject_name 