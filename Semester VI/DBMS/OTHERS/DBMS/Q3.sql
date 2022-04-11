CREATE TABLE DEPT_AS3(
	DEPT_CODE CHAR(6) PRIMARY KEY,
	DEPT_NAME CHAR(15)
);

create table Employee_29(
code char(4) primary key,
name varchar2(50) check(upper(name)=name),
addr varchar2(150),
city varchar2(20),
basic number not null check(basic>=5000 and basic <=9000),
grade char(1) not null check(grade in('A','B','C')),
dt_join date default(sysdate),
dept_code char(4),
foreign key(dept_code) references department29(code)
);

create table leave_register29 (
code char(4) primary key,
emp_code char(4),
start_date date,
end_date date,
leave_type char(1) not null check(leave_type in('cl','el','ml')),
foreign key (emp_code) references Employee_29(code) on delete cascade
);
--2
INSERT INTO Employee_29 VALUES('EMP1','Pulak','DPT1','KOLKATA-97',6000,'C','1-JUL-2011');
INSERT INTO Employee_29 VALUES('EMP2','Raj','DPT2','KOLKATA-91',6720,'C','1-JUL-2011');
INSERT INTO Employee_29 VALUES('EMP3','Aryapriyo','DPT4','KOLKATA-59',7800,'C','1-JUL-2011');
INSERT INTO Employee_29 VALUES('EMP4','AVILASH','DPT3','KOLKATA-17',5600,'C','1-JUL-2011');
INSERT INTO Employee_29 VALUES('EMP5','Arijit','DPT2','KOLKATA-07',8900,'C','1-JUL-2011');
--3

create table t1 as(
select code,name,dept_name,basic from Employee_29 e
inner join department29 d on e.dept_code=d.code
where basic=7000
);
commit;
alter table t1
add net_pay number;

update table t1
set net_pay=1.5*basic;
commit;

alter table t1
drop column net_pay;

--5


 