-- INSERT INTO DESIGNATION
INSERT INTO
    DESIGNATION
VALUES
    ('DSG01', 'Manager'),
    ('DSG02', 'Executive'),
    ('DSG03', 'Officer'),
    ('DSG04', 'Clerk'),
    ('DSG05', 'Helper');

CREATE TABLE DESIGNATION(
    DESIG_CODE CHAR(5) PRIMARY KEY,
    DESIG_DESC CHAR(20)
);