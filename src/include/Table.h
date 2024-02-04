#ifndef TABLE_H
#define TABLE_H

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

void CSQLITE3_createTableBuffer();

#endif