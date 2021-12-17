OBJ = obj
INC = include
BIN = bin
SRC = src
VERSION = c++11
HIDE_WARNINGS = -Wno-write-strings -Wno-deprecated-register

.SILENT:

all: generadorCodInter

generadorCodInter: $(OBJ)/main.o $(OBJ)/y.tab.o
	g++ $(HIDE_WARNINGS) -std=$(VERSION) -pthread -g $(OBJ)/main.o $(OBJ)/y.tab.o -o $(BIN)/generadorCodInter

generadorCodEjemplos: $(BIN)/generadorCodInter ejemplo1.txt ejemplo2.txt
	./$(BIN)/generadorCodInter ejemplo1.txt
	mv ./$(SRC)/codInter.cpp ./$(SRC)/ejemplo1.cpp
	./$(BIN)/generadorCodInter ejemplo2.txt
	mv ./$(SRC)/codInter.cpp ./$(SRC)/ejemplo2.cpp
	./$(BIN)/generadorCodInter ejemploProcedimientos.txt
	mv ./$(SRC)/codInter.cpp ./$(SRC)/ejemploProcedimientos.cpp
	./$(BIN)/generadorCodInter pruebaFinal.txt
	mv ./$(SRC)/codInter.cpp ./$(SRC)/pruebaFinal.cpp
	./$(BIN)/generadorCodInter defensa.txt
	mv ./$(SRC)/codInter.cpp ./$(SRC)/defensa.cpp

ejecutableEjemplos: $(SRC)/ejemplo1.cpp $(SRC)/ejemplo2.cpp
	g++ -std=$(VERSION) $(HIDE_WARNINGS) $(SRC)/ejemplo1.cpp -o $(BIN)/ejemplo1
	g++ -std=$(VERSION) $(HIDE_WARNINGS) $(SRC)/ejemplo2.cpp -o $(BIN)/ejemplo2
	g++ -std=$(VERSION) $(HIDE_WARNINGS) $(SRC)/ejemploProcedimientos.cpp -o $(BIN)/ejemploProcedimientos
	g++ -std=$(VERSION) $(HIDE_WARNINGS) $(SRC)/pruebaFinal.cpp -o $(BIN)/pruebaFinal
	g++ -std=$(VERSION) $(HIDE_WARNINGS) $(SRC)/defensa.cpp -o $(BIN)/defensa

$(OBJ)/y.tab.o: $(SRC)/y.tab.c
	g++ $(HIDE_WARNINGS) -std=$(VERSION) -pthread -g -DYYDEBUG=1 -c $(SRC)/y.tab.c -o $(OBJ)/y.tab.o

$(OBJ)/main.o: $(SRC)/main.cpp
	g++ $(HIDE_WARNINGS) -std=$(VERSION) -c $(SRC)/main.cpp -o $(OBJ)/main.o

$(SRC)/y.tab.c: $(SRC)/practica5.y $(SRC)/lex.yy.c
	bison -v -d -o $(SRC)/y.tab.c $(SRC)/practica5.y

$(SRC)/lex.yy.c: $(SRC)/practica5.l
	lex $(SRC)/practica5.l
	mv lex.yy.c $(SRC)

clean:
	rm $(SRC)/lex.yy.c $(SRC)/y.tab.h $(SRC)/y.tab.c $(SRC)/y.output $(OBJ)/*.o $(BIN)/*
