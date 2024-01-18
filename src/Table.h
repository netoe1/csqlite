#ifndef TABLE_H
#define TABLE_H

typedef struct column
{
    char *variable_name;
    char *type;
} CSQLITE3_Column;

typedef struct table
{
    char *table_name;
    CSQLITE3_Column *columns;
    char *onDelete;
} CSQLITE3_Table;

typedef struct buffer
{
    int inited;
    CSQLITE3_Table __table;
} CSQLITE3_Buffer;

void CSQLITE3_createTableBuffer();

#endif