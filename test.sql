SELECT c1, c2 FROM t1;
DELETE FROM t2;

DROP INDEX stunameidx;

CREATE INDEX stunameidx ON student ( sname );

DROP TABLE student;

CREATE TABLE student (
		sno CHAR(8),
		sname CHAR(16) UNIQUE,
		sage INT,
		sgender CHAR (1),
		PRIMARY KEY ( sno )
);

SELECT * FROM student;
SELECT * FROM student WHERE sno = '88888888';
SELECT * FROM student WHERE sage > 20 AND sgender = 'F';

DELETE FROM student;
DELETE FROM student WHERE sno = '88888888';
