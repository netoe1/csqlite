#ifndef CSQLITE3_H
#define CSQLITE3_H

#include <sqlite3.h>
#include <stdbool.h>

typedef struct csqlite3
{
    sqlite3 *connection;
    int return_value;
    char *zErrMsg;

} CSQLITE3;

static int callback(void *NotUsed, int argc, char **argv, char **azColName);
int CSQLITE3_initConnection(const char __path[], CSQLITE3 *ptr);
bool CSQLITE3_endConnection(CSQLITE3 *ptr);

#endif