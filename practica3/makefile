OBJ = obj
INC = include
BIN = bin
SRC = src
VERSION = c99

all: analizadorSintactico

analizadorSintactico: $(OBJ)/main.o $(OBJ)/y.tab.o
	gcc -std=$(VERSION) $(OBJ)/main.o $(OBJ)/y.tab.o -o $(BIN)/analizadorSintactico

$(OBJ)/y.tab.o: $(SRC)/y.tab.c
	gcc -std=$(VERSION) -DYYDEBUG=1 -c $(SRC)/y.tab.c -o $(OBJ)/y.tab.o

$(OBJ)/main.o: $(SRC)/main.c
	gcc -std=$(VERSION) -c $(SRC)/main.c -o $(OBJ)/main.o

$(SRC)/y.tab.c: $(SRC)/practica3.y $(SRC)/lex.yy.c
	bison -Wall -v -d -o $(SRC)/y.tab.c $(SRC)/practica3.y

$(SRC)/lex.yy.c: $(SRC)/practica3.l
	lex $(SRC)/practica3.l
	mv lex.yy.c $(SRC)

clean:
	rm $(SRC)/lex.yy.c $(SRC)/y.tab.c $(SRC)/y.output $(OBJ)/*.o $(BIN)/*
