OBJ = obj
INC = include
BIN = bin
SRC = src
VERSION = c99

all: analizadorSemantico

analizadorSemantico: $(OBJ)/main.o $(OBJ)/y.tab.o
	gcc -std=$(VERSION) $(OBJ)/main.o $(OBJ)/y.tab.o -o $(BIN)/analizadorSemantico

$(OBJ)/y.tab.o: $(SRC)/y.tab.c
	gcc -std=$(VERSION) -DYYDEBUG=1 -c $(SRC)/y.tab.c -o $(OBJ)/y.tab.o

$(OBJ)/main.o: $(SRC)/main.c
	gcc -std=$(VERSION) -c $(SRC)/main.c -o $(OBJ)/main.o

$(SRC)/y.tab.c: $(SRC)/practica4.y $(SRC)/lex.yy.c
	bison -v -d -o $(SRC)/y.tab.c $(SRC)/practica4.y

$(SRC)/lex.yy.c: $(SRC)/practica4.l
	lex $(SRC)/practica4.l
	mv lex.yy.c $(SRC)

clean:
	rm $(SRC)/lex.yy.c $(SRC)/y.tab.h $(SRC)/y.tab.c $(SRC)/y.output $(OBJ)/*.o $(BIN)/*
