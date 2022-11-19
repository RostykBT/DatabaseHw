-- kustutame olemasolevad tabelid
drop table grade;
drop table subject;
drop table student;

-- loome tabelid
-- grade
create table grade(
id_grade	serial not null primary key,
id_subject		serial not null,
student_code	numeric(6),
grade		numeric(1)
);

do
$do$
begin
for i in 1..250 loop
insert into grade(id_subject,student_code,grade) values 
(
	(SELECT id_subject FROM subject ORDER BY RANDOM() LIMIT 1),	
	(SELECT student_code FROM student ORDER BY RANDOM() LIMIT 1),
	random() * 5
);
end loop;
end
$do$;

--subject
create table subject(
id_subject		serial not null primary key,
credits		numeric(1),
subject_code	varchar(7),
name		varchar(32), 
teacher	varchar(32)
);

insert into subject(credits,subject_code,name,teacher) values (6, 'aaa4199', 'Füüsika', 'Ivari Vesik');
insert into subject(credits,subject_code,name,teacher) values (5, 'sdf2344', 'Diskreetne matemaatika', 'Kalle Oja');
insert into subject(credits,subject_code,name,teacher) values (4, 'abb3443', 'Programmeerimine', 'Gustav Masing');
insert into subject(credits,subject_code,name,teacher) values (3, 'vbc3321', 'Digitaalsüsteemid', 'Evert Kross');
insert into subject(credits,subject_code,name,teacher) values (4, 'kks3004', 'Arvutiarhitektuurid', 'Arnold Viiding');
insert into subject(credits,subject_code,name,teacher) values (2, 'cyb3332', 'Krüptoloogia', 'Priidu Magi');
insert into subject(credits,subject_code,name,teacher) values (2, 'fin6064', 'Finantsjuhtimine', 'Luule Vaher');

--student
create table student
(
  student_code numeric(6,0) NOT NULL,
  first_name character varying(32),
  last_name character varying(32),
  birthdate date,
  average_grade numeric(3,2)
)
  
