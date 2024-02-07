#ifndef CSQLITE3_H
#define CSQLITE3_H

#include <sqlite3.h>
#include <stdbool.h>

typepdef struct csqlite3
{
    sqlite3 *connection;
    int return_value;
    char *zErrMsg;

} CSQLITE3;

typedef struct column
{
    const char *variable_name;
    const char *sqlite_type;
} CSQLITE3_Column;

typedef struct table
{
    const char *table_name;
    CSQLITE3_Column *columns;
    const char *onDelete;
} CSQLITE3_Table;

typedef struct buffer
{
    unsigned int inited;
    CSQLITE3_Table __table;
} CSQLITE3_Buffer;

int CSQLITE3_initConnection(const char __path[], CSQLITE3 *ptr);
bool CSQLITE3_endConnection(CSQLITE3 *ptr);

#endif