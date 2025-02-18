CREATE TABLE Patients (
    patient_id INT PRIMARY KEY,
    patient_name VARCHAR(255),
    conditions VARCHAR(255)
);

INSERT INTO Patients (patient_id, patient_name, conditions)
VALUES
(1, 'Daniel', 'YFEV COUGH'),
(2, 'Alice', ''),
(3, 'Bob', 'DIAB100 MYOP'),
(4, 'George', 'ACNE DIAB100'),
(5, 'Alain', 'DIAB201');

-- solution
SELECT patient_id, patient_name, conditions
FROM Patients
WHERE conditions ~ '(^| )DIAB1';


