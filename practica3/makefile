OBJ = obj
INC = include
BIN = bin
SRC = src

all: analizadorLexico

analizadorLexico: $(OBJ)/lex.yy.o
	gcc  $(OBJ)/lex.yy.o -o $(BIN)/analizadorLexico

$(SRC)/lex.yy.c:
	lex $(SRC)/practica2.l
	mv lex.yy.c $(SRC)

$(OBJ)/lex.yy.o: $(SRC)/lex.yy.c $(INC)/tabla.h
	gcc -g -I$(INC) -c $(SRC)/lex.yy.c -o $(OBJ)/lex.yy.o

clean:
	rm $(SRC)/*.c $(OBJ)/*.o
