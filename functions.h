#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <libpq-fe.h>
#include <stdio.h>
#include <string.h>

void print_help();
void list(PGconn *);
void modify(PGconn *);
void delete (PGconn *);
void add(PGconn *);

void list_students(PGconn *);
void list_courses(PGconn *);
void list_grades(PGconn *);

void add_user(PGconn *);
void add_course(PGconn *);
void add_grade(PGconn *);

void modify_student(PGconn *);
void modify_course(PGconn *);

void delete_course(PGconn *);
void delete_student(PGconn *);

void upate_student_avarage_grade(PGconn *, int);
void rating(PGconn *);


#endif