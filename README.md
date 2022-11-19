Task:
Tasks
Create a text based user interface program, that would have the following functionality:

1. Adding a student. User will be asked: first name, last name, date of birth. Program has to generate unique student code for each student. (2p)
2. Modifying and deleting a student. (2p)
3. Adding, modifying and deleting a course. (2p)
4. Giving grade for a student for a specific course. When inserting a grade, the average grade should also be updated taking account the credit points. (2p)
5. Searching students based on their weighted average grade. (2p) For example, if we want to find the best students we could specify condition 'avg > 4.6'
Program has to communicate with the given database and use it for reading and storing data.



How to use the comand line program:
1. To conect to the database, you need to have to go to main.c file and change the database name, user name and password.

## CLI:

2. all possible can be found using the ```"help"``` command

``` 
This program is a student database management system.
It allows you to add, delete, update and list students, courses and grades.
You can also list students with average grade >= user input.
------------------------------------------------------------
'add' - add student, course or grade to database
'delete' - delete student or course from database
'modify' - modify student or course from database
'list' - list all students, courses or grades from database
'rating' - list all students with average grade grater than requested
'exit' - exit from program
```

3. to perform an operatin use the ```"add"```, ```delete``` or ```modify``` command,
program will ask you to enter the command arguments

```
>_add
type student, course or grade: student
type first name Rostyslav
type last name Boychuk
type date of birth 2005-04-05
row number 0 is out of range 0..-1
Student added.
```

4. to list all students, courses or grades use the ```"list"``` command

```
0       Sven    Keskula 1991-05-23      1.29
52      Reio    Aavik   1993-04-22      3.22
116     Paavo   Meri    1993-06-13      3.73
118     Kaur    Valk    1991-05-18      4.53
189     Leevi   Pihlak  1990-05-14      2.13
259     Veljo   Kuusk   1990-11-27      1.94
.......
```

5. exit the program using the ```"exit"``` command

```
>_exit

C:\HomeWork\DB>
```

### File sturcure:
```
1. main.c
    file contains main function, which is the entry point of the program. 
    It also contains the function to print the menu and the function to get the user's choice.
2. functions.c
    file contains the functions to perform the operations. The functions are called by main function.
3. functions.h
    file contains the function prototypes.
```
