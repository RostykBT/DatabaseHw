#include "functions.h"

void add_user(PGconn *conn)
{
    PGresult *res;
    char input_first_name[100];
    char input_last_name[100];
    char input_date_of_birth[100];
    printf("type first name ");
    scanf("%s", input_first_name);
    printf("type last name ");
    scanf("%s", input_last_name);
    printf("type date of birth ");
    scanf("%s", input_date_of_birth);
    // insert student to database
    char query[1000];
    sprintf(query, "INSERT INTO student(student_code, first_name, last_name, birthdate) VALUES (((select max(student_code) from student) + 1),'%s', '%s', '%s')", input_first_name, input_last_name, input_date_of_birth);
    res = PQexec(conn, query);
    if (PQresultStatus(res) != PGRES_COMMAND_OK)
    {
        printf("We did not add the student\n");
        // printf("%s", PQerrorMessage(conn));

        PQclear(res);
        // continue;
    }
    printf("Student added. Code: %d\n", PQgetvalue(res, 0, 0));

    PQclear(res);
}

void list_students(PGconn *conn)

{
    PGresult *res;
    int rec_count;
    int row;
    int col;

    res = PQexec(conn, "SELECT * FROM student");
    if (PQresultStatus(res) != PGRES_TUPLES_OK)
    {
        printf("We did not get any data!\n");
        PQclear(res);
        return;
    }

    // number of rows
    rec_count = PQntuples(res);

    // number of columns
    col = PQnfields(res);

    // print the rows
    for (row = 0; row < rec_count; row++)
    {
        for (col = 0; col < 5; col++)
        {
            printf("%s\t", PQgetvalue(res, row, col));
        }
        printf("\n");
    }
    PQclear(res);
}

void list_courses(PGconn *conn)
{
    PGresult *res;
    int rec_count;
    int row;
    int col;
    res = PQexec(conn, "SELECT * FROM subject");
    if (PQresultStatus(res) != PGRES_TUPLES_OK)
    {
        printf("We did not get any data!\n");
        PQclear(res);
    }

    // number of rows
    rec_count = PQntuples(res);

    // number of columns
    col = PQnfields(res);

    // print the rows
    for (row = 0; row < rec_count; row++)
    {
        for (col = 0; col < 4; col++)
        {
            printf("%s\t", PQgetvalue(res, row, col));
        }
        printf("\n");
    }
    PQclear(res);
}

void add_course(PGconn *conn)
{
    PGresult *res;
    char input_name[100];
    char input_teacher[100];
    char input_credits[100];
    char input_code[100];
    printf("type name: ");
    scanf("%s", input_name);
    printf("type teacher: ");
    scanf("%s", input_teacher);
    printf("type credits: ");
    scanf("%s", input_credits);
    printf("type code: ");
    scanf("%s", input_code);
    // insert course to database
    char query[1000];
    sprintf(query, "INSERT INTO subject(subject_code, name, teacher, credits) VALUES ('%s','%s', '%s', '%s')", input_code, input_name, input_teacher, input_credits);
    res = PQexec(conn, query);
    if (PQresultStatus(res) != PGRES_COMMAND_OK)
    {
        printf("We did not add the course\n");
        // printf("%s", PQerrorMessage(conn));

        PQclear(res);
        // continue;
    }
    printf("Course added. Code: %d\n", PQgetvalue(res, 0, 0));
}

void delete_student(PGconn *conn)
{
    PGresult *res;
    char input_student_code[100];
    printf("type student code: ");
    scanf("%s", input_student_code);
    // delete student from database
    char query[1000];
    sprintf(query, "DELETE FROM student WHERE student_code = %s", input_student_code);
    res = PQexec(conn, query);
    if (PQresultStatus(res) != PGRES_COMMAND_OK)
    {
        printf("We did not delete the student\n");
        // printf("%s", PQerrorMessage(conn));

        PQclear(res);
        // continue;
    }
    printf("Student deleted. Code: %s\n", input_student_code);

    PQclear(res);
}

