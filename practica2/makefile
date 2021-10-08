all: analizadorLexico

analizadorLexico: lex.yy.o
	gcc lex.yy.o -o analizadorLexico

lex.yy.c:
	lex practica2.l

lex.yy.o: lex.yy.c tabla.h

clean:
	rm *.c *.o
