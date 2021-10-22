OBJ = obj
INC = include
BIN = bin
SRC = src

all:
	make clean
	make analizadorSintactico

analizadorSintactico: $(OBJ)/main.o $(OBJ)/y.tab.o
	gcc $(OBJ)/main.o $(OBJ)/y.tab.o -o $(BIN)/analizadorSintactico

$(OBJ)/y.tab.o: $(SRC)/y.tab.c
	gcc -c $(SRC)/y.tab.c -o $(OBJ)/y.tab.o

$(OBJ)/main.o: $(SRC)/main.c
	gcc -c $(SRC)/main.c -o $(OBJ)/main.o

$(SRC)/y.tab.c: $(SRC)/practica3.y $(SRC)/lex.yy.c
	bison -o $(SRC)/y.tab.c $(SRC)/practica3.y

$(SRC)/lex.yy.c: $(SRC)/practica3.l
	lex $(SRC)/practica3.l
	mv lex.yy.c $(SRC)

clean:
	rm $(SRC)/lex.yy.c $(OBJ)/*.o $(BIN)/*
