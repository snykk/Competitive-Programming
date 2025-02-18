CREATE TABLE Teacher (
    teacher_id INT,
    subject_id INT,
    dept_id INT,
    PRIMARY KEY (subject_id, dept_id)
);

INSERT INTO Teacher (teacher_id, subject_id, dept_id) VALUES
(1, 2, 3),
(1, 2, 4),
(1, 3, 3),
(2, 1, 1),
(2, 2, 1),
(2, 3, 1),
(2, 4, 1);

-- solution
SELECT t.teacher_id, COUNT(DISTINCT t.subject_id) as cnt
FROM Teacher t
GROUP BY t.teacher_id
ORDER BY t.teacher_id