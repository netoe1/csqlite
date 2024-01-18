CSQLITE3_H = ./src/csqlite3.h
CSQLITE3_C = ./src/csqlite3.c
CSQLITE3_O = ./obj/csqlite3.o
TABLE_H = ./src/Table.h
TABLE_C = ./src/Table.c
TABLE_O = ./obj/Table.o
MAIN_O = ./obj/main.o
MAIN_C = ./src/main.c
FLAG_SQLITE = -lsqlite3


 

all: 
	make table.o csqlite3.o main.o
table.o: ${TABLE_C} ${TABLE_H}
	gcc -c ${TABLE_C} -o ${TABLE_O}
main.o:
	gcc -o ${MAIN_O} ${MAIN_C} ${CSQLITE3_O} ${TABLE} ${FLAG_SQLITE}
csqlite3.o: ${CSQLITE3_H} ${CSQLITE3_C}
	gcc -c ${CSQLITE3_C} ${FLAG_SQLITE} -o ${CSQLITE3_O}
clean:
	rm -rf ./obj/*.o