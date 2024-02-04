#include "../include/csqlite3.h"

#include <stdio.h>
int main(void)
{
    CSQLITE3 db;
    puts("criando conexao");
    CSQLITE3_initConnection("teu cu.sql", &db);
    puts("encerra");
}