insert into student values ((select max(student_code) from student)+ trunc(random()*100), 'Sven', 'Keskula',    ((TO_DATE('01-JAN-1990','DD-MON-YYYY') + trunc(random() * 365) * '1 day'::interval + trunc(random() * 5) * '1 year'::interval)), mod(trunc((random() * 10)::numeric, 2), 4) + 1);
insert into student values ((select max(student_code) from student)+ trunc(random()*100), 'Reio', 'Aavik',      ((TO_DATE('01-JAN-1990','DD-MON-YYYY') + trunc(random() * 365) * '1 day'::interval + trunc(random() * 5) * '1 year'::interval)), mod(trunc((random() * 10)::numeric, 2), 4) + 1);
insert into student values ((select max(student_code) from student)+ trunc(random()*100), 'Paavo', 'Meri',      ((TO_DATE('01-JAN-1990','DD-MON-YYYY') + trunc(random() * 365) * '1 day'::interval + trunc(random() * 5) * '1 year'::interval)), mod(trunc((random() * 10)::numeric, 2), 4) + 1);
insert into student values ((select max(student_code) from student)+ trunc(random()*100), 'Kaur', 'Valk',       ((TO_DATE('01-JAN-1990','DD-MON-YYYY') + trunc(random() * 365) * '1 day'::interval + trunc(random() * 5) * '1 year'::interval)), mod(trunc((random() * 10)::numeric, 2), 4) + 1);
insert into student values ((select max(student_code) from student)+ trunc(random()*100), 'Leevi', 'Pihlak',    ((TO_DATE('01-JAN-1990','DD-MON-YYYY') + trunc(random() * 365) * '1 day'::interval + trunc(random() * 5) * '1 year'::interval)), mod(trunc((random() * 10)::numeric, 2), 4) + 1);
insert into student values ((select max(student_code) from student)+ trunc(random()*100), 'Veljo', 'Kuusk',     ((TO_DATE('01-JAN-1990','DD-MON-YYYY') + trunc(random() * 365) * '1 day'::interval + trunc(random() * 5) * '1 year'::interval)), mod(trunc((random() * 10)::numeric, 2), 4) + 1);
insert into student values ((select max(student_code) from student)+ trunc(random()*100), 'Kajar', 'Ruutel',    ((TO_DATE('01-JAN-1990','DD-MON-YYYY') + trunc(random() * 365) * '1 day'::interval + trunc(random() * 5) * '1 year'::interval)), mod(trunc((random() * 10)::numeric, 2), 4) + 1);
insert into student values ((select max(student_code) from student)+ trunc(random()*100), 'Anti', 'Pihlak',     ((TO_DATE('01-JAN-1990','DD-MON-YYYY') + trunc(random() * 365) * '1 day'::interval + trunc(random() * 5) * '1 year'::interval)), mod(trunc((random() * 10)::numeric, 2), 4) + 1);
insert into student values ((select max(student_code) from student)+ trunc(random()*100), 'Robin', 'Meri',      ((TO_DATE('01-JAN-1990','DD-MON-YYYY') + trunc(random() * 365) * '1 day'::interval + trunc(random() * 5) * '1 year'::interval)), mod(trunc((random() * 10)::numeric, 2), 4) + 1);
insert into student values ((select max(student_code) from student)+ trunc(random()*100), 'Kustav', 'Mark',     ((TO_DATE('01-JAN-1990','DD-MON-YYYY') + trunc(random() * 365) * '1 day'::interval + trunc(random() * 5) * '1 year'::interval)), mod(trunc((random() * 10)::numeric, 2), 4) + 1);
insert into student values ((select max(student_code) from student)+ trunc(random()*100), 'Ivari', 'Eenpalu',   ((TO_DATE('01-JAN-1990','DD-MON-YYYY') + trunc(random() * 365) * '1 day'::interval + trunc(random() * 5) * '1 year'::interval)), mod(trunc((random() * 10)::numeric, 2), 4) + 1);
insert into student values ((select max(student_code) from student)+ trunc(random()*100), 'Andrus', 'Kangro',   ((TO_DATE('01-JAN-1990','DD-MON-YYYY') + trunc(random() * 365) * '1 day'::interval + trunc(random() * 5) * '1 year'::interval)), mod(trunc((random() * 10)::numeric, 2), 4) + 1);
insert into student values ((select max(student_code) from student)+ trunc(random()*100), 'Kaspar', 'Masing',   ((TO_DATE('01-JAN-1990','DD-MON-YYYY') + trunc(random() * 365) * '1 day'::interval + trunc(random() * 5) * '1 year'::interval)), mod(trunc((random() * 10)::numeric, 2), 4) + 1);
insert into student values ((select max(student_code) from student)+ trunc(random()*100), 'Eedu', 'Mitt',       ((TO_DATE('01-JAN-1990','DD-MON-YYYY') + trunc(random() * 365) * '1 day'::interval + trunc(random() * 5) * '1 year'::interval)), mod(trunc((random() * 10)::numeric, 2), 4) + 1);
insert into student values ((select max(student_code) from student)+ trunc(random()*100), 'Aadu', 'Puhvel',     ((TO_DATE('01-JAN-1990','DD-MON-YYYY') + trunc(random() * 365) * '1 day'::interval + trunc(random() * 5) * '1 year'::interval)), mod(trunc((random() * 10)::numeric, 2), 4) + 1);
insert into student values ((select max(student_code) from student)+ trunc(random()*100), 'Mait', 'Lepmets',    ((TO_DATE('01-JAN-1990','DD-MON-YYYY') + trunc(random() * 365) * '1 day'::interval + trunc(random() * 5) * '1 year'::interval)), mod(trunc((random() * 10)::numeric, 2), 4) + 1);
insert into student values ((select max(student_code) from student)+ trunc(random()*100), 'Raimond', 'Kivi',    ((TO_DATE('01-JAN-1990','DD-MON-YYYY') + trunc(random() * 365) * '1 day'::interval + trunc(random() * 5) * '1 year'::interval)), mod(trunc((random() * 10)::numeric, 2), 4) + 1);
insert into student values ((select max(student_code) from student)+ trunc(random()*100), 'Heiki', 'Vosu',      ((TO_DATE('01-JAN-1990','DD-MON-YYYY') + trunc(random() * 365) * '1 day'::interval + trunc(random() * 5) * '1 year'::interval)), mod(trunc((random() * 10)::numeric, 2), 4) + 1);
insert into student values ((select max(student_code) from student)+ trunc(random()*100), 'Ahto', 'Koiv',       ((TO_DATE('01-JAN-1990','DD-MON-YYYY') + trunc(random() * 365) * '1 day'::interval + trunc(random() * 5) * '1 year'::interval)), mod(trunc((random() * 10)::numeric, 2), 4) + 1);
insert into student values ((select max(student_code) from student)+ trunc(random()*100), 'Riho', 'Vesik',      ((TO_DATE('01-JAN-1990','DD-MON-YYYY') + trunc(random() * 365) * '1 day'::interval + trunc(random() * 5) * '1 year'::interval)), mod(trunc((random() * 10)::numeric, 2), 4) + 1);
insert into student values ((select max(student_code) from student)+ trunc(random()*100), 'Marek', 'Harma',     ((TO_DATE('01-JAN-1990','DD-MON-YYYY') + trunc(random() * 365) * '1 day'::interval + trunc(random() * 5) * '1 year'::interval)), mod(trunc((random() * 10)::numeric, 2), 4) + 1);
insert into student values ((select max(student_code) from student)+ trunc(random()*100), 'Ago', 'Kallas',      ((TO_DATE('01-JAN-1990','DD-MON-YYYY') + trunc(random() * 365) * '1 day'::interval + trunc(random() * 5) * '1 year'::interval)), mod(trunc((random() * 10)::numeric, 2), 4) + 1);
insert into student values ((select max(student_code) from student)+ trunc(random()*100), 'Leevi', 'Jakobson',  ((TO_DATE('01-JAN-1990','DD-MON-YYYY') + trunc(random() * 365) * '1 day'::interval + trunc(random() * 5) * '1 year'::interval)), mod(trunc((random() * 10)::numeric, 2), 4) + 1);
insert into student values ((select max(student_code) from student)+ trunc(random()*100), 'Aadu', 'Orav',       ((TO_DATE('01-JAN-1990','DD-MON-YYYY') + trunc(random() * 365) * '1 day'::interval + trunc(random() * 5) * '1 year'::interval)), mod(trunc((random() * 10)::numeric, 2), 4) + 1);
insert into student values ((select max(student_code) from student)+ trunc(random()*100), 'Iisak', 'Valk',      ((TO_DATE('01-JAN-1990','DD-MON-YYYY') + trunc(random() * 365) * '1 day'::interval + trunc(random() * 5) * '1 year'::interval)), mod(trunc((random() * 10)::numeric, 2), 4) + 1);
insert into student values ((select max(student_code) from student)+ trunc(random()*100), 'Allan', 'Kross',     ((TO_DATE('01-JAN-1990','DD-MON-YYYY') + trunc(random() * 365) * '1 day'::interval + trunc(random() * 5) * '1 year'::interval)), mod(trunc((random() * 10)::numeric, 2), 4) + 1);
insert into student values ((select max(student_code) from student)+ trunc(random()*100), 'Roland', 'Valk',     ((TO_DATE('01-JAN-1990','DD-MON-YYYY') + trunc(random() * 365) * '1 day'::interval + trunc(random() * 5) * '1 year'::interval)), mod(trunc((random() * 10)::numeric, 2), 4) + 1);
insert into student values ((select max(student_code) from student)+ trunc(random()*100), 'Rihard', 'Saar',     ((TO_DATE('01-JAN-1990','DD-MON-YYYY') + trunc(random() * 365) * '1 day'::interval + trunc(random() * 5) * '1 year'::interval)), mod(trunc((random() * 10)::numeric, 2), 4) + 1);
insert into student values ((select max(student_code) from student)+ trunc(random()*100), 'Roland', 'Eskola',   ((TO_DATE('01-JAN-1990','DD-MON-YYYY') + trunc(random() * 365) * '1 day'::interval + trunc(random() * 5) * '1 year'::interval)), mod(trunc((random() * 10)::numeric, 2), 4) + 1);
insert into student values ((select max(student_code) from student)+ trunc(random()*100), 'Raiko', 'Mark',      ((TO_DATE('01-JAN-1990','DD-MON-YYYY') + trunc(random() * 365) * '1 day'::interval + trunc(random() * 5) * '1 year'::interval)), mod(trunc((random() * 10)::numeric, 2), 4) + 1);
insert into student values ((select max(student_code) from student)+ trunc(random()*100), 'Ulari', 'Janes',     ((TO_DATE('01-JAN-1990','DD-MON-YYYY') + trunc(random() * 365) * '1 day'::interval + trunc(random() * 5) * '1 year'::interval)), mod(trunc((random() * 10)::numeric, 2), 4) + 1);
insert into student values ((select max(student_code) from student)+ trunc(random()*100), 'Heiki', 'Ruutel',    ((TO_DATE('01-JAN-1990','DD-MON-YYYY') + trunc(random() * 365) * '1 day'::interval + trunc(random() * 5) * '1 year'::interval)), mod(trunc((random() * 10)::numeric, 2), 4) + 1);
insert into student values ((select max(student_code) from student)+ trunc(random()*100), 'Urmet', 'Rootare',   ((TO_DATE('01-JAN-1990','DD-MON-YYYY') + trunc(random() * 365) * '1 day'::interval + trunc(random() * 5) * '1 year'::interval)), mod(trunc((random() * 10)::numeric, 2), 4) + 1);
insert into student values ((select max(student_code) from student)+ trunc(random()*100), 'Aarne', 'Kivi',      ((TO_DATE('01-JAN-1990','DD-MON-YYYY') + trunc(random() * 365) * '1 day'::interval + trunc(random() * 5) * '1 year'::interval)), mod(trunc((random() * 10)::numeric, 2), 4) + 1);
insert into student values ((select max(student_code) from student)+ trunc(random()*100), 'Tonu', 'Kabin',      ((TO_DATE('01-JAN-1990','DD-MON-YYYY') + trunc(random() * 365) * '1 day'::interval + trunc(random() * 5) * '1 year'::interval)), mod(trunc((random() * 10)::numeric, 2), 4) + 1);
insert into student values ((select max(student_code) from student)+ trunc(random()*100), 'Innar', 'Kaljurand', ((TO_DATE('01-JAN-1990','DD-MON-YYYY') + trunc(random() * 365) * '1 day'::interval + trunc(random() * 5) * '1 year'::interval)), mod(trunc((random() * 10)::numeric, 2), 4) + 1);
insert into student values ((select max(student_code) from student)+ trunc(random()*100), 'Tanel', 'Tamm',      ((TO_DATE('01-JAN-1990','DD-MON-YYYY') + trunc(random() * 365) * '1 day'::interval + trunc(random() * 5) * '1 year'::interval)), mod(trunc((random() * 10)::numeric, 2), 4) + 1);
insert into student values ((select max(student_code) from student)+ trunc(random()*100), 'Ivo', 'Lepp',        ((TO_DATE('01-JAN-1990','DD-MON-YYYY') + trunc(random() * 365) * '1 day'::interval + trunc(random() * 5) * '1 year'::interval)), mod(trunc((random() * 10)::numeric, 2), 4) + 1);
insert into student values ((select max(student_code) from student)+ trunc(random()*100), 'Runno', 'Teder',     ((TO_DATE('01-JAN-1990','DD-MON-YYYY') + trunc(random() * 365) * '1 day'::interval + trunc(random() * 5) * '1 year'::interval)), mod(trunc((random() * 10)::numeric, 2), 4) + 1);
