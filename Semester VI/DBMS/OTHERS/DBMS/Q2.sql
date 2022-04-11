--1

select dept_code, min(basic),max(basic),avg(basic) from EMP_rajibul group by dept_code;

--2

select dept_code,count(*) from EMP_rajibul where sex='F' group by dept_code;

--3

select dept_code,city,count(*) from EMP_rajibul group by dept_code,city;

--4
select dept_code,count(*) from EMP_rajibul where substr(jn_dt,8,2)='00'
group by dept_code order by count(*);

--5

select dept_code, sum(basic) from EMP_rajibul group by dept_code having sum(basic)>5000 order by sum(basic) desc;

--6

select emp_name, desig_desc,basic from EMP_rajibul join designation_rajibul on EMP_rajibul.design_code=designation_rajibul.design_code;

--7

select emp_name,desig_desc,dept_name,basic from EMP_rajibul,designation_rajibul, department_rajibul 
where EMP_rajibul.design_code=designation_rajibul.design_code and EMP_rajibul.dept_code=department_rajibul.dept_code;

--8 

select dept_code from department_rajibul minus select distinct(dept_code) from EMP_rajibul;

--9

select distinct(dept_name) from EMP_rajibul join department_rajibul on 
EMP_rajibul.dept_code=department_rajibul.dept_code;

--10

select dept_name, count(*) from EMP_rajibul,department_rajibul where 
EMP_rajibul.dept_code=department_rajibul.dept_code;

--11
select * from
(
select dept_code from EMP_rajibul order by basic desc
)
where rownum=1;

--12

select * from
(
select desig_desc from EMP_rajibul,designation_rajibul
 where EMP_rajibul.design_code=designation_rajibul.desig_code order by basic desc
)

where rownum=1;

--13
select dept_name,count(*) from EMP_rajibul,designation_rajibul,department_rajibul where EMP_rajibul.design_code
=designation_rajibul.desig_code and EMP_rajibul.dept_code=department_rajibul.dept_code and desig_desc='Manager' group by dept_name;

--14
select * from
(
select basic from EMP_rajibul order by basic desc
)
where rownum=1;

--15
select * from
(
select basic from EMP_rajibul order by basic
)
where rownum=1;

--16
select * from
(
select dept_name,sum(basic) from EMP_rajibul,department_rajibul where
EMP_rajibul.dept_code=department_rajibul.dept_code group by dept_name order by sum(basic) desc
)
where rownum=1;

--17
insert into EMP_rajibul values('E9','jhilik','DP9','DS9','F','High Road','kolkata','700018','WB','10000','1-Mar-2022');

--18
delete from EMP_rajibul where design_code not in(select desig_code from EMP_rajibul);

--19
select emp_name from EMP_rajibul natural join
(
select avg(basic) as avg_basic, dept_code from EMP_rajibul group by dept_code
)where basic>avg_basic and sex='F';

--20

select count(*) from EMP_rajibul,designation_rajibul where EMP_rajibul.design_code=designation_rajibul.desig_code and desig_desc='Manager' and sex='F';