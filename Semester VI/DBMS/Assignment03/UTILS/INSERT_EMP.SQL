-- +-----------+------------+------+-----+-------------------+-------------------+
-- | Field     | Type       | Null | Key | Default           | Extra             |
-- +-----------+------------+------+-----+-------------------+-------------------+
-- | EMP_CODE  | varchar(5) | NO   | PRI | NULL              |                   |
-- | DEPT_CODE | varchar(5) | YES  |     | NULL              |                   |
-- | EMP_NAME  | char(20)   | YES  |     | NULL              |                   |
-- | ADDRESS   | char(20)   | YES  |     | NULL              |                   |
-- | CITY      | char(20)   | YES  |     | NULL              |                   |
-- | BASIC     | int        | YES  |     | NULL              |                   |
-- | GRADE     | char(1)    | YES  |     | NULL              |                   |
-- | DT_JN     | timestamp  | YES  |     | CURRENT_TIMESTAMP | DEFAULT_GENERATED |
-- +-----------+------------+------+-----+-------------------+-------------------+
INSERT INTO
    EMP (EMP_CODE, DEPT_CODE, EMP_NAME, ADDRESS, CITY, BASIC, GRADE)
VALUES
    ('EP001',   'DT001',    'ALPHA',      'ALPHA STREET',     'ALPHA CITY',   5000, 'A'),
    ('EP002',   'DT002',    'BETA',       'BETA STREET',      'BETA CITY',    6500, 'B'),
    ('EP003',   'DT003',    'GAMMA',      'GAMMA STREET',     'GAMMA CITY',   7000, 'C'),
    ('EP004',   'DT004',    'DELTA',      'DELTA STREET',     'DELTA CITY',   8000, 'A'),
    ('EP005',   'DT005',    'EPSILON',    'EPSILON STREET',   'EPSILON CITY', 9000, 'B'),
    ('EP006',   'DT006',    'ZETA',       'ZETA STREET',      'ZETA CITY',    8500, 'C'),
    ('EP007',   'DT007',    'ETA',        'ALPHA STREET',     'ALPHA CITY',   7000, 'A'),
    ('EP008',   'DT008',    'THETA',      'ALPHA STREET',     'ALPHA CITY',   6000, 'B'),
    ('EP009',   'DT009',    'IOTA',       'ALPHA STREET',     'ALPHA CITY',   5500, 'C'),
    ('EP010',   'DT010',    'KAPPA',      'ALPHA STREET',     'ALPHA CITY',   6000, 'A'),
    ('EP011',   'DT011',    'LAMBDA',     'ALPHA STREET',     'ALPHA CITY',   7500, 'B'),
    ('EP012',   'DT012',    'MU',         'ALPHA STREET',     'ALPHA CITY',   8000, 'C'),
    ('EP013',   'DT013',    'NU',         'ALPHA STREET',     'ALPHA CITY',   9000, 'A'),
    ('EP014',   'DT014',    'XI',         'ALPHA STREET',     'ALPHA CITY',   8000, 'B'),
    ('EP015',   'DT015',    'OMICRON',    'ALPHA STREET',     'ALPHA CITY',   7500, 'C'),
    ('EP016',   'DT016',    'PI',         'ALPHA STREET',     'ALPHA CITY',   6000, 'A'),
    ('EP017',   'DT017',    'RHO',        'ALPHA STREET',     'ALPHA CITY',   5000, 'B'),
    ('EP018',   'DT018',    'SIGMA',      'ALPHA STREET',     'ALPHA CITY',   6000, 'C'),
    ('EP019',   'DT019',    'TAU',        'ALPHA STREET',     'ALPHA CITY',   7000, 'A'),
    ('EP020',   'DT020',    'UPSILON',    'ALPHA STREET',     'ALPHA CITY',   8000, 'B'),
    ('EP021',   'DT021',    'PHI',        'ALPHA STREET',     'ALPHA CITY',   9000, 'C'),
    ('EP022',   'DT022',    'CHI',        'ALPHA STREET',     'ALPHA CITY',   8500, 'A'),
    ('EP023',   'DT023',    'PSI',        'ALPHA STREET',     'ALPHA CITY',   7000, 'B'),
    ('EP024',   'DT024',    'OMEGA',      'ALPHA STREET',     'ALPHA CITY',   6000, 'C');