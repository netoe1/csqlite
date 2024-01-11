CSQLITE3_H = ./src/csqlite3.h
CSQLITE3_C = ./src/csqlite3.c
CSQLITE3_O = ./obj/csqlite3.o
MAIN_O = ./obj/main.o
MAIN_C = ./src/main.c
FLAG_SQLITE = -lsqlite3


 

all: ${CSQLITE3_C} ${CSQLITE3_H}
#compiling csqlite3.c
	gcc -c ${CSQLITE3_C} ${FLAG_SQLITE} -o ${CSQLITE3_O}
#compiling main.c
	gcc -o ${MAIN_O} ${MAIN_C} ${CSQLITE3_O} ${FLAG_SQLITE}

clean:
	rm -rf ./obj/*.o