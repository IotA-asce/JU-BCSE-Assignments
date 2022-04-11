create table EMP_rajibul
 (
 emp_code varchar(5)
 ,
 emp_name varchar(20),
 dept_code varchar(5),
 design_code varchar(5),
 sex varchar(1),
 address varchar(25),
 city varchar(20),
 state varchar(20),
 pin varchar(6),
 basic number(8,3),
jn_dt date
);
create table designation_rajibul (
desig_Code varchar(5) primary key,
desig_desc varchar(20)
);

create Table department_rajibul (
dept_code varchar(5) primary key,
Dept_name varchar(15)

);

--2

describe EMP_rajibul;
describe department_rajibul;
describe department_rajibul;

insert into department_rajibul values
          ('DP1','teacher');
insert into department_rajibul values
          ('DP2' 'student');
insert into department_rajibul values
          ('DP3','class');
insert into department_rajibul values
          ('DP4' 'clerk');
		  
insert into designation_rajibul values
          ('DS1','Manager');
insert into designation_rajibul values
          ('DS2','Executive');
insert into designation_rajibul values
          ('DS3','helper');
insert into designation_rajibul values
          ('DS4','Finance');

--3
		  
insert into EMP_rajibul values('E1','Ram','DP1','DS1','M','garfa',
'kolkata','WB','700075','1000','17-Feb-2022');
insert into EMP_rajibul values('E2','shyam','DP2','DS2','M','jadavpur',
'kolkata','WB','700076','2000','16-Feb-2022');
insert into EMP_rajibul values('E3','jodu','DP3','DS3','M','sulekha',
'kolkata','WB','700077','3000','15-Feb-2022');
insert into EMP_rajibul values('E4','Sonali','DP4','DS4','F','garia',
'kolkata','WB','700078','6000','14-Feb-2022');
insert into EMP_rajibul values('E5','Rupali','DP4','DS5','F','garia',
'kolkata','WB','700078','3500','14-Feb-2022');
--4
insert into EMP_rajibul values('E6','priya',NULL,'DS6','F','patuli',
'kolkata','WB','700074',NULL,'10-Feb-2022');
insert into EMP_rajibul values('E7','Tina',NULL,'DS7','F','Baruipur',
'kolkata','WB','700073',NULL,'11-Feb-2022');
insert into EMP_rajibul values('E8','shreya',NULL,'DS8','F','sealdah',
'kolkata','WB','700074',NULL,'14-Feb-2022');


--5

select * from EMP_rajibul where dept_code is null;

--6
select * from EMP_rajibul where basic = 0;

--7
select * from EMP_rajibul where basic is null;

--8
select avg(basic) from EMP_rajibul;

--9
update EMP_rajibul set basic=0 where basic is null;

--10
select avg(basic) from EMP_rajibul;

--11
delete from EMP_rajibul where dept_code is null;

--12
select emp_name,basic*1.9 as Net_pay from EMP_rajibul;

--13
select upper(emp_name), basic from EMP_rajibul order by dept_code;

--14
select * from EMP_rajibul where jn_dt>'1-JAN-1990';

--15
select count(*) from EMP_rajibul where substr(jn_dt,4,3)='JAN';

--16
select max(basic),min(basic) from EMP_rajibul;

--17
select * from  EMP_rajibul where sex='F';

--18
update EMP_rajibul set city =upper(city);

--19
select count(distinct city) from EMP_rajibul;

--20
select * from EMP_rajibul order by dept_code, basic desc;
