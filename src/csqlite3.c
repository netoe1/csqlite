#include <stdio.h>
#include <stdlib.h>
#include "csqlite3.h"

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
