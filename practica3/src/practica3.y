%{
/****************************************************************
 **
 ** Fichero: PRACTICA3.Y
 ** Función: Pruebas de YACC para practicas de PL
 **
 ****************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/** La siguiente declaracion permite que 'yyerror' se puede invocar desde el
 ** fuente de lex (practica3.l)
 **/

void yyerror(char *msg);

/** La siguiente variable se usará para conocer el numero de la línea
 ** que se esta leyendo en cada momento. Tambies es posible usar la variable
 ** 'yylineno' que tambien nos muestra la linea actual. Para ello es necesario
 ** invocar a flex con la opcion '-l' (compatibilidad con lex).
 **/

int linea_actual = 1;

%}

/** Para uso de mensajes de error sintactivo con BISON.
 ** La siguiente declaracion provoca que 'bison', ante un error sintactivo,
 ** visualice mensajes de error con indicacion de los tokens que se esperaban
 ** en el lugar en el que se produjo el error (SOLO FUNCIONA CON BISON>=2.1).
 ** Para Bison<2.1 es mediante
 **
 ** #define YYERROR_VERBOSE
 **
 ** En caso de usar mensajes de error mediante 'mes' y 'mes2' (ver apendice D)
 ** nada de lo anterior debe tenerse en cuenta.
 **/

%error-verbose

/** A continuacion declaramos los nombres simbolicos de los tokens.
 ** byacc se encarga de asociar a cada uno un codigo
 **/

%token NOMBRE VERBO
%token NOMBRE_PROPIO
%token ARTICULO ARTICULO_A
%token DESCONOCIDO

%%

/** Seccion de producciones que definen la gramatica. **/

frase               : sintagma_nominal sintagma_predicado ;

sintagma_nominal    : ARTICULO NOMBRE
                    | NOMBRE_PROPIO ;

sintagma_predicado  : VERBO modificador objeto_directo ;

objeto_directo      : sintagma_nominal ;

modificador         : ARTICULO_A
                    | /** esto representa la cadena vacía **/ ;

%%

/** Aqui incluimos el fichero generado por el 'lex'
 ** que implementa la funcion 'yylex'
 **/

#include "lex.yy.c"

/** Se debe implementar la funcion yyerror. En este caso
 ** simplemente escribimos el mensaje de error en pantalla
 **/

void yyerror(char *msg)
{
    fprintf(stderr, "[Linea %d]: %s\n", linea_actual, msg);
}