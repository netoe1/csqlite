

# Default folders:
INCLUDE = ./src/include
SRC = ./src/src
OBJ = ./src/obj

# Custom Folders
#SCHEMA_SRC 				= 		${SRC}/Schema
#SCHEMA_INCLUDE 			= 		${INCLUDE}/Schema
#SCHEMA_OBJ 				= 		${OBJ}/Schema
#MAIN_SRC 				= 		${SRC}/Main
#MAIN_INCLUDE 			= 		${INCLUDE}Main
#MAIN_OBJ 				= 		${OBJ}/Main
#CONSTANTS_INCLUDE 		=		${INCLUDE}/Constants

CSQLITE3_H 				= 		${INCLUDE}/csqlite3.h
CSQLITE3_C 				= 		${SRC}/csqlite3.c
CSQLITE3_O 				=		${OBJ}/csqlite3.o

TABLE_H	 				= 		${INCLUDE}/Table.h
TABLE_C 				= 		${SRC}/Table.c
TABLE_O 				= 		${OBJ}/Table.o

MAIN_O 					= 		${OBJ}/main.o
MAIN_C 					= 		${SRC}/main.c
FLAG_SQLITE = -lsqlite3	
ALL_FLAGS = -Wall

 

all: 
	make table.o csqlite3.o main.o

table.o: ${TABLE_C} ${TABLE_H}
	gcc -c ${TABLE_C} -o ${TABLE_O}
main.o:
	gcc -o ${MAIN_O} ${MAIN_C} ${CSQLITE3_O} ${TABLE} ${FLAG_SQLITE}
csqlite3.o: ${CSQLITE3_H} ${CSQLITE3_C}
	gcc -c ${CSQLITE3_C} ${FLAG_SQLITE} -o ${CSQLITE3_O}
clean:
	rm -rf ./src/obj/*.o