-- 2.Try to violate the constraints that you have implemented in the table & note, what happens. 
-- [Try with suitable INSERT/UPDATE/DELETE instruction] 



-- OPERATION SELECTED : INSERT

-- EMP INSERTION
-- -- VIOLATION : 1
INSERT INTO
    EMP (
        EMP_CODE,
        DEPT_CODE,
        EMP_NAME,
        ADDRESS,
        CITY,
        BASIC,
        GRADE
    )
VALUES
    (
        'EP025',
        'DT001',
        'Alpha',                -- VIOLATION : EMPLOYEE NAME SHOULD BE IN UPPERCASE
        'ALPHA STREET',
        'ALPHA CITY',
        7000,                  
        'A'
    );

-- -- VIOLATION : 2
INSERT INTO
    EMP (
        EMP_CODE,
        DEPT_CODE,
        EMP_NAME,
        ADDRESS,
        CITY,
        BASIC,
        GRADE
    )
VALUES
    (
        'EP026',
        'DT002',
        'ALPHA',
        'ALPHA STREET',
        'ALPHA CITY',
        10000,                  -- VIOLATION : BASIC SHOULD BE IN BETWEEN Rs 5000 AND Rs 9000
        'A'
    );

-- -- VIOLATION : 3
INSERT INTO
    EMP (
        EMP_CODE,
        DEPT_CODE,
        EMP_NAME,
        ADDRESS,
        CITY,
        BASIC,
        GRADE
    )
VALUES
    (
        'EP027',
        'DT003',
        'ALPHA',
        'ALPHA STREET',
        'ALPHA CITY',
        8000,                  
        'D'                    -- VIOLATION : GRADE SHOULD BE WITH THE VALUES OF 'A', 'B' AND 'C'
    );

-- LEAVE_REGISTER INSERTION
INSERT INTO
    LEAVE_REGISTER
VALUES
    (
        'ET001', 
        'EP001', 
        'TL',                  -- VIOLATION : LEAVE CATEGORY SHOULD BE WITHIN THE VALUES OF 'CL', 'EL' AND 'ML'
        '2022-04-12', 
        '2022-04-18'
    );
