create table emp_temp_rajibul
(
ecode number(3,0) primary key,
ename varchar(30),
dcode number(3,0),
basic number(8,2),
foreign key (dcode) references dept_temp_rajibul(dcode)
);

insert into emp_temp_rajibul values(1,'A',1,20000);
insert into emp_temp_rajibul values(2,'B',2,20000);
insert into emp_temp_rajibul values(3,'C',1,20000);
insert into emp_temp_rajibul values(4,'D',3,20000);

DECLARE
R emp_temp_rajibul%rowtype;
BEGIN
select * into r from emp_temp_rajibul where ecode=&ecode;
dbms_output.put_line(r.ename);
EXCEPTION
WHEN no_data_found THEN
dbms_output.put_line('No such employee found.');
END;
/


--2

create table dept_temp_rajibul
(
dcode number(3,0) primary key,
dname varchar(30)
;

insert into dept_temp_rajibul values(1,'Finance');
insert into dept_temp_rajibul values(2,'Technology');
insert into dept_temp_rajibul values(3,'Management');

DECLARE
ecodei emp_temp_rajibul.ecode%type;
enamei emp_temp_rajibul.ename%type;
dcodei emp_temp_rajibul.dcode%type;
basici emp_temp_rajibul.basic%type;
cnte number(3,0);
cntd number(3,0);
BEGIN
ecodei :=&ecodei;
enamei :='&enamei';
dcodei :=&dcodei;
basici :=&basici;
select count(*) into cnte from emp_temp_rajibul where ecode=ecodei;
select count(*) into cntd from dept_temp_rajibul where dcode=dcodei;
IF cnte=0 and cntd=1 THEN
insert into emp_temp_rajibul values(ecodei,enamei,dcodei,basici);
ELSE
    dbms_output.put_line('Invalid Data.');
END IF;
END
/

---3
select * from
(
select * from emp_temp_rajibul order by basic desc
)
where rownum<=5;

---4
DECLARE
cnt number(3,0);
dcodei emp_temp_rajibul.dcode%type;
BEGIN
dcodei:=&dcodei;
select count(*) into cnt from emp_temp_rajibul where dcode=dcodei;
delete from emp_temp_rajibul where dcode=dcodei;
dbms_output.put_line('Deleted number of users is');
dbms_output.put_line(TO_CHAR(cnt));
END;
/	

--5

declare
bidi book_rajibul.bid%type;
snoi book_rajibul.sno%type;
midi transaction_rajibul.mid%type;
type_transi transaction_rajibul.type_trans%type;
dti transaction_rajibul.dt_issue%type;
bki book_rajibul%rowtype;
mi member_rajibul%rowtype;
cnt_issue number(5,0);
cnt total number(5,0);
begin
bidi :=&bidi;
midi :=&midi;
type_transi :='&type_transi';
dti :='&dti';
