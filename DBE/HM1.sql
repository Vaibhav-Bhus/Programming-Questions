
use Assignment_1;

create Table student_info(
Stud_ID int,
Stud_Name varchar(205) not null,
Subject1_marks tinyint,
Subject2_marks tinyint,
Subject3_marks tinyint,
Subject4_marks tinyint,
age tinyint check(age > 18),
mobile_number varchar(20) unique,
primary key(Stud_ID),
);

insert into student_info values(1, 'Vaibhav Bhus', 87, 89, 74, 90, 20, '7719874955');
insert into student_info values(2, 'Kritika Kshirsagar', 90, 93, 91, 89, 19, '8605301437');

select * from student_info;