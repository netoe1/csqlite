#include <stdio.h>
#include <stdlib.h>
#include "../include/csqlite3.h"
#include "../include/consts.h"
#include "../include/Table.h"
// Internal functions.
static int callback(void *NotUsed, int argc, char **argv, char **azColName)
{
    int i;
    for (i = 0; i < argc; i++)
    {
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}
static void CSQLITE3_error(const char *what)
{

    if (what == NULL || *what == '\0')
    {
        fprintf(stderr, "The reason for error (what) is mandatory in CSQLITE3_error()!");
        exit(CSQLITE_ERROR_EXIT);
        return;
    }

    fprintf(stderr, "[%s]:%s\n", PREFIX_CSQLITE_ERR, what);
    exit(CSQLITE_ERROR_EXIT);
}
static int CSQLITE3_verifyConn(CSQLITE3 *ptr)
{
    if (ptr == NULL)
    {
        CSQLITE3_error("The CSQLITE ptr is invalid.");
        return EXIT_FAILURE;
    }

    if (ptr->connection == NULL)
    {
        CSQLITE3_error("The CSQLITE ptr connectio  is invalid.");
        return EXIT_FAILURE;
    }

    return EXIT_FAILURE;
}
int CSQLITE3_initConnection(const char path[], CSQLITE3 *ptr)
{
    if (&path[0] == NULL || path[0] == '\0')
    {
        fprintf(stderr, "[csqlite3-error]: You didn't define a valid path to init connection!\n");
        return EXIT_FAILURE;
    }

    if (ptr == NULL)
    {
        fprintf(stderr, "[csqlite3-error]: You didn't define a valid CSQLITE3 ptr to init connection!\n");
        return EXIT_FAILURE;
    }
    FILE *file = fopen(path, "r");
    if (!file)
    {
        printf("[csqlite3-error]: The file that you pass is invalid.\n");
        return EXIT_FAILURE;
    }
    fclose(file);

    // ptr->return_value = sqlite3_open(path, &ptr->connection);

    // if (ptr->return_value)
    // {
    //     fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(ptr->connection));
    //     sqlite3_close(ptr->connection);
    //     return EXIT_FAILURE;
    // }
    return EXIT_SUCCESS;
}
bool CSQLITE3_endConnection(CSQLITE3 *ptr)
{
    if (ptr == NULL)
    {
        fprintf(stderr, "[csqlite3-error]: You didn't define a valid CSQLITE3 ptr.");
        return false;
    }

    if (ptr->zErrMsg != NULL)
    {
        sqlite3_free(ptr->zErrMsg);
    }

    if (ptr->connection != NULL)
    {
        sqlite3_close(ptr->connection);
    }
    return true;
}
int CSQLITE3_createTable(CSQLITE3 *conn, CSQLITE3_Table *newTable);
int CSQLITE3_deleteTable(CSQLITE3 *conn, CSQLITE3_Table *deleteTable);
int CSQLITE3_updateTable(CSQLITE3 *conn, CSQLITE3_Table *updateTable);