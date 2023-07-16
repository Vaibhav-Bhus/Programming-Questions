
create table Worker(
Worker_ID tinyint,
First_Name varchar(20) not null,
Last_Name varchar(20) ,
Salary int check (salary>0),
Joining_Date smallDateTime default GETDATE(),
Department varchar(10) not null,
primary key(Worker_ID),
);

create table Bonus(
Worker_ID tinyint, 
Bonus_Date smalldatetime default GETDATE(),
Bonus_Amount int,
foreign key (Worker_ID) references Worker
);

create table Title(
Worker_ID tinyint,
Worker_Title varchar(20),
Working_From smalldatetime default GETDATE(),
foreign key (Worker_ID) references Worker
);


insert into Worker values(1, 'Dipali', 'Khadke', 50000,default,'QA');
insert into Worker values(2, 'Aniket', 'Muley', 25000,default,'TS');
insert into Worker values(3, 'Kritika', 'Kshirsagar', 60000,default,'HR');
insert into Worker values(4, 'Vaibhav', 'Bhus', 45000,default,'HR');
insert into Worker values(5, 'Aarti', 'Nemane', 30000,default,'Sales');
insert into Worker values(6, 'Disha', 'Arora', 75000,default,'IT Services');
insert into Worker values(7, 'Honeypreet', 'Mehta', 43000,default,'IT Services');
insert into Worker values(8, 'Nikita', 'Bobade', 58000,default,'TL');
insert into Worker values(9, 'Harshad', 'Devidas', 44000,default,'TS');
insert into Worker values(10, 'Ashwini', 'Pable', 60000,default,'QA');


insert into Bonus values(1, default,5000);
insert into Bonus values(2, default,4500);
insert into Bonus values(3, default,6000);
insert into Bonus values(4, default,6000);
insert into Bonus values(5, default,6000);
insert into Bonus values(6, default,6000);
insert into Bonus values(7, default,6000);
insert into Bonus values(8, default,6000);
insert into Bonus values(9, default,6000);
insert into Bonus values(10, default,6000);


insert into Title values(1, 'Manager',default);
insert into Title values(2, 'Developer',default);
insert into Title values(3, 'Database analyst',default);
insert into Title values(4, 'Database analyst',default);
insert into Title values(5, 'Database analyst',default);
insert into Title values(6, 'Database analyst',default);
insert into Title values(7, 'Database analyst',default);
insert into Title values(8, 'Back-End Developer',default);
insert into Title values(9, 'Front-End Developer',default);
insert into Title values(10, 'Manager',default);



select * from Worker;
select * from Bonus;
select * from Title;


select * from Worker where salary > 50000;

select * from Worker order by Salary;

SELECT *FROM Worker WHERE First_Name LIKE '%i_%';