void modify_student(PGconn *conn)
{
    // ask user, what should be modified(name, surname, age)
    char input_storcs[100];
    printf("type name, surname or age: ");
    scanf("%s", input_storcs);
    // ask user for id
    int id;
    printf("type id ");
    scanf("%d", &id);
    if (strcmp(input_storcs, "name") == 0)
    {
        // ask user for new name
        char new_first_name[100];
        printf("type new name: ");
        scanf("%s", new_first_name);
        // modify name
        char query[100];
        sprintf(query, "UPDATE student SET first_name = '%s' WHERE student_code = %d", new_first_name, id);
        PGresult *res = PQexec(conn, query);
        if (PQresultStatus(res) != PGRES_COMMAND_OK)
        {
            //printf("Error: %s", PQerrorMessage(conn));
        }
        PQclear(res);
    }
    else if (strcmp(input_storcs, "surname") == 0)
    {
        // ask user for new surname
        char new_last_name[100];
        printf("type new last_name ");
        scanf("%s", new_last_name);
        // modify surname
        char query[100];
        sprintf(query, "UPDATE student SET last_name = '%s' WHERE student_code = %d", new_last_name, id);
        PGresult *res = PQexec(conn, query);
        if (PQresultStatus(res) != PGRES_COMMAND_OK)
        {
            //printf("Error: %s", PQerrorMessage(conn));
        }
        PQclear(res);
    }
    else if (strcmp(input_storcs, "age") == 0)
    {
        char new_birthdate[100];
        printf("type new birthdate ");
        scanf("%s", new_birthdate);
        char query[100];
        sprintf(query, "UPDATE student SET birthdate = '%s' WHERE student_code = %d", new_birthdate, id);
        PGresult *res = PQexec(conn, query);
        if (PQresultStatus(res) != PGRES_COMMAND_OK)
        {
            //printf("Error: %s", PQerrorMessage(conn));
        }
        PQclear(res);
    }
    else
    {
        printf("Invalid input");
    }
}

void modify_course(PGconn *conn)
{
    // ask user, what should be modified( credits, name or teacher or course_code)

    char input_storcs[100];
    printf("type credits, name, teacher or course_code ");
    scanf("%s", input_storcs);
    // ask id_course which should be modified
    int id_course;
    printf("type id_course ");
    scanf("%d", &id_course);
    if (strcmp(input_storcs, "credits") == 0)
    {
        // ask new credits
        // update credits
        int credits;
        printf("type new credits ");
        scanf("%d", &credits);
        char query[100];
        sprintf(query, "UPDATE subject SET credits = %d WHERE id_subject = %d", credits, id_course);
        PGresult *res = PQexec(conn, query);
        if (PQresultStatus(res) != PGRES_COMMAND_OK)
        {
           // printf("Error: %s", PQerrorMessage(conn));
            PQclear(res);
        }
        else
        {
            printf("Credits updated\n");
        }
    }
    else if (strcmp(input_storcs, "name") == 0)
    {
        // ask new name
        // update name
        char name[100];
        printf("type new name ");
        scanf("%s", name);
        char query[100];
        sprintf(query, "UPDATE subject SET name = '%s' WHERE id_subject = %d", name, id_course);
        PGresult *res = PQexec(conn, query);
        if (PQresultStatus(res) != PGRES_COMMAND_OK)
        {
            //printf("Error: %s", PQerrorMessage(conn));
            PQclear(res);
        }
        else
        {
            printf("Name updated\n");
        }
    }
    else if (strcmp(input_storcs, "teacher") == 0)
    {
        // ask new teacher
        // update teacher
        char teacher[100];
        printf("type new teacher ");
        scanf("%s", teacher);
        char query[100];
        sprintf(query, "UPDATE subject SET teacher = '%s' WHERE id_subject = %d", teacher, id_course);
        PGresult *res = PQexec(conn, query);
        if (PQresultStatus(res) != PGRES_COMMAND_OK)
        {
            //printf("Error: %s", PQerrorMessage(conn));
            PQclear(res);
        }
        else
        {
            printf("Teacher updated\n");
        }
    }
    else if (strcmp(input_storcs, "course_code") == 0)
    {
        // ask new course_code
        // update course_code
        char course_code[100];
        printf("type new course_code ");
        scanf("%s", course_code);
        char query[100];
        sprintf(query, "UPDATE subject SET subject_code = '%s' WHERE id_subject = %d", course_code, id_course);
        PGresult *res = PQexec(conn, query);
        if (PQresultStatus(res) != PGRES_COMMAND_OK)
        {
           // printf("Error: %s", PQerrorMessage(conn));
            PQclear(res);
        }
        else
        {
            printf("Course_code updated\n");
        }
    }
    else
    {
        printf("Invalid input");
    }
}

void delete_course(PGconn *conn)
{
    PGresult *res;
    char input[100];
    printf("Enter course id: ");
    scanf("%s", input);
    char query[100];
    sprintf(query, "DELETE FROM subject WHERE id_subject = %s", input);
    res = PQexec(conn, query);
    if (PQresultStatus(res) != PGRES_COMMAND_OK)
    {
        printf("Error deleting course\n");
        PQclear(res);
        return;
    }
    PQclear(res);
    printf("Course deleted\n");
}

void list_grades(PGconn *conn)
{
    // print all grades
    PGresult *res;
    int rec_count;
    int row;
    int col;
    res = PQexec(conn, "SELECT id_grade, id_subject, student_code, grade FROM grade");
    if (PQresultStatus(res) != PGRES_TUPLES_OK)
    {
        printf("We did not get any data!\n");
        PQclear(res);
        return;
    }
    rec_count = PQntuples(res);
    for (row = 0; row < rec_count; row++)
    {
        for (col = 0; col < 4; col++)
        {
            printf("%s\t", PQgetvalue(res, row, col));
        }
        printf("\n");
    }
    PQclear(res);
}

void add_grade(PGconn *conn)
{
    PGresult *res;
    // ask user for student id
    char input_student_id[100];
    printf("type student id ");
    scanf("%s", input_student_id);
    // ask user for id_subject
    char input_id_subject[100];
    printf("type id_subject ");
    scanf("%s", input_id_subject);
    // ask user for grade
    char input_grade[100];
    printf("type grade ");
    scanf("%s", input_grade);
    // update grades table
    char query[100];
    sprintf(query, "INSERT INTO grade (student_code, id_subject, grade) VALUES (%s, %s, %s)", input_student_id, input_id_subject, input_grade);
    res = PQexec(conn, query);
    if (PQresultStatus(res) != PGRES_COMMAND_OK)
    {
        printf("Error adding grade\n");
        // print error
        // printf("%s", PQerrorMessage(conn));
        PQclear(res);
        return;
    }
    PQclear(res);
    printf("Grade added\n");
    upate_student_avarage_grade(conn, input_student_id);
}

void upate_student_avarage_grade(PGconn *conn, int student_id)
{
    PGresult *res;
    char query[1000];
    sprintf(query, "UPDATE student SET average_grade = (SELECT SUM(grade.grade*subject.credits)/ SUM(subject.credits) FROM grade INNER JOIN subject ON grade.id_subject = subject.id_subject where student_code= %d) WHERE student_code = %d", student_id, student_id);
    res = PQexec(conn, query);
    PQclear(res);
}

void rating(PGconn *conn)
{
    // print those students who have average grade >= user input
    PGresult *res;
    int rec_count;
    int row;
    int col;
    float input;
    printf("Enter average grade: ");
    scanf("%f", &input);
    char query[100];
    sprintf(query, "SELECT * FROM student WHERE average_grade > %f", input);
    res = PQexec(conn, query);
    rec_count = PQntuples(res);
    if (rec_count == 0)
    {
        printf("No students with average grade >= %f\n", input);
    }
    else
    {
        printf("Students with average grade >= %f:\n", input);
        for (row = 0; row < rec_count; row++)
        {
            for (col = 0; col < 5; col++)
            {
                printf("%s\t", PQgetvalue(res, row, col));
            }
            printf("\n");
        }
    }
}

void print_help()
{
    //clear terminal
    printf("\033[2J\033[1;1H");
    printf("This program is a student database management system.\n");
    printf("It allows you to add, delete, update and list students, courses and grades.\n");
    printf("You can also list students with average grade >= user input.\n");
    //print hr
    printf("------------------------------------------------------------\n");
    printf("'add' - add student, course or grade to database \n");
    printf("'delete' - delete student or course from database \n");
    printf("'modify' - modify student or course from database \n");
    printf("'list' - list all students, courses or grades from database \n");
    printf("'rating' - list all students with average grade grater than requested\n");
    printf("'exit' - exit from program \n");
}

void list(PGconn *conn)
{
    char input_storcs[100];
    printf("type 'student', 'course' or 'grade': ");
    scanf("%s", input_storcs);
    if (strcmp(input_storcs, "student") == 0)
    {
        // list all students
        list_students(conn);
    }
    else if (strcmp(input_storcs, "course") == 0)
    {
        // list all courses
        list_courses(conn);
    }
    else if (strcmp(input_storcs, "grade") == 0)
    {
        list_grades(conn);
    }
    else

    {
        printf("Invalid input");
    }
}

void modify(PGconn *conn)
{
    char input_storcs[100];
    printf("type 'student' or 'course': ");
    scanf("%s", input_storcs);
    if (strcmp(input_storcs, "student") == 0)
    {
        modify_student(conn);
    }
    else if (strcmp(input_storcs, "course") == 0)
    {
        modify_course(conn);
    }
    else
    {
        printf("Wrong input\n");
    }
}

void delete (PGconn *conn)
{
    char input_storcs[100];
    printf("type student or course: ");
    scanf("%s", input_storcs);
    if (strcmp(input_storcs, "student") == 0)
    {
        delete_student(conn);
    }
    else if (strcmp(input_storcs, "course") == 0)
    {
        delete_course(conn);
    }
    else
    {
        printf("Wrong input\n");
    }
}

void add(PGconn *conn)
{
    // ask user, what should be added(student or course)
    char input_storcs[100];
    printf("type student, course or grade: ");
    scanf("%s", input_storcs);
    if (strcmp(input_storcs, "student") == 0)
    {
        add_user(conn);
    }
    else if (strcmp(input_storcs, "course") == 0)
    {
        add_course(conn);
    }
    else if (strcmp(input_storcs, "grade") == 0)
    {
        add_grade(conn);
    }
    else
    {
        printf("Wrong input\n");
    }
}
