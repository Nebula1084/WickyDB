select c1, c2 from t1;
delete from t2;

drop index stunameidx;

create index stunameidx on student ( sname );

drop table student;

create table student (
		sno char(8),
		sname char(16) unique,
		sage int,
		sgender char (1),
		primary key ( sno )
);

select * from student;
select * from student where sno = '88888888';
select * from student where sage > 20.1 and sgender = 'FF';

delete from student;
delete from student where sno = '88888888';

insert into student values ('12345678','wy',22,'M);