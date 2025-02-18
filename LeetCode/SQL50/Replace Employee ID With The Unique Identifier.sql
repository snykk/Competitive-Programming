CREATE TABLE Employees (
    id INT PRIMARY KEY,
    name VARCHAR
);

CREATE TABLE EmployeeUNI (
    id INT,
    unique_id INT,
    PRIMARY KEY (id, unique_id)
);

INSERT INTO Employees (id, name) VALUES
(1, 'Alice'),
(7, 'Bob'),
(11, 'Meir'),
(90, 'Winston'),
(3, 'Jonathan');

INSERT INTO EmployeeUNI (id, unique_id) VALUES
(3, 1),
(11, 2),
(90, 3);


-- solution
SELECT emu.unique_id, em.name
FROM Employees as em
LEFT JOIN EmployeeUni as emu ON em.id = emu.id
