#include <stdio.h>
#include <libpq-fe.h>
#include "functions.h"
#include <string.h>

int main()
{
    PGconn *conn;
    PGresult *res;
    int rec_count;
    int row;
    int col;

    // Creating a connection to database
    conn = PQconnectdb("dbname=student_db host=localhost port=54320 user=admin password=admin");

    // Check connection status
    if (PQstatus(conn) == CONNECTION_BAD)
    {
        printf("We were unable to connect to the database\n");
        return 0;
    }

    // Print help
    print_help();

    while (1)
    {
        char input[100];
        printf(">_");
        scanf("%s", input);
        if (strcmp(input, "exit") == 0)
        {
            break;
        }
        else if (strcmp(input, "add") == 0)
        {
            add(conn);
        }
        else if (strcmp(input, "delete") == 0)
        {
            delete (conn);
        }
        else if (strcmp(input, "modify") == 0)
        {
            modify(conn);
        }
        else if (strcmp(input, "list") == 0)
        {
            list(conn);
        }
        else if (strcmp(input, "help") == 0)
        {
            print_help();
        }
        else if (strcmp(input, "rating") == 0)
        {
            rating(conn);
        }
        else
        {
            printf("Command not found, try again or 'help' to get more info\n");
        }
    }

    PQfinish(conn);

    return 0;
}
