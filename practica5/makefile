OBJ = obj
INC = include
BIN = bin
SRC = src
VERSION = c99

all: generadorCodInter

generadorCodInter: $(OBJ)/main.o $(OBJ)/y.tab.o
	gcc -std=$(VERSION) -pthread -g $(OBJ)/main.o $(OBJ)/y.tab.o -o $(BIN)/generadorCodInter

generadorCodEjemplos: $(BIN)/generadorCodInter ejemplo1.txt ejemplo2.txt
	./$(BIN)/generadorCodInter ejemplo1.txt
	mv ./$(SRC)/codInter.c ./$(SRC)/ejemplo1.c
	./$(BIN)/generadorCodInter ejemplo2.txt
	mv ./$(SRC)/codInter.c ./$(SRC)/ejemplo2.c

ejecutableEjemplos: $(SRC)/ejemplo1.c $(SRC)/ejemplo2.c
	gcc $(SRC)/ejemplo1.c -o $(BIN)/ejemplo1
	gcc $(SRC)/ejemplo2.c -o $(BIN)/ejemplo2

$(OBJ)/y.tab.o: $(SRC)/y.tab.c
	gcc -std=$(VERSION) -pthread -g -DYYDEBUG=1 -c $(SRC)/y.tab.c -o $(OBJ)/y.tab.o

$(OBJ)/main.o: $(SRC)/main.c
	gcc -std=$(VERSION) -c $(SRC)/main.c -o $(OBJ)/main.o

$(SRC)/y.tab.c: $(SRC)/practica5.y $(SRC)/lex.yy.c
	bison -v -d -o $(SRC)/y.tab.c $(SRC)/practica5.y

$(SRC)/lex.yy.c: $(SRC)/practica5.l
	lex $(SRC)/practica5.l
	mv lex.yy.c $(SRC)

clean:
	rm $(SRC)/lex.yy.c $(SRC)/y.tab.h $(SRC)/y.tab.c $(SRC)/y.output $(OBJ)/*.o $(BIN)/*
