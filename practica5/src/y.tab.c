/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     PRINCIPAL = 258,
     LLAVEIZQ = 259,
     LLAVEDER = 260,
     COMA = 261,
     LISTADE = 262,
     PROCEDIMIENTO = 263,
     PARDER = 264,
     PARIZQ = 265,
     CORCHIZQ = 266,
     CORCHDER = 267,
     IGUAL = 268,
     INICIOVAR = 269,
     FINVAR = 270,
     SI = 271,
     MIENTRAS = 272,
     OTROCASO = 273,
     PARA = 274,
     HASTA = 275,
     ITERANDO = 276,
     HACER = 277,
     LEER = 278,
     IMPRIMIR = 279,
     CADENA = 280,
     ID = 281,
     PYC = 282,
     TIPOS = 283,
     CONSTANTE = 284,
     ELEM_POSI_BINA = 285,
     OR = 286,
     AND = 287,
     XOR = 288,
     IGUALDAD = 289,
     RELACION = 290,
     ADITIVOS = 291,
     MULTIPLICATIVOS = 292,
     POTENCIAS = 293,
     NOT = 294,
     UNARIOS = 295,
     DECRE_PRE = 296,
     INCRE_PRE = 297,
     UNARIO_PRE_LISTA = 298,
     ELEM_POSI = 299,
     MOV_LISTA = 300,
     DOLLAR = 301
   };
#endif
/* Tokens.  */
#define PRINCIPAL 258
#define LLAVEIZQ 259
#define LLAVEDER 260
#define COMA 261
#define LISTADE 262
#define PROCEDIMIENTO 263
#define PARDER 264
#define PARIZQ 265
#define CORCHIZQ 266
#define CORCHDER 267
#define IGUAL 268
#define INICIOVAR 269
#define FINVAR 270
#define SI 271
#define MIENTRAS 272
#define OTROCASO 273
#define PARA 274
#define HASTA 275
#define ITERANDO 276
#define HACER 277
#define LEER 278
#define IMPRIMIR 279
#define CADENA 280
#define ID 281
#define PYC 282
#define TIPOS 283
#define CONSTANTE 284
#define ELEM_POSI_BINA 285
#define OR 286
#define AND 287
#define XOR 288
#define IGUALDAD 289
#define RELACION 290
#define ADITIVOS 291
#define MULTIPLICATIVOS 292
#define POTENCIAS 293
#define NOT 294
#define UNARIOS 295
#define DECRE_PRE 296
#define INCRE_PRE 297
#define UNARIO_PRE_LISTA 298
#define ELEM_POSI 299
#define MOV_LISTA 300
#define DOLLAR 301




/* Copy the first part of user declarations.  */
#line 1 "src/practica5.y"

int yylex();
#line 5 "src/practica5.y"

/****************************************************************
 **
 ** Fichero: PRACTICA5.Y
 ** Función: Pruebas de YACC para practicas de PL
 **
 ****************************************************************/

#define _POSIX_C_SOURCE 200809L

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/** La siguiente declaracion permite que 'yyerror' se puede invocar desde el
 ** fuente de lex (practica3.l)
 **/

void lexerror(const char *msg);
void yyerror(const char *msg);

/** La siguiente variable se usará para conocer el numero de la línea
 ** que se esta leyendo en cada momento. Tambies es posible usar la variable
 ** 'yylineno' que tambien nos muestra la linea actual. Para ello es necesario
 ** invocar a flex con la opcion '-l' (compatibilidad con lex).
 **/

int linea_actual = 1;


typedef enum {
  marca,
  procedimiento,
  variable,
  parametro_formal,
  descripInstrControl
} tipoEntrada ;

typedef enum {
  entero,
  real,
  caracter,
  booleano,
  lista_entero,
  lista_real,
  lista_caracter,
  lista_booleano,
  desconocido,
  no_asignado
} dtipo ;

dtipo obtenerTipoLista(dtipo tipo) {
  switch(tipo) {
    case entero:
      return lista_entero;
    break;
    case real:
      return lista_real;
    break;
    case caracter:
      return lista_caracter;
    break;
    case booleano:
      return lista_booleano;
    break;
    default:
      return lista_entero;
    break;
  }
}

typedef struct {
  char *etiquetaEntrada;
  char *etiquetaSalida;
  char *etiquetaElse;
  char *nombreVarControl;
} descriptorDeInstrControl;

typedef struct {
  tipoEntrada   entrada ;
  char          *nombre ;
  dtipo         tipoDato ;
  //numero de parámetros que hay que pasar al procedimiento
  unsigned int  parametrosMin ;
  //número de parámetros obligatorios más por defecto
  unsigned int  parametrosMax ;
  descriptorDeInstrControl descripControl ;
} entradaTS ;


#define MAX_TS 1000

unsigned int TOPE=0 ;
unsigned int Subprog ;
dtipo tipoTmp ;
int posParam;
int posProced;
dtipo listaParam[50];
int profun = 0;

entradaTS TS[MAX_TS] ;

typedef struct {
  int   atrib ;
  char  *lexema ;
  char  *nombre ;
  char  *codigo ;
  char  *codigoGlobal;
  char  *codigoProced;
  dtipo tipo ;
} atributos ;

#define YYSTYPE atributos

void mostrarErrorTipoInco(int pos, dtipo tipo);

void mostrarErrorOrden();

void mostrarErrorMinParam(char* nomProced);

void mostrarErrorMaxParam(char* nomProced);

void mostrarErrorProcedDesco(char* nomProced);

void mostrarErrorTipoAsig(dtipo tipo);

void errorNoDeclarado(char* lexema);

void errorYaDeclarado(char* lexema);

void errorTipoOperador(char* lexema);

void errorTipoOperador2(char* lexema, char* lexema2);

unsigned int procedMasProximo() {
  unsigned int pos = TOPE - 1;

  while(TS[pos].entrada != procedimiento) {
    pos -= 1;
  }

  return pos;
}

void TS_InsertaMARCA() {
  entradaTS aux = {marca, "", desconocido, 0, 0};
  unsigned int posEntradaProced;
  int numParam;

  TS[TOPE] = aux;
  TOPE += 1;

  if(Subprog == 1) {
    posEntradaProced = procedMasProximo();
    numParam = TS[posEntradaProced].parametrosMax;
    
    for(int i = 0; i < numParam; ++i) { 
      int pos = posEntradaProced + i + 1;    
      TS[TOPE] = TS[pos];
      TS[TOPE].entrada = variable;   
      TOPE += 1;
    } 
  }
}

void TS_InsertaPROCED(char* lexema) {
  entradaTS aux = {procedimiento, lexema, desconocido, 0, 0};
  TS[TOPE] = aux;
  TOPE = TOPE + 1;
}

void TS_InsertaVAR(char* lexema, dtipo tipo) {
  entradaTS aux = {variable, lexema, tipo, 0, 0};
  TS[TOPE] = aux;
  TOPE = TOPE + 1;
}

void TS_InsertaDescripControl(char* nombreVarControl, char* etiqEntrada, char* etiqSalida, char* etiqElse) {
  descriptorDeInstrControl descrip = {etiqEntrada,etiqSalida,etiqElse,nombreVarControl};
  entradaTS aux = {descripInstrControl, "", desconocido, 0, 0, descrip};
  TS[TOPE] = aux;
  TOPE = TOPE + 1;
}

void TS_InsertaPARAM(char* lexema, dtipo tipo) {
  entradaTS aux = {parametro_formal, lexema, tipo, 0, 0};
  TS[TOPE] = aux;
  TOPE = TOPE + 1;
  unsigned int pos = procedMasProximo();
  TS[pos].parametrosMin += 1;
  TS[pos].parametrosMax += 1;
}

void TS_InsertaPARAM_POR_DEF(char* lexema, dtipo tipo) {
  entradaTS aux = {parametro_formal, lexema, tipo, 0, 0};
  TS[TOPE] = aux;
  TOPE = TOPE + 1;
  unsigned int pos = procedMasProximo();
  TS[pos].parametrosMax += 1;
}

void TS_VaciarENTRADAS() {
  TOPE = TOPE - 1;
  while(TS[TOPE].entrada != marca) {
    TOPE = TOPE - 1;
  }
}

char* obtenerTipo(dtipo tipo) {
  if(tipo == entero) {
    return "int";
  }
  else if(tipo == real) {
    return "float";
  }
  else if(tipo == booleano) {
    return "bool";
  }
  else if(tipo == caracter) {
    return "char";
  }
}

char* generarTab() {
  char* salida = "";
  
  if(profun > 0){
    salida = (char*)malloc(strlen("\t")*profun + 1);
    strcpy(salida,"\t");
    for(int i = 1; i < profun; ++i) {
      strcat(salida, "\t");
    }
  }

  return salida;
}

descriptorDeInstrControl buscarDescrip() {
  int pos = TOPE - 1;
  while(TS[pos].entrada != descripInstrControl) {
    pos = pos - 1;
  }
  return TS[pos].descripControl;
}

int buscarProced(char* lexemaProced) {
  int pos = TOPE-1;
  while(pos >= 0 && strcmp(TS[pos].nombre, lexemaProced) != 0) {
    pos -= 1;
  }
  return pos;
}

void comprobarParam() {
  int i = 0;
  while(i < posParam) {
    dtipo tipo = TS[posProced + i + 1].tipoDato;

    if(tipo != listaParam[i]) {
      if(i < TS[posProced].parametrosMin) {
        mostrarErrorTipoInco(i, tipo);
        i += 1;
      }
      else {
        i += 1;
        if(i == TS[posProced].parametrosMax) {
          mostrarErrorOrden();
          i = posParam;
        }
      }
    }
    else {
      i += 1;
    }
  }
}

dtipo buscarTipoVariable(char* lexema){
  int pos = TOPE-1;
  while(pos > 0 && strcmp(TS[pos].nombre, lexema) != 0) {
    pos -= 1;
  }

  return TS[pos].tipoDato;
}

//comprueba si un lexama ha sido declarado
int declarado(char *lexema){
  int i = 0;
  
  while(i < TOPE){
    if (strcmp(TS[i].nombre,lexema) == 0){
      //printf("Se ha encontrado el lexema %s\n",lexema);
      return 1;
    }
      
    i+=1;
  }
  //printf("No se ha encontrado el lexema %s\n",lexema);
  return 0;
  
}

int enAmbito(char *lexema){
  int i = TOPE -1;

  while((strcmp(TS[i].nombre,"") != 0) && i > 0){
    if((strcmp(TS[i].nombre,lexema) == 0))
      return 1;
    i -= 1;

  }

  
  return 0;
}

bool esListaNumerica(dtipo tipo){
  return tipo == lista_entero || tipo == lista_real;
}

bool esLista(dtipo tipo){
  return esListaNumerica(tipo) || tipo == lista_caracter || tipo == lista_booleano;
}

bool esNumerico(dtipo tipo){
  return tipo == entero || tipo == real;
}

dtipo listaATipo(dtipo tipo) {
  if (tipo == lista_entero) {
    return entero;
  } else if (tipo == lista_real) {
    return real;
  } else if (tipo == lista_booleano) {
    return booleano;
  } else if (tipo == lista_caracter) {
    return caracter;
  } else {
    return entero;
  }
}

int tipoANumero(dtipo tipo) {
  switch (tipo) {
    case entero:
      return 0;
    break;
    case real:
      return 1;
    break;
    case lista_entero:
      return 2;
    break;
    case lista_real:
      return 3;
    break;
    default:
      return 99;
  }
}


char numero[10];
char *nombre;

int N_temp = 0;
char* temporal() {
  sprintf(numero, "%d", N_temp);
  N_temp += 1;
  nombre = "temp";
  char* salida = (char*)malloc(strlen(numero) + strlen(nombre) + 1);
  strcpy(salida,nombre);
  strcat(salida, numero);
  return salida;
}

int N_eti = 0;
char* etiqueta() {
  sprintf(numero, "%d", N_eti);
  
  N_eti += 1;
  nombre = "etiqueta";
  char* salida = (char*)malloc(strlen(numero) + strlen(nombre) + 1);
  
  strcpy(salida,nombre);
  strcat(salida, numero);
  
  return salida;
}

void generarCodNull(atributos *a) {
  a->codigo = (char*)malloc(strlen("") + 1);
  strcpy(a->codigo,"");
  a->nombre = (char*)malloc(strlen("") + 1);
  strcpy(a->nombre,"");
  a->codigoGlobal = (char*)malloc(strlen("") + 1);
  strcpy(a->codigoGlobal,"");
}

void generarCodPrograma(atributos *a, atributos *a1, atributos *a2) {
  a->codigo = (char*)malloc(strlen("#include <stdbool.h>\n#include <stdio.h>\n") + strlen("#include <math.h>\n\n") +strlen(a2->codigoGlobal) + strlen("\n") + strlen(a1->codigo) + strlen(a2->codigo) + 1);
  strcpy(a->codigo,"#include <stdbool.h>\n#include <stdio.h>\n");
  strcat(a->codigo,"#include <math.h>\n\n");
  strcat(a->codigo,a2->codigoGlobal);
  strcat(a->codigo,"\n");
  strcat(a->codigo,a1->codigo);
  strcat(a->codigo,a2->codigo);
  
  FILE *fichero;
  fichero = fopen("src/codInter.cpp", "w");
  fputs(a->codigo,fichero);
  fclose(fichero);
}

void generarCodCabeProg(atributos *a) {
  a->codigo = (char*)malloc(strlen("int main(int argc, char* argv[])\n") + 1);
  strcpy(a->codigo,"int main(int argc, char* argv[])\n");
}

void generarCodIniBloque(atributos *a) {
  char *tab = generarTab();
  a->codigo = (char*)malloc(strlen(tab) + strlen("{\n") + 1);
  strcpy(a->codigo,tab);
  strcat(a->codigo,"{\n");
}

char* etiquetaPrinf(dtipo tipo) {
   //TODO: Deberíamos de contemplar el tipo lista?
  switch(tipo) {
    case entero:
      return "%i";
    break;
    case real:
      return "%f";
    break;
    case booleano:
      return "%i";
    break;
    case caracter:
      return "%c";
    break;
  }
}

void generarCodMensajeExp(atributos *a, atributos *a1) {
  char *etiqPrintf = etiquetaPrinf(a1->tipo);
  char *tab = generarTab();
  a->codigo = (char*)malloc(strlen(a1->codigo) + strlen(tab) + strlen("printf(\"") + strlen(etiqPrintf) + strlen("\", ") + strlen(a1->nombre) + strlen(");\n") + 1);
  strcpy(a->codigo,a1->codigo);
  strcat(a->codigo, tab);
  strcat(a->codigo, "printf(\"");
  strcat(a->codigo, etiqPrintf);
  strcat(a->codigo, "\", ");
  strcat(a->codigo, a1->nombre);
  strcat(a->codigo, ");\n");
}

void generarCodMensajeCad(atributos *a, atributos *a1) {
  char *tab = generarTab();
  a->codigo = (char*)malloc(strlen(tab) + strlen("printf(\"%s\", ") + strlen(a1->lexema) + strlen(");\n") + 1);
  strcpy(a->codigo, tab);
  strcat(a->codigo, "printf(\"%s\", ");
  strcat(a->codigo, a1->lexema);
  strcat(a->codigo, ");\n");
}

void generarCodExpresion(atributos *a, atributos *a1, atributos *a2, atributos *a3, char* op){
  //generacion de codigo
  char *varTmp = temporal();
  char *tipoTmp = obtenerTipo(a->tipo);
  char *tab = generarTab();
  a->codigo = (char*)malloc(strlen(a1->codigo) + strlen(a3->codigo) + strlen(tab) + strlen(tipoTmp) + strlen(" ") + strlen(varTmp) + strlen(" = ") + strlen(a1->nombre) 
              + strlen(" ") + strlen(op) + strlen(" ") + strlen(a3->nombre) + strlen(";\n") + 1);


  strcpy(a->codigo,a1->codigo);
  strcat(a->codigo,a3->codigo);
  strcat(a->codigo,tab);
  strcat(a->codigo,tipoTmp);
  strcat(a->codigo," ");
  strcat(a->codigo,varTmp);
  strcat(a->codigo," = ");
  strcat(a->codigo,a1->nombre);
  strcat(a->codigo," ");
  strcat(a->codigo,op);
  strcat(a->codigo," ");
  
  strcat(a->codigo,a3->nombre);
  strcat(a->codigo,";\n");

  a->nombre = strdup(varTmp);
  printf("operador %s\n",op);
  printf("nombre: %s\n",a2->nombre);
  printf("codigo generado: \n%s\n",a->codigo);
}

void generarCodExpresionUnario(atributos *a, atributos *a1, atributos *a2, char* op){
  //generacion de codigo
  char *varTmp = temporal();
  char *tipoTmp = obtenerTipo(a->tipo);
  char *tab = generarTab();
  a->codigo = (char*)malloc(strlen(a2->codigo) + strlen(tab) + strlen(tipoTmp) + strlen(" ") + strlen(varTmp) + strlen(" = ") 
                    + strlen(op) + strlen(a2->nombre) + strlen(";\n") + 1);

  
  strcpy(a->codigo,a2->codigo);
  strcat(a->codigo,tab);
  strcat(a->codigo,tipoTmp);
  strcat(a->codigo," ");
  strcat(a->codigo,varTmp);
  strcat(a->codigo," = ");
  strcat(a->codigo,op);;
  strcat(a->codigo,a2->nombre);
  strcat(a->codigo,";\n");

  a->nombre = strdup(varTmp);
  printf("operador %s\n",op);
  printf("codigo generado: \n%s\n",a->codigo);
}

void potencia(atributos *a, atributos *a1, atributos *a2, atributos *a3){
  //generacion de codigo
  char *varTmp = temporal();
  char *tipoTmp = obtenerTipo(a->tipo);
  char *tab = generarTab();
  a->codigo = (char*)malloc(strlen(a1->codigo) + strlen(a3->codigo) + strlen(tab) + strlen(tipoTmp) + strlen(" ") + strlen(varTmp) + strlen(" = pow(") + strlen(a1->nombre) 
              + strlen(", ") + strlen(a3->nombre) + strlen(");\n") + 1);

  
  strcpy(a->codigo,a1->codigo);
  strcat(a->codigo,a3->codigo);
  strcat(a->codigo,tab);
  strcat(a->codigo,tipoTmp);
  strcat(a->codigo," ");
  strcat(a->codigo,varTmp);
  strcat(a->codigo," = pow(");
  strcat(a->codigo,a1->nombre);
  strcat(a->codigo,", ");  
  strcat(a->codigo,a3->nombre);
  strcat(a->codigo,");\n");

  a->nombre = strdup(varTmp);
  printf("codigo generado: \n%s\n",a->codigo);
}

void bucleWhile(atributos *a, atributos *a1, atributos *a2, atributos *a3, atributos *a4, atributos *a5){
  char *etiqSalida = etiqueta();
  char *etiqEntrada = etiqueta();
  //TS_InsertaDescripControl($2.nombre, etiqEntrada, etiqSalida, NULL);
  char *tab = generarTab();

  a->codigo = (char*)malloc(strlen(etiqEntrada) + strlen(": ;\n") + strlen(a3->codigo) + strlen(tab) + strlen("if (!") + strlen(a3->nombre) 
              + strlen(") goto ") + strlen(etiqSalida) + strlen(";\n") + strlen(a5->codigo) +strlen(tab)+strlen("goto ") + strlen(etiqEntrada) + strlen(";\n") + strlen(etiqSalida) + strlen(": ;\n")+ 1);

  
  strcpy(a->codigo,etiqEntrada);
  strcat(a->codigo,": ;\n");
  strcat(a->codigo,a3->codigo);

  strcat(a->codigo,tab);
  strcat(a->codigo,"if (!");
  strcat(a->codigo,a3->nombre);
  strcat(a->codigo,") goto ");
  strcat(a->codigo,etiqSalida);
  strcat(a->codigo,";\n");
  strcat(a->codigo,a5->codigo);
  strcat(a->codigo,tab);
  strcat(a->codigo,"goto ");
  strcat(a->codigo,etiqEntrada);
  strcat(a->codigo,";\n");
  strcat(a->codigo,etiqSalida);
  strcat(a->codigo,": ;\n");

}






/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 783 "src/y.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   438

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  47
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  31
/* YYNRULES -- Number of rules.  */
#define YYNRULES  83
/* YYNRULES -- Number of states.  */
#define YYNSTATES  169

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   301

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     6,    10,    12,    18,    23,    27,    29,
      35,    39,    45,    49,    52,    56,    57,    60,    62,    66,
      68,    70,    74,    78,    84,    87,    89,    92,    95,   102,
     107,   111,   113,   116,   118,   123,   125,   127,   129,   135,
     141,   145,   149,   151,   155,   159,   164,   169,   172,   177,
     181,   183,   187,   189,   191,   193,   196,   201,   205,   209,
     211,   215,   218,   221,   224,   227,   230,   234,   238,   242,
     246,   250,   254,   258,   262,   266,   270,   276,   278,   280,
     282,   284,   288,   290
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      48,     0,    -1,    49,    51,    -1,     3,    10,     9,    -1,
       4,    -1,    50,    55,    59,    63,     5,    -1,    50,    55,
      63,     5,    -1,    52,     6,    54,    -1,    54,    -1,    53,
       6,    54,    13,    29,    -1,    54,    13,    29,    -1,    53,
       6,    54,    13,    76,    -1,    54,    13,    76,    -1,    77,
      26,    -1,    14,    56,    15,    -1,    -1,    56,    57,    -1,
      57,    -1,    77,    58,    27,    -1,     1,    -1,    26,    -1,
      26,    13,    75,    -1,    58,     6,    26,    -1,    58,     6,
      26,    13,    75,    -1,    59,    60,    -1,    60,    -1,    62,
      51,    -1,     8,    26,    -1,    61,    10,    52,     6,    53,
       9,    -1,    61,    10,    52,     9,    -1,    61,    10,     9,
      -1,     1,    -1,    63,    65,    -1,    65,    -1,    19,    66,
      20,    75,    -1,    51,    -1,    66,    -1,    68,    -1,    17,
      10,    75,     9,    65,    -1,    64,    21,    75,    22,    65,
      -1,    23,    69,    27,    -1,    24,    70,    27,    -1,    73,
      -1,    75,    45,    27,    -1,    46,    75,    27,    -1,    26,
      13,    75,    27,    -1,    16,    10,    75,     9,    -1,    67,
      65,    -1,    67,    65,    18,    65,    -1,    69,     6,    26,
      -1,    26,    -1,    70,     6,    71,    -1,    71,    -1,    75,
      -1,    25,    -1,    26,    10,    -1,    72,    74,     9,    27,
      -1,    72,     9,    27,    -1,    74,     6,    75,    -1,    75,
      -1,    10,    75,     9,    -1,    41,    75,    -1,    42,    75,
      -1,    39,    75,    -1,    43,    75,    -1,    36,    75,    -1,
      75,    36,    75,    -1,    75,    41,    75,    -1,    75,    44,
      75,    -1,    75,    37,    75,    -1,    75,    38,    75,    -1,
      75,    34,    75,    -1,    75,    35,    75,    -1,    75,    31,
      75,    -1,    75,    32,    75,    -1,    75,    33,    75,    -1,
      75,    42,    75,    44,    75,    -1,    26,    -1,    76,    -1,
      29,    -1,     1,    -1,    11,    74,    12,    -1,    28,    -1,
       7,    28,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   674,   674,   678,   682,   688,   709,   726,   734,   741,
     751,   759,   770,   779,   788,   792,   797,   803,   808,   828,
     830,   838,   848,   858,   871,   876,   881,   894,   903,   915,
     924,   932,   934,   937,   940,   962,   965,   972,   976,   980,
    1007,  1013,  1019,  1032,  1033,  1035,  1060,  1081,  1090,  1111,
    1126,  1146,  1151,  1156,  1159,  1163,  1175,  1191,  1208,  1230,
    1249,  1250,  1258,  1266,  1274,  1285,  1293,  1328,  1335,  1342,
    1410,  1432,  1452,  1471,  1483,  1494,  1507,  1514,  1536,  1538,
    1564,  1566,  1568,  1585
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "PRINCIPAL", "LLAVEIZQ", "LLAVEDER",
  "COMA", "LISTADE", "PROCEDIMIENTO", "PARDER", "PARIZQ", "CORCHIZQ",
  "CORCHDER", "IGUAL", "INICIOVAR", "FINVAR", "SI", "MIENTRAS", "OTROCASO",
  "PARA", "HASTA", "ITERANDO", "HACER", "LEER", "IMPRIMIR", "CADENA", "ID",
  "PYC", "TIPOS", "CONSTANTE", "ELEM_POSI_BINA", "OR", "AND", "XOR",
  "IGUALDAD", "RELACION", "ADITIVOS", "MULTIPLICATIVOS", "POTENCIAS",
  "NOT", "UNARIOS", "DECRE_PRE", "INCRE_PRE", "UNARIO_PRE_LISTA",
  "ELEM_POSI", "MOV_LISTA", "DOLLAR", "$accept", "programa",
  "cabecera_programa", "inicio_bloque", "bloque", "lista_parametros",
  "lista_para_por_defecto", "parametro", "declar_de_variables_locales",
  "variables_locales", "cuerpo_declar_variables", "declar_variables",
  "declar_procedimientos", "declar_proced", "inicio_cabe_proced",
  "cabecera_proced", "sentencias", "cabecera_for", "sentencia",
  "sentencia_asignacion", "cabecera_if", "sentencia_if",
  "lista_identificadores", "mensajes", "mensaje", "inicio_llamada",
  "llamada_proced", "lista_expresiones", "expresion", "agregado_lista",
  "tipos", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    47,    48,    49,    50,    51,    51,    52,    52,    53,
      53,    53,    53,    54,    55,    55,    56,    56,    57,    57,
      58,    58,    58,    58,    59,    59,    60,    61,    62,    62,
      62,    62,    63,    63,    64,    65,    65,    65,    65,    65,
      65,    65,    65,    65,    65,    66,    67,    68,    68,    69,
      69,    70,    70,    71,    71,    72,    73,    73,    74,    74,
      75,    75,    75,    75,    75,    75,    75,    75,    75,    75,
      75,    75,    75,    75,    75,    75,    75,    75,    75,    75,
      75,    76,    77,    77
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     3,     1,     5,     4,     3,     1,     5,
       3,     5,     3,     2,     3,     0,     2,     1,     3,     1,
       1,     3,     3,     5,     2,     1,     2,     2,     6,     4,
       3,     1,     2,     1,     4,     1,     1,     1,     5,     5,
       3,     3,     1,     3,     3,     4,     4,     2,     4,     3,
       1,     3,     1,     1,     1,     2,     4,     3,     3,     1,
       3,     2,     2,     2,     2,     2,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     5,     1,     1,     1,
       1,     3,     1,     2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     1,     4,    15,     2,     3,
       0,     0,    19,     0,    82,     0,    17,     0,    80,     0,
       0,     0,     0,     0,     0,     0,     0,    77,    79,     0,
       0,     0,     0,     0,     0,    35,     0,    25,     0,     0,
       0,     0,    33,    36,     0,    37,     0,    42,     0,    78,
      83,    14,    16,    20,     0,    27,    80,    77,     0,     0,
      59,     0,     0,     0,     0,    50,     0,    54,     0,    52,
      53,    55,     0,    65,    63,    61,    62,    64,     0,    24,
       0,     0,    26,     6,    32,     0,    47,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    18,    60,     0,    81,     0,     0,     0,
       0,    40,     0,    41,     0,    44,     5,    30,     0,     8,
       0,     0,     0,    57,     0,    73,    74,    75,    71,    72,
      66,    69,    70,    67,     0,    68,    43,    21,    22,    58,
      46,     0,    34,    49,    51,    45,     0,    29,    13,     0,
      48,    56,     0,     0,    38,     0,     7,    39,    76,    23,
       0,    28,     0,     0,    10,    12,     0,     9,    11
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     7,    35,   118,   155,   119,    11,    15,
      16,    54,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    66,    68,    69,    46,    47,    59,    48,    49,
     120
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -142
static const yytype_int16 yypact[] =
{
      46,    41,    82,    79,    88,  -142,  -142,    90,  -142,  -142,
      89,    14,  -142,    75,  -142,    20,  -142,    85,   110,    94,
     196,   196,   111,   113,   102,   108,   174,     7,  -142,   196,
     196,   196,   196,   196,   196,  -142,    14,  -142,   125,    79,
      83,   118,  -142,  -142,   137,  -142,   185,  -142,   302,  -142,
    -142,  -142,  -142,   127,    -4,  -142,  -142,  -142,   209,    56,
     317,   196,   196,   131,   138,  -142,     1,  -142,    40,  -142,
     317,  -142,   196,    74,    74,    74,    66,   107,   272,  -142,
     126,    38,  -142,  -142,  -142,   196,   128,   130,    23,   196,
     196,   196,   196,   196,   196,   196,   196,   196,   196,   196,
     132,   196,   144,  -142,  -142,   196,  -142,   224,   239,   196,
     145,  -142,   174,  -142,   288,  -142,  -142,  -142,    55,  -142,
     148,   256,   137,  -142,   150,   344,   356,   367,   377,   386,
     394,   149,    74,    74,   331,   317,  -142,   317,   151,   317,
    -142,   137,   317,  -142,  -142,  -142,    52,  -142,  -142,   137,
    -142,  -142,   196,   196,  -142,    92,   168,  -142,   107,   317,
      52,  -142,     5,   169,  -142,  -142,    25,  -142,  -142
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -142,  -142,  -142,  -142,     0,  -142,  -142,  -141,  -142,  -142,
     173,  -142,  -142,   153,  -142,  -142,   156,  -142,   -36,   177,
    -142,  -142,  -142,  -142,    86,  -142,  -142,   158,   -20,   -71,
      48
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -32
static const yytype_int16 yytable[] =
{
      58,    60,   102,     8,    84,   156,    70,   110,    86,    73,
      74,    75,    76,    77,    78,    18,    21,    71,     6,   163,
      72,    12,    19,   103,    20,    21,    60,    13,   111,   105,
      22,    23,   124,    24,   164,    51,    21,    25,    26,    82,
      27,   107,   108,    28,    84,    13,   112,   117,    14,     1,
      29,     4,   114,    30,   167,    31,    32,    33,    17,    13,
      34,   146,   105,    17,   147,   121,    14,   113,   106,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
      14,   137,     5,     6,    56,   139,   150,     6,    83,   142,
      12,   165,    70,    20,    21,   168,    13,     9,   160,    22,
      23,   161,    24,    50,    10,   154,    25,    26,    98,    27,
      99,    53,    28,   157,   -31,    97,    98,    14,    99,    29,
      55,    61,    30,    62,    31,    32,    33,    56,    63,    34,
       6,   116,   158,   159,    65,    81,    20,    21,    56,    85,
     101,     6,    22,    23,    72,    24,   122,    20,    21,    25,
      26,    99,    27,    22,    23,    28,    24,   123,   109,   136,
      25,    26,    29,    27,   153,    30,    28,    31,    32,    33,
     138,   143,    34,    29,   148,    56,    30,   151,    31,    32,
      33,   162,   166,    34,    20,    21,    56,    96,    52,    79,
      97,    98,    80,    99,    87,    20,    21,    56,   144,    67,
      57,    64,     0,    28,    88,     0,    20,    21,     0,     0,
      29,    57,     0,    30,    28,    31,    32,    33,   104,     0,
       0,    29,    57,     0,    30,    28,    31,    32,    33,     0,
       0,     0,    29,   140,     0,    30,     0,    31,    32,    33,
      89,    90,    91,    92,    93,    94,    95,    96,   141,     0,
      97,    98,     0,    99,     0,    89,    90,    91,    92,    93,
      94,    95,    96,     0,     0,    97,    98,     0,    99,     0,
      89,    90,    91,    92,    93,    94,    95,    96,   149,     0,
      97,    98,     0,    99,     0,     0,     0,    89,    90,    91,
      92,    93,    94,    95,    96,     0,     0,    97,    98,   115,
      99,     0,     0,    89,    90,    91,    92,    93,    94,    95,
      96,     0,     0,    97,    98,   145,    99,     0,     0,    89,
      90,    91,    92,    93,    94,    95,    96,     0,     0,    97,
      98,     0,    99,    89,    90,    91,    92,    93,    94,    95,
      96,     0,     0,    97,    98,     0,    99,   100,    89,    90,
      91,    92,    93,    94,    95,    96,     0,     0,    97,    98,
       0,    99,    89,    90,    91,    92,    93,    94,    95,    96,
       0,     0,    97,    98,     0,   152,    90,    91,    92,    93,
      94,    95,    96,     0,     0,    97,    98,     0,    99,    91,
      92,    93,    94,    95,    96,     0,     0,    97,    98,     0,
      99,    92,    93,    94,    95,    96,     0,     0,    97,    98,
       0,    99,    93,    94,    95,    96,     0,     0,    97,    98,
       0,    99,    94,    95,    96,     0,     0,    97,    98,     0,
      99,    95,    96,     0,     0,    97,    98,     0,    99
};

static const yytype_int16 yycheck[] =
{
      20,    21,     6,     3,    40,   146,    26,     6,    44,    29,
      30,    31,    32,    33,    34,     1,    11,    10,     4,   160,
      13,     1,     8,    27,    10,    11,    46,     7,    27,     6,
      16,    17,     9,    19,    29,    15,    11,    23,    24,    39,
      26,    61,    62,    29,    80,     7,     6,     9,    28,     3,
      36,    10,    72,    39,    29,    41,    42,    43,    10,     7,
      46,     6,     6,    15,     9,    85,    28,    27,    12,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
      28,   101,     0,     4,     1,   105,   122,     4,     5,   109,
       1,   162,   112,    10,    11,   166,     7,     9,     6,    16,
      17,     9,    19,    28,    14,   141,    23,    24,    42,    26,
      44,    26,    29,   149,     4,    41,    42,    28,    44,    36,
      26,    10,    39,    10,    41,    42,    43,     1,    26,    46,
       4,     5,   152,   153,    26,    10,    10,    11,     1,    21,
      13,     4,    16,    17,    13,    19,    18,    10,    11,    23,
      24,    44,    26,    16,    17,    29,    19,    27,    20,    27,
      23,    24,    36,    26,    13,    39,    29,    41,    42,    43,
      26,    26,    46,    36,    26,     1,    39,    27,    41,    42,
      43,    13,    13,    46,    10,    11,     1,    38,    15,    36,
      41,    42,    36,    44,     9,    10,    11,     1,   112,    25,
      26,    24,    -1,    29,    46,    -1,    10,    11,    -1,    -1,
      36,    26,    -1,    39,    29,    41,    42,    43,     9,    -1,
      -1,    36,    26,    -1,    39,    29,    41,    42,    43,    -1,
      -1,    -1,    36,     9,    -1,    39,    -1,    41,    42,    43,
      31,    32,    33,    34,    35,    36,    37,    38,     9,    -1,
      41,    42,    -1,    44,    -1,    31,    32,    33,    34,    35,
      36,    37,    38,    -1,    -1,    41,    42,    -1,    44,    -1,
      31,    32,    33,    34,    35,    36,    37,    38,    22,    -1,
      41,    42,    -1,    44,    -1,    -1,    -1,    31,    32,    33,
      34,    35,    36,    37,    38,    -1,    -1,    41,    42,    27,
      44,    -1,    -1,    31,    32,    33,    34,    35,    36,    37,
      38,    -1,    -1,    41,    42,    27,    44,    -1,    -1,    31,
      32,    33,    34,    35,    36,    37,    38,    -1,    -1,    41,
      42,    -1,    44,    31,    32,    33,    34,    35,    36,    37,
      38,    -1,    -1,    41,    42,    -1,    44,    45,    31,    32,
      33,    34,    35,    36,    37,    38,    -1,    -1,    41,    42,
      -1,    44,    31,    32,    33,    34,    35,    36,    37,    38,
      -1,    -1,    41,    42,    -1,    44,    32,    33,    34,    35,
      36,    37,    38,    -1,    -1,    41,    42,    -1,    44,    33,
      34,    35,    36,    37,    38,    -1,    -1,    41,    42,    -1,
      44,    34,    35,    36,    37,    38,    -1,    -1,    41,    42,
      -1,    44,    35,    36,    37,    38,    -1,    -1,    41,    42,
      -1,    44,    36,    37,    38,    -1,    -1,    41,    42,    -1,
      44,    37,    38,    -1,    -1,    41,    42,    -1,    44
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    48,    49,    10,     0,     4,    50,    51,     9,
      14,    55,     1,     7,    28,    56,    57,    77,     1,     8,
      10,    11,    16,    17,    19,    23,    24,    26,    29,    36,
      39,    41,    42,    43,    46,    51,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    72,    73,    75,    76,
      28,    15,    57,    26,    58,    26,     1,    26,    75,    74,
      75,    10,    10,    26,    66,    26,    69,    25,    70,    71,
      75,    10,    13,    75,    75,    75,    75,    75,    75,    60,
      63,    10,    51,     5,    65,    21,    65,     9,    74,    31,
      32,    33,    34,    35,    36,    37,    38,    41,    42,    44,
      45,    13,     6,    27,     9,     6,    12,    75,    75,    20,
       6,    27,     6,    27,    75,    27,     5,     9,    52,    54,
      77,    75,    18,    27,     9,    75,    75,    75,    75,    75,
      75,    75,    75,    75,    75,    75,    27,    75,    26,    75,
       9,     9,    75,    26,    71,    27,     6,     9,    26,    22,
      65,    27,    44,    13,    65,    53,    54,    65,    75,    75,
       6,     9,    13,    54,    29,    76,    13,    29,    76
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 674 "src/practica5.y"
    {  
                                          generarCodPrograma(&(yyval), &(yyvsp[(1) - (2)]), &(yyvsp[(2) - (2)]));
                                       ;}
    break;

  case 3:
#line 678 "src/practica5.y"
    { 
                                                generarCodCabeProg(&(yyval));
                                              ;}
    break;

  case 4:
#line 682 "src/practica5.y"
    { 
                            TS_InsertaMARCA();
                            generarCodIniBloque(&(yyval));
                            profun += 1;
                          ;}
    break;

  case 5:
#line 692 "src/practica5.y"
    { 
                      TS_VaciarENTRADAS();

                      profun -= 1;
                      char *tab = generarTab();

                      (yyval).codigoGlobal = (char*)malloc(strlen((yyvsp[(2) - (5)]).codigoGlobal) + 1);
                      strcpy((yyval).codigoGlobal,(yyvsp[(2) - (5)]).codigoGlobal);

                      (yyval).codigo = (char*)malloc(strlen((yyvsp[(1) - (5)]).codigo) + strlen((yyvsp[(2) - (5)]).codigo) + strlen((yyvsp[(3) - (5)]).codigo) + strlen((yyvsp[(4) - (5)]).codigo) + strlen(tab) + strlen("}\n") + 1);
                      strcpy((yyval).codigo,(yyvsp[(1) - (5)]).codigo);
                      strcat((yyval).codigo,(yyvsp[(2) - (5)]).codigo);
                      strcat((yyval).codigo, (yyvsp[(3) - (5)]).codigo);
                      strcat((yyval).codigo,(yyvsp[(4) - (5)]).codigo);
                      strcat((yyval).codigo,tab);
                      strcat((yyval).codigo,"}\n"); 
                    ;}
    break;

  case 6:
#line 712 "src/practica5.y"
    { TS_VaciarENTRADAS();
                     profun -= 1;
                     char *tab = generarTab();
                     (yyval).codigo = (char*)malloc(strlen((yyvsp[(1) - (4)]).codigo) + strlen((yyvsp[(2) - (4)]).codigo) + strlen((yyvsp[(3) - (4)]).codigo) + strlen(tab) + strlen("}\n") + 1);
                     (yyval).codigoGlobal = (char*)malloc(strlen((yyvsp[(2) - (4)]).codigoGlobal) + 1);
                     strcpy((yyval).codigoGlobal,(yyvsp[(2) - (4)]).codigoGlobal);

                     strcpy((yyval).codigo,(yyvsp[(1) - (4)]).codigo);
                     strcat((yyval).codigo,(yyvsp[(2) - (4)]).codigo);
                     strcat((yyval).codigo,(yyvsp[(3) - (4)]).codigo);
                     strcat((yyval).codigo,tab);
                     strcat((yyval).codigo,"}\n"); 
                   ;}
    break;

  case 7:
#line 726 "src/practica5.y"
    { 
                                                        TS_InsertaPARAM((yyvsp[(3) - (3)]).lexema, (yyvsp[(3) - (3)]).tipo);

                                                        (yyval).codigo = (char*)malloc(strlen((yyvsp[(1) - (3)]).codigo) + strlen(", ") + strlen((yyvsp[(3) - (3)]).codigo) + 1);
                                                        strcpy((yyval).codigo, (yyvsp[(1) - (3)]).codigo);
                                                        strcat((yyval).codigo, ", ");
                                                        strcat((yyval).codigo, (yyvsp[(3) - (3)]).codigo);
                                                      ;}
    break;

  case 8:
#line 734 "src/practica5.y"
    { 
                                  TS_InsertaPARAM((yyvsp[(1) - (1)]).lexema, (yyvsp[(1) - (1)]).tipo); 

                                  (yyval).codigo = (char*)malloc(strlen((yyvsp[(1) - (1)]).codigo) + 1);
                                  strcpy((yyval).codigo, (yyvsp[(1) - (1)]).codigo);
                                ;}
    break;

  case 9:
#line 741 "src/practica5.y"
    { 
                            TS_InsertaPARAM_POR_DEF((yyvsp[(3) - (5)]).lexema, (yyvsp[(3) - (5)]).tipo); 

                            (yyval).codigo = (char*)malloc(strlen((yyvsp[(1) - (5)]).codigo) + strlen(", ") + strlen((yyvsp[(3) - (5)]).codigo) + strlen(" = ") + strlen((yyvsp[(5) - (5)]).lexema) + 1);
                            strcpy((yyval).codigo, (yyvsp[(1) - (5)]).codigo);
                            strcat((yyval).codigo, ", ");
                            strcat((yyval).codigo, (yyvsp[(3) - (5)]).codigo);
                            strcat((yyval).codigo, " = ");
                            strcat((yyval).codigo, (yyvsp[(5) - (5)]).lexema);
                                                                                ;}
    break;

  case 10:
#line 751 "src/practica5.y"
    { 
                                                      TS_InsertaPARAM_POR_DEF((yyvsp[(1) - (3)]).lexema, (yyvsp[(1) - (3)]).tipo); 

                                                      (yyval).codigo = (char*)malloc(strlen((yyvsp[(1) - (3)]).codigo) + strlen(" = ") + strlen((yyvsp[(3) - (3)]).lexema));
                                                      strcat((yyval).codigo, (yyvsp[(1) - (3)]).codigo);
                                                      strcat((yyval).codigo, " = ");
                                                      strcat((yyval).codigo, (yyvsp[(3) - (3)]).lexema);
                                                    ;}
    break;

  case 11:
#line 759 "src/practica5.y"
    { 
                                                                                        TS_InsertaPARAM_POR_DEF((yyvsp[(3) - (5)]).lexema, (yyvsp[(3) - (5)]).tipo); 

                                                                                        (yyval).codigo = (char*)malloc(strlen((yyvsp[(1) - (5)]).codigo) + strlen(", ")
                                                                                        + strlen((yyvsp[(3) - (5)]).codigo) + strlen(" = ") + strlen((yyvsp[(5) - (5)]).codigo) + 1);
                                                                                        strcpy((yyval).codigo, (yyvsp[(1) - (5)]).codigo);
                                                                                        strcat((yyval).codigo, ", ");
                                                                                        strcat((yyval).codigo, (yyvsp[(3) - (5)]).codigo);
                                                                                        strcat((yyval).codigo, " = ");
                                                                                        strcat((yyval).codigo, (yyvsp[(5) - (5)]).codigo);
                                                                                      ;}
    break;

  case 12:
#line 770 "src/practica5.y"
    { 
                                                            TS_InsertaPARAM_POR_DEF((yyvsp[(1) - (3)]).lexema, (yyvsp[(1) - (3)]).tipo); 

                                                            (yyval).codigo = (char*)malloc(strlen((yyvsp[(1) - (3)]).codigo) + strlen(" = ") + strlen((yyvsp[(3) - (3)]).codigo));
                                                            strcat((yyval).codigo, (yyvsp[(1) - (3)]).codigo);
                                                            strcat((yyval).codigo, " = ");
                                                            strcat((yyval).codigo, (yyvsp[(3) - (3)]).codigo);
                                                          ;}
    break;

  case 13:
#line 779 "src/practica5.y"
    { 
                          (yyval).tipo = tipoTmp; (yyval).lexema = (yyvsp[(2) - (2)]).lexema; 

                          (yyval).codigo = (char*)malloc(strlen((yyvsp[(1) - (2)]).codigo) + strlen(" ") + strlen((yyvsp[(2) - (2)]).lexema) + 1);
                          strcpy((yyval).codigo, (yyvsp[(1) - (2)]).codigo);
                          strcat((yyval).codigo, " ");
                          strcat((yyval).codigo, (yyvsp[(2) - (2)]).lexema);
                        ;}
    break;

  case 14:
#line 788 "src/practica5.y"
    { (yyval).codigo = (char*)malloc(strlen((yyvsp[(2) - (3)]).codigo) + 1);
                                                                   (yyval).codigoGlobal = (char*)malloc(strlen((yyvsp[(2) - (3)]).codigoGlobal) + 1);
                                                                   strcpy((yyval).codigoGlobal,(yyvsp[(2) - (3)]).codigoGlobal);
                                                                   strcpy((yyval).codigo,(yyvsp[(2) - (3)]).codigo); ;}
    break;

  case 15:
#line 792 "src/practica5.y"
    { (yyval).codigo = (char*)malloc(strlen("") + 1);
                                (yyval).codigoGlobal = (char*)malloc(strlen("") + 1);
                                strcpy((yyval).codigoGlobal,"");
                                strcpy((yyval).codigo,""); ;}
    break;

  case 16:
#line 797 "src/practica5.y"
    { (yyval).codigo = (char*)malloc(strlen((yyvsp[(1) - (2)]).codigo) + strlen((yyvsp[(2) - (2)]).codigo) + 1);
                                                                  (yyval).codigoGlobal = (char*)malloc(strlen((yyvsp[(1) - (2)]).codigoGlobal) + strlen((yyvsp[(2) - (2)]).codigoGlobal) + 1);
                                                                  strcpy((yyval).codigoGlobal,(yyvsp[(1) - (2)]).codigoGlobal);
                                                                  strcat((yyval).codigoGlobal,(yyvsp[(2) - (2)]).codigoGlobal);
                                                                  strcpy((yyval).codigo,(yyvsp[(1) - (2)]).codigo);
                                                                  strcat((yyval).codigo,(yyvsp[(2) - (2)]).codigo); ;}
    break;

  case 17:
#line 803 "src/practica5.y"
    { (yyval).codigo = (char*)malloc(strlen((yyvsp[(1) - (1)]).codigo) + 1);
                                                (yyval).codigoGlobal = (char*)malloc(strlen((yyvsp[(1) - (1)]).codigoGlobal) + 1);
                                                strcpy((yyval).codigoGlobal,(yyvsp[(1) - (1)]).codigoGlobal);
                                                strcpy((yyval).codigo,(yyvsp[(1) - (1)]).codigo); ;}
    break;

  case 18:
#line 808 "src/practica5.y"
    { if(profun > 1) {
                                                         char *tab = generarTab();
                                                         (yyval).codigo = (char*)malloc(strlen(tab) + strlen((yyvsp[(1) - (3)]).codigo) + strlen(" ") + strlen((yyvsp[(2) - (3)]).codigo) + strlen(";\n") + 1);
                                                         (yyval).codigoGlobal = (char*)malloc(strlen("") + 1);
                                                         strcpy((yyval).codigoGlobal,"");
                                                         strcpy((yyval).codigo,tab);
                                                         strcat((yyval).codigo,(yyvsp[(1) - (3)]).codigo);
                                                         strcat((yyval).codigo, " ");
                                                         strcat((yyval).codigo, (yyvsp[(2) - (3)]).codigo);
                                                         strcat((yyval).codigo, ";\n");
                                                       }
                                                       else {
                                                         (yyval).codigoGlobal = (char*)malloc(strlen((yyvsp[(1) - (3)]).codigo) + strlen(" ") + strlen((yyvsp[(2) - (3)]).codigo) + strlen(";\n") + 1);
                                                         (yyval).codigo = (char*)malloc(strlen("") + 1);
                                                         strcpy((yyval).codigo,"");
                                                         strcpy((yyval).codigoGlobal,(yyvsp[(1) - (3)]).codigo);
                                                         strcat((yyval).codigoGlobal, " ");
                                                         strcat((yyval).codigoGlobal, (yyvsp[(2) - (3)]).codigo);
                                                         strcat((yyval).codigoGlobal, ";\n");
                                                       } ;}
    break;

  case 20:
#line 830 "src/practica5.y"
    {  if(enAmbito((yyvsp[(1) - (1)]).lexema) == 1)
                              errorYaDeclarado((yyvsp[(1) - (1)]).lexema);
                            else
                              TS_InsertaVAR((yyvsp[(1) - (1)]).lexema, tipoTmp);
                            
                            (yyval).codigo = (char*)malloc(strlen((yyvsp[(1) - (1)]).lexema) + 1);
                            strcpy((yyval).codigo,(yyvsp[(1) - (1)]).lexema);
                          ;}
    break;

  case 21:
#line 838 "src/practica5.y"
    {  if(enAmbito((yyvsp[(1) - (3)]).lexema) == 1)
                                              errorYaDeclarado((yyvsp[(1) - (3)]).lexema);
                                            else
                                              TS_InsertaVAR((yyvsp[(1) - (3)]).lexema, tipoTmp);
                                            
                                            (yyval).codigo = (char*)malloc(strlen((yyvsp[(1) - (3)]).lexema) + strlen(" = ") + strlen((yyvsp[(3) - (3)]).lexema) + 1);
                                            strcpy((yyval).codigo,(yyvsp[(1) - (3)]).lexema);
                                            strcat((yyval).codigo," = ");
                                            strcat((yyval).codigo,(yyvsp[(3) - (3)]).lexema);
                                         ;}
    break;

  case 22:
#line 848 "src/practica5.y"
    {  if(enAmbito((yyvsp[(3) - (3)]).lexema) == 1)
                                                    errorYaDeclarado((yyvsp[(3) - (3)]).lexema);
                                                  else
                                                    TS_InsertaVAR((yyvsp[(3) - (3)]).lexema, tipoTmp);
                                                  
                                                  (yyval).codigo = (char*)malloc(strlen((yyvsp[(1) - (3)]).codigo) + strlen(", ") + strlen((yyvsp[(3) - (3)]).lexema) + 1);
                                                  strcpy((yyval).codigo,(yyvsp[(1) - (3)]).codigo);
                                                  strcat((yyval).codigo,", ");
                                                  strcat((yyval).codigo,(yyvsp[(3) - (3)]).lexema);
                                                ;}
    break;

  case 23:
#line 858 "src/practica5.y"
    {  if(enAmbito((yyvsp[(3) - (5)]).lexema) == 1)
                                                                    errorYaDeclarado((yyvsp[(3) - (5)]).lexema);
                                                                  else
                                                                    TS_InsertaVAR((yyvsp[(3) - (5)]).lexema, tipoTmp);
                                                                    
                                                                  (yyval).codigo = (char*)malloc(strlen((yyvsp[(1) - (5)]).codigo) + strlen(", ") + strlen((yyvsp[(3) - (5)]).lexema) + strlen(" = ") + strlen((yyvsp[(5) - (5)]).lexema) + 1);
                                                                  strcpy((yyval).codigo,(yyvsp[(1) - (5)]).codigo);
                                                                  strcat((yyval).codigo,", ");
                                                                  strcat((yyval).codigo,(yyvsp[(3) - (5)]).lexema);
                                                                  strcat((yyval).codigo," = ");
                                                                  strcat((yyval).codigo,(yyvsp[(5) - (5)]).lexema);
                                                                  ;}
    break;

  case 24:
#line 871 "src/practica5.y"
    {
                                                              (yyval).codigo = (char*)malloc(strlen((yyvsp[(1) - (2)]).codigo) + strlen((yyvsp[(2) - (2)]).codigo) + 1);
                                                              strcpy((yyval).codigo, (yyvsp[(1) - (2)]).codigo);
                                                              strcat((yyval).codigo, (yyvsp[(2) - (2)]).codigo);
                                                            ;}
    break;

  case 25:
#line 876 "src/practica5.y"
    {
                                        (yyval).codigo = (char*)malloc(strlen((yyvsp[(1) - (1)]).codigo) + 1);
                                        strcpy((yyval).codigo, (yyvsp[(1) - (1)]).codigo);
                                      ;}
    break;

  case 26:
#line 881 "src/practica5.y"
    { 
                                          Subprog = 0; 

                                          char *tab = generarTab();
                                          (yyval).codigo = (char*)malloc(strlen(tab) + strlen((yyvsp[(1) - (2)]).codigo) + strlen("\n") + strlen((yyvsp[(2) - (2)]).codigo) + strlen(";\n\n") + 1);
                                          strcpy((yyval).codigo, tab);
                                          strcat((yyval).codigo, (yyvsp[(1) - (2)]).codigo);
                                          strcat((yyval).codigo, "\n");
                                          strcat((yyval).codigo, (yyvsp[(2) - (2)]).codigo);
                                          strcat((yyval).codigo, tab);
                                          strcat((yyval).codigo, ";\n\n");
                                        ;}
    break;

  case 27:
#line 894 "src/practica5.y"
    { 
                                        TS_InsertaPROCED((yyvsp[(2) - (2)]).lexema); 

                                        (yyval).codigo = (char*)malloc(strlen("auto ") + strlen((yyvsp[(2) - (2)]).lexema) + strlen("= [=] ") + 1);
                                        strcpy((yyval).codigo, "auto ");
                                        strcat((yyval).codigo, (yyvsp[(2) - (2)]).lexema);
                                        strcat((yyval).codigo, "= [=] ");
                                      ;}
    break;

  case 28:
#line 903 "src/practica5.y"
    { 
                                                                                                  Subprog = 1; 

                                                                                                  (yyval).codigo = (char*)malloc(strlen((yyvsp[(1) - (6)]).codigo) + strlen(" (") + strlen((yyvsp[(3) - (6)]).codigo)
                                                                                                                     + strlen(", ") + strlen((yyvsp[(5) - (6)]).codigo) + strlen(") ") + 1);
                                                                                                  strcpy((yyval).codigo, (yyvsp[(1) - (6)]).codigo);
                                                                                                  strcat((yyval).codigo, " (");
                                                                                                  strcat((yyval).codigo, (yyvsp[(3) - (6)]).codigo);
                                                                                                  strcat((yyval).codigo, ", ");
                                                                                                  strcat((yyval).codigo, (yyvsp[(5) - (6)]).codigo);
                                                                                                  strcat((yyval).codigo, ") ");
                                                                                                ;}
    break;

  case 29:
#line 915 "src/practica5.y"
    { 
                                                                      Subprog = 1; 

                                                                      (yyval).codigo = (char*)malloc(strlen((yyvsp[(1) - (4)]).codigo) + strlen("(") + strlen((yyvsp[(3) - (4)]).codigo) + strlen(")") + 1);
                                                                      strcpy((yyval).codigo, (yyvsp[(1) - (4)]).codigo);
                                                                      strcat((yyval).codigo, "(");
                                                                      strcat((yyval).codigo, (yyvsp[(3) - (4)]).codigo);
                                                                      strcat((yyval).codigo, ")");
                                                                    ;}
    break;

  case 30:
#line 924 "src/practica5.y"
    { 
                                                      Subprog = 1; 

                                                      (yyval).codigo = (char*)malloc(strlen((yyvsp[(1) - (3)]).codigo) + strlen(" (") + strlen(") ") + 1);
                                                      strcpy((yyval).codigo, (yyvsp[(1) - (3)]).codigo);
                                                      strcat((yyval).codigo, " (");
                                                      strcat((yyval).codigo, ") ");
                                                    ;}
    break;

  case 32:
#line 934 "src/practica5.y"
    { (yyval).codigo = (char*)malloc(strlen((yyvsp[(1) - (2)]).codigo) + strlen((yyvsp[(2) - (2)]).codigo) + 1);
                                     strcpy((yyval).codigo,(yyvsp[(1) - (2)]).codigo);
                                     strcat((yyval).codigo,(yyvsp[(2) - (2)]).codigo); ;}
    break;

  case 33:
#line 937 "src/practica5.y"
    { (yyval).codigo = (char*)malloc(strlen((yyvsp[(1) - (1)]).codigo) + 1);
                          strcpy((yyval).codigo,(yyvsp[(1) - (1)]).codigo); ;}
    break;

  case 34:
#line 941 "src/practica5.y"
    { char *etiqSalida = etiqueta();
                        char *etiqEntrada = etiqueta();
                        TS_InsertaDescripControl((yyvsp[(2) - (4)]).nombre, etiqEntrada, etiqSalida, NULL);
                        char *tab = generarTab();
                        
                        (yyval).codigo = (char*)malloc(strlen((yyvsp[(2) - (4)]).codigo) + strlen(etiqEntrada) + strlen(": ;\n") + strlen((yyvsp[(4) - (4)]).codigo) + strlen(tab) + strlen("if (!") + strlen((yyvsp[(4) - (4)]).nombre) 
                                    + strlen(") goto ") + strlen(etiqSalida) + strlen(";\n") + 1);
                        
                        strcpy((yyval).codigo,(yyvsp[(2) - (4)]).codigo);
                        strcat((yyval).codigo,etiqEntrada);
                        strcat((yyval).codigo,": ;\n");
                        strcat((yyval).codigo,(yyvsp[(4) - (4)]).codigo);
                        
                        strcat((yyval).codigo,tab);
                        strcat((yyval).codigo,"if (!");
                        strcat((yyval).codigo,(yyvsp[(4) - (4)]).nombre);
                        strcat((yyval).codigo,") goto ");
                        strcat((yyval).codigo,etiqSalida);
                        strcat((yyval).codigo,";\n");
                      ;}
    break;

  case 35:
#line 962 "src/practica5.y"
    {  (yyval).codigo = (char*)malloc(strlen((yyvsp[(1) - (1)]).codigo) + 1);
                        strcpy((yyval).codigo,(yyvsp[(1) - (1)]).codigo);
                     ;}
    break;

  case 36:
#line 965 "src/practica5.y"
    { char *tab = generarTab();
                                     (yyval).codigo = (char*)malloc(strlen(tab) + strlen("{\n") + strlen((yyvsp[(1) - (1)]).codigo) + strlen(tab) + strlen("}\n\n") + 1);
                                     strcpy((yyval).codigo,tab);
                                     strcat((yyval).codigo,"{\n");
                                     strcat((yyval).codigo,(yyvsp[(1) - (1)]).codigo);
                                     strcat((yyval).codigo,tab);
                                     strcat((yyval).codigo,"}\n\n"); ;}
    break;

  case 37:
#line 972 "src/practica5.y"
    {  (yyval).codigo = (char*)malloc(strlen((yyvsp[(1) - (1)]).codigo) + strlen("\n") + 1);
                              strcpy((yyval).codigo,(yyvsp[(1) - (1)]).codigo);
                              strcat((yyval).codigo,"\n");
                           ;}
    break;

  case 38:
#line 977 "src/practica5.y"
    {
              bucleWhile(&(yyval),&(yyvsp[(1) - (5)]),&(yyvsp[(2) - (5)]),&(yyvsp[(3) - (5)]),&(yyvsp[(4) - (5)]),&(yyvsp[(5) - (5)]));
            ;}
    break;

  case 39:
#line 981 "src/practica5.y"
    { char *tab = generarTab();
                                    descriptorDeInstrControl descrip = buscarDescrip();
                                    (yyval).codigo = (char*)malloc(strlen((yyvsp[(1) - (5)]).codigo) + strlen(tab) + strlen("{\n") + strlen((yyvsp[(5) - (5)]).codigo) + strlen((yyvsp[(3) - (5)]).codigo) + strlen(tab) 
                                                + strlen(descrip.nombreVarControl) + strlen(" += ") + strlen((yyvsp[(3) - (5)]).nombre) + strlen(";\n") + strlen(tab) + strlen("goto ") 
                                                + strlen(descrip.etiquetaEntrada) + strlen(";\n") + strlen(tab) + strlen("}\n") + strlen(descrip.etiquetaSalida) + strlen(": ;\n\n") + 1);
                                    strcpy((yyval).codigo,(yyvsp[(1) - (5)]).codigo);
                                    strcat((yyval).codigo,tab);
                                    strcat((yyval).codigo,"{\n");
                                    strcat((yyval).codigo,(yyvsp[(5) - (5)]).codigo);
                                    strcat((yyval).codigo,(yyvsp[(3) - (5)]).codigo);
                                    strcat((yyval).codigo,tab);
                                    strcat((yyval).codigo,descrip.nombreVarControl);
                                    strcat((yyval).codigo," += ");
                                    strcat((yyval).codigo,(yyvsp[(3) - (5)]).nombre);
                                    strcat((yyval).codigo,";\n");
                                    strcat((yyval).codigo,tab);
                                    strcat((yyval).codigo,"goto ");
                                    strcat((yyval).codigo,descrip.etiquetaEntrada);
                                    strcat((yyval).codigo,";\n");
                                    strcat((yyval).codigo,tab);
                                    strcat((yyval).codigo,"}\n");
                                    strcat((yyval).codigo,descrip.etiquetaSalida);
                                    strcat((yyval).codigo,": ;\n\n");

                                    TOPE -= 1;
                                  ;}
    break;

  case 40:
#line 1007 "src/practica5.y"
    {
                                                (yyval).codigo = (char*)malloc(strlen((yyvsp[(2) - (3)]).codigo) + strlen("\n") + 1);
                                                strcpy((yyval).codigo,(yyvsp[(2) - (3)]).codigo);
                                                strcat((yyval).codigo,"\n");
                                              ;}
    break;

  case 41:
#line 1013 "src/practica5.y"
    {
                                      (yyval).codigo = (char*)malloc(strlen("{\n") + strlen((yyvsp[(2) - (3)]).codigo) + strlen("\n}\n") + 1);
                                      strcat((yyval).codigo,"{\n");
                                      strcat((yyval).codigo,(yyvsp[(2) - (3)]).codigo);
                                      strcat((yyval).codigo,"\n}\n");
                                    ;}
    break;

  case 42:
#line 1019 "src/practica5.y"
    {
                                char *tab = generarTab();
                                (yyval).codigo = (char*)malloc(strlen(tab) + strlen("{\n") + strlen((yyvsp[(1) - (1)]).codigoProced) + strlen(tab) 
                                + strlen((yyvsp[(1) - (1)]).codigo) + strlen("\n") + strlen(tab) + strlen("}\n\n") + 1);
                                strcpy((yyval).codigo,tab);
                                strcat((yyval).codigo,"{\n");
                                strcat((yyval).codigo,(yyvsp[(1) - (1)]).codigoProced);
                                strcat((yyval).codigo,tab);
                                strcat((yyval).codigo,(yyvsp[(1) - (1)]).codigo);
                                strcat((yyval).codigo,"\n");
                                strcat((yyval).codigo,tab);
                                strcat((yyval).codigo,"}\n\n");
                              ;}
    break;

  case 43:
#line 1032 "src/practica5.y"
    {if (esLista((yyvsp[(1) - (3)]).tipo)) { (yyval).tipo = (yyvsp[(1) - (3)]).tipo; } else {errorTipoOperador((yyvsp[(2) - (3)]).lexema); };}
    break;

  case 44:
#line 1033 "src/practica5.y"
    {if (esLista((yyvsp[(2) - (3)]).tipo)) { (yyval).tipo = (yyvsp[(2) - (3)]).tipo; } else {errorTipoOperador((yyvsp[(1) - (3)]).lexema); };}
    break;

  case 45:
#line 1035 "src/practica5.y"
    {
                                                if (declarado((yyvsp[(1) - (4)]).lexema) == 0) {
                                                  errorNoDeclarado((yyvsp[(1) - (4)]).lexema);
                                                }
                                                else {
                                                  if ((yyvsp[(1) - (4)]).tipo == entero && (yyvsp[(3) - (4)]).tipo == real) {

                                                  } else if ((yyvsp[(1) - (4)]).tipo == real && (yyvsp[(3) - (4)]).tipo == entero) {

                                                  } else if (buscarTipoVariable((yyvsp[(1) - (4)]).lexema) != (yyvsp[(3) - (4)]).tipo){
                                                    mostrarErrorTipoAsig((yyvsp[(3) - (4)]).tipo);
                                                  }
                                                }

                                                char *tab = generarTab();
                                                (yyval).nombre = strdup((yyvsp[(1) - (4)]).lexema);
                                                (yyval).codigo = (char*)malloc(strlen((yyvsp[(3) - (4)]).codigo) + strlen(tab) + strlen((yyvsp[(1) - (4)]).lexema) + strlen(" = ") + strlen((yyvsp[(3) - (4)]).nombre) + strlen(";\n") + 1);
                                                strcpy((yyval).codigo,(yyvsp[(3) - (4)]).codigo);
                                                strcat((yyval).codigo,tab);
                                                strcat((yyval).codigo,(yyvsp[(1) - (4)]).lexema);
                                                strcat((yyval).codigo," = ");
                                                strcat((yyval).codigo,(yyvsp[(3) - (4)]).nombre);
                                                strcat((yyval).codigo,";\n");
                                                ;}
    break;

  case 46:
#line 1060 "src/practica5.y"
    { char *etiqSalida = etiqueta();
                                           
                                           char *etiqElse = etiqueta();
                                           
                                           TS_InsertaDescripControl(NULL, NULL, etiqSalida, etiqElse);
                                           
                                           char *tab = generarTab();

                                           

                                           (yyval).codigo = (char*)malloc(strlen((yyvsp[(3) - (4)]).codigo) + strlen(tab) + strlen("if (!") + strlen((yyvsp[(3) - (4)]).nombre) + strlen(") goto ") + strlen(etiqElse) + strlen(";\n") + 1);
                                           
                                           strcpy((yyval).codigo,(yyvsp[(3) - (4)]).codigo);
                                           strcat((yyval).codigo,tab);
                                           strcat((yyval).codigo,"if (!");
                                           strcat((yyval).codigo,(yyvsp[(3) - (4)]).nombre);
                                           strcat((yyval).codigo,") goto ");
                                           strcat((yyval).codigo,etiqElse);
                                           strcat((yyval).codigo,";\n");
                                         ;}
    break;

  case 47:
#line 1081 "src/practica5.y"
    { descriptorDeInstrControl descrip = buscarDescrip();
                                          (yyval).codigo = (char*)malloc(strlen((yyvsp[(1) - (2)]).codigo) + strlen((yyvsp[(2) - (2)]).codigo) + strlen(descrip.etiquetaElse) + strlen(": ;\n") + 1);
                                          strcpy((yyval).codigo,(yyvsp[(1) - (2)]).codigo);
                                          strcat((yyval).codigo,(yyvsp[(2) - (2)]).codigo);
                                          strcat((yyval).codigo,descrip.etiquetaElse);
                                          strcat((yyval).codigo,": ;\n");

                                          TOPE -= 1; 
                                        ;}
    break;

  case 48:
#line 1091 "src/practica5.y"
    {  descriptorDeInstrControl descrip = buscarDescrip();
                                        char *tab = generarTab();
                                        (yyval).codigo = (char*)malloc(strlen((yyvsp[(1) - (4)]).codigo) + strlen((yyvsp[(2) - (4)]).codigo) + strlen(tab) + strlen("goto ") + strlen(descrip.etiquetaSalida)
                                                     + strlen(";\n") + strlen(descrip.etiquetaElse) + strlen(": ;\n") + strlen((yyvsp[(4) - (4)]).codigo) + strlen(descrip.etiquetaSalida)
                                                     + strlen(": ;\n") + 1);
                                        strcpy((yyval).codigo,(yyvsp[(1) - (4)]).codigo);
                                        strcat((yyval).codigo,(yyvsp[(2) - (4)]).codigo);
                                        strcat((yyval).codigo,tab);
                                        strcat((yyval).codigo,"goto ");
                                        strcat((yyval).codigo,descrip.etiquetaSalida);
                                        strcat((yyval).codigo,";\n");
                                        strcat((yyval).codigo,descrip.etiquetaElse);
                                        strcat((yyval).codigo,": ;\n");
                                        strcat((yyval).codigo,(yyvsp[(4) - (4)]).codigo);
                                        strcat((yyval).codigo,descrip.etiquetaSalida);
                                        strcat((yyval).codigo,": ;\n");

                                        TOPE -= 1;
                                     ;}
    break;

  case 49:
#line 1111 "src/practica5.y"
    {
                                                          dtipo tipo = buscarTipoVariable((yyvsp[(3) - (3)]).lexema);
                                                          char *tab = generarTab();
                                                          char *etiqPrintf = etiquetaPrinf(tipo);

                                                          (yyval).codigo = (char*)malloc(strlen((yyvsp[(1) - (3)]).codigo) + strlen(tab) + strlen("scanf(\"") 
                                                          + strlen(etiqPrintf) + strlen("\", &") + strlen((yyvsp[(3) - (3)]).lexema) + strlen(");\n") + 1);
                                                          strcpy((yyval).codigo, (yyvsp[(1) - (3)]).codigo);
                                                          strcat((yyval).codigo, tab);
                                                          strcat((yyval).codigo, "scanf(\"");
                                                          strcat((yyval).codigo, etiqPrintf);
                                                          strcat((yyval).codigo, "\", &");
                                                          strcat((yyval).codigo, (yyvsp[(3) - (3)]).lexema);
                                                          strcat((yyval).codigo, ");\n");
                                                        ;}
    break;

  case 50:
#line 1126 "src/practica5.y"
    {  
                                if (declarado((yyvsp[(1) - (1)]).lexema) == 0) { 
                                  errorNoDeclarado((yyvsp[(1) - (1)]).lexema);
                                }
                                else {
                                  dtipo tipo = buscarTipoVariable((yyvsp[(1) - (1)]).lexema);
                                  char *tab = generarTab();
                                  
                                  char *etiqPrintf = etiquetaPrinf(tipo);
                                  
                                  (yyval).codigo = (char*)malloc(strlen(tab) + strlen("scanf(\"") + strlen(etiqPrintf) + strlen("\", &") + strlen((yyvsp[(1) - (1)]).lexema) + strlen("); getchar();\n") + 1);
                                  strcpy((yyval).codigo, tab);
                                  strcat((yyval).codigo, "scanf(\"");
                                  strcat((yyval).codigo, etiqPrintf);
                                  strcat((yyval).codigo, "\", &");
                                  strcat((yyval).codigo, (yyvsp[(1) - (1)]).lexema);
                                  strcat((yyval).codigo, "); getchar();\n");
                                }
                              ;}
    break;

  case 51:
#line 1146 "src/practica5.y"
    {
                                      (yyval).codigo = (char*)malloc(strlen((yyvsp[(1) - (3)]).codigo) + strlen((yyvsp[(3) - (3)]).codigo) + 1);
                                      strcpy((yyval).codigo,(yyvsp[(1) - (3)]).codigo);
                                      strcat((yyval).codigo,(yyvsp[(3) - (3)]).codigo);
                                    ;}
    break;

  case 52:
#line 1151 "src/practica5.y"
    {
                        (yyval).codigo = (char*)malloc(strlen((yyvsp[(1) - (1)]).codigo) + 1);
                        strcpy((yyval).codigo,(yyvsp[(1) - (1)]).codigo);
                      ;}
    break;

  case 53:
#line 1156 "src/practica5.y"
    { 
                      generarCodMensajeExp(&(yyval), &(yyvsp[(1) - (1)]));
                    ;}
    break;

  case 54:
#line 1159 "src/practica5.y"
    {
                    generarCodMensajeCad(&(yyval), &(yyvsp[(1) - (1)]));
                  ;}
    break;

  case 55:
#line 1163 "src/practica5.y"
    { (yyval).lexema = (yyvsp[(1) - (2)]).lexema ;
                             posProced = buscarProced((yyvsp[(1) - (2)]).lexema) ; 
                             if(posProced == -1){ 
                               mostrarErrorProcedDesco((yyvsp[(1) - (2)]).lexema); 
                             }
                             posParam = 0; 

                             (yyval).codigo = (char*)malloc(strlen((yyvsp[(1) - (2)]).lexema) + strlen("(") + 1);
                             strcpy((yyval).codigo, (yyvsp[(1) - (2)]).lexema);
                             strcat((yyval).codigo, "("); 
                            ;}
    break;

  case 56:
#line 1175 "src/practica5.y"
    { if(posProced != -1) {
                                                                  if(posParam < TS[posProced].parametrosMin) {
                                                                    mostrarErrorMinParam((yyvsp[(1) - (4)]).lexema);
                                                                  }
                                                                  else {
                                                                    comprobarParam();
                                                                  }
                                                                } 

                                                                (yyval).codigo = (char*)malloc(strlen((yyvsp[(1) - (4)]).codigo) + strlen((yyvsp[(2) - (4)]).codigo) + strlen(");") + 1);
                                                                (yyval).codigoProced = (char*)malloc(strlen((yyvsp[(2) - (4)]).codigoProced) + 1);
                                                                strcpy((yyval).codigoProced, (yyvsp[(2) - (4)]).codigoProced);
                                                                strcpy((yyval).codigo, (yyvsp[(1) - (4)]).codigo);
                                                                strcat((yyval).codigo, (yyvsp[(2) - (4)]).codigo);
                                                                strcat((yyval).codigo, ");");
                                                              ;}
    break;

  case 57:
#line 1191 "src/practica5.y"
    { if(posProced != -1) {
                                                if(posParam < TS[posProced].parametrosMin) {
                                                  mostrarErrorMinParam((yyvsp[(1) - (3)]).lexema);
                                                }
                                                else {
                                                  comprobarParam();
                                                }
                                              } 

                                              (yyval).codigoProced = (char*)malloc(strlen("") + 1);
                                              strcpy((yyval).codigoProced, "");

                                              (yyval).codigo = (char*)malloc(strlen((yyvsp[(1) - (3)]).codigo) + strlen(");") + 1);
                                              strcpy((yyval).codigo, (yyvsp[(1) - (3)]).codigo);
                                              strcat((yyval).codigo, ");");
                                            ;}
    break;

  case 58:
#line 1208 "src/practica5.y"
    { if((yyval).tipo != (yyvsp[(3) - (3)]).tipo) {
                                                           (yyval).tipo = desconocido;
                                                         }
                                                         if(posProced != -1) {
                                                           if(posParam >= TS[posProced].parametrosMax) {
                                                             mostrarErrorMaxParam(TS[posProced].nombre);
                                                           }
                                                           else {
                                                             listaParam[posParam] = (yyvsp[(3) - (3)]).tipo;
                                                             posParam += 1;  
                                                           }
                                                         } 
                                                          (yyval).codigoProced = (char*)malloc(strlen((yyvsp[(1) - (3)]).codigoProced) + strlen((yyvsp[(3) - (3)]).codigo) + strlen("\n") + 1);
                                                          strcpy((yyval).codigoProced, (yyvsp[(1) - (3)]).codigoProced);
                                                          strcat((yyval).codigoProced, (yyvsp[(3) - (3)]).codigo);
                                                          strcat((yyval).codigoProced, "\n");

                                                          (yyval).codigo = (char*)malloc(strlen((yyvsp[(1) - (3)]).codigo) + strlen(", ") + strlen((yyvsp[(3) - (3)]).nombre) + 1);
                                                          strcpy((yyval).codigo, (yyvsp[(1) - (3)]).codigo);
                                                          strcat((yyval).codigo, ", ");
                                                          strcat((yyval).codigo, (yyvsp[(3) - (3)]).nombre); 
                                                        ;}
    break;

  case 59:
#line 1230 "src/practica5.y"
    { (yyval).tipo = (yyvsp[(1) - (1)]).tipo;
                                  if(posProced != -1) {
                                    if(posParam >= TS[posProced].parametrosMax) {
                                      mostrarErrorMaxParam(TS[posProced].nombre);
                                    }
                                    else {
                                      listaParam[posParam] = (yyvsp[(1) - (1)]).tipo;
                                      posParam += 1;  
                                    } 
                                  } 
                                  
                                  (yyval).codigoProced = (char*)malloc(strlen((yyvsp[(1) - (1)]).codigo) + strlen("\n") + 1);
                                  strcpy((yyval).codigoProced, (yyvsp[(1) - (1)]).codigo);
                                  strcat((yyval).codigoProced, "\n");

                                  (yyval).codigo = (char*)malloc(strlen((yyvsp[(1) - (1)]).nombre) + 1);
                                  strcpy((yyval).codigo, (yyvsp[(1) - (1)]).nombre);  
                                ;}
    break;

  case 60:
#line 1249 "src/practica5.y"
    {(yyval).tipo = (yyvsp[(2) - (3)]).tipo;;}
    break;

  case 61:
#line 1250 "src/practica5.y"
    {
              if (esNumerico((yyvsp[(2) - (2)]).tipo)){
                (yyval).tipo = (yyvsp[(2) - (2)]).tipo;
                generarCodExpresionUnario(&(yyval),&(yyvsp[(1) - (2)]),&(yyvsp[(2) - (2)]),(yyvsp[(1) - (2)]).lexema);
              } else {
                errorTipoOperador((yyvsp[(1) - (2)]).lexema);
              }
            ;}
    break;

  case 62:
#line 1258 "src/practica5.y"
    {
              if (esNumerico((yyvsp[(2) - (2)]).tipo)){
                (yyval).tipo = (yyvsp[(2) - (2)]).tipo;
                generarCodExpresionUnario(&(yyval),&(yyvsp[(1) - (2)]),&(yyvsp[(2) - (2)]),(yyvsp[(1) - (2)]).lexema);
              } else {
                errorTipoOperador((yyvsp[(1) - (2)]).lexema);
              }
            ;}
    break;

  case 63:
#line 1266 "src/practica5.y"
    {
              if ((yyvsp[(2) - (2)]).tipo == booleano){
                (yyval).tipo = (yyvsp[(2) - (2)]).tipo;
                generarCodExpresionUnario(&(yyval),&(yyvsp[(1) - (2)]),&(yyvsp[(2) - (2)]),"!");
              } else {
                errorTipoOperador((yyvsp[(1) - (2)]).lexema);
              } 
            ;}
    break;

  case 64:
#line 1274 "src/practica5.y"
    {
              if (esLista((yyvsp[(2) - (2)]).tipo)) {
                if ((yyvsp[(1) - (2)]).atrib == 0) {
                  (yyval).tipo = entero;
                } else if ((yyvsp[(1) - (2)]).atrib == 1) {
                  (yyval).tipo = listaATipo((yyvsp[(2) - (2)]).tipo);
                }
              } else {
                errorTipoOperador((yyvsp[(1) - (2)]).lexema);
              }
            ;}
    break;

  case 65:
#line 1285 "src/practica5.y"
    {
              if (esNumerico((yyvsp[(2) - (2)]).tipo)){
                (yyval).tipo = (yyvsp[(2) - (2)]).tipo;
                generarCodExpresionUnario(&(yyval),&(yyvsp[(1) - (2)]),&(yyvsp[(2) - (2)]),(yyvsp[(1) - (2)]).lexema);
              } else {
                errorTipoOperador((yyvsp[(1) - (2)]).lexema);
              }
            ;}
    break;

  case 66:
#line 1293 "src/practica5.y"
    {
              int correcto = 0;
              if ((yyvsp[(1) - (3)]).tipo == entero && (yyvsp[(3) - (3)]).tipo == entero) {
                (yyval).tipo = entero;
                correcto = 1;
              } else if ((yyvsp[(1) - (3)]).tipo == real && (yyvsp[(3) - (3)]).tipo == real) {
                (yyval).tipo = real;
                correcto = 1;
              } else if ((yyvsp[(1) - (3)]).tipo == lista_entero && (yyvsp[(3) - (3)]).tipo == entero) {
                (yyval).tipo = lista_entero;
                correcto = 1;
              } else if ((yyvsp[(1) - (3)]).tipo == lista_real && (yyvsp[(3) - (3)]).tipo == real) {
                (yyval).tipo = lista_real;
                correcto = 1;
              } else if ((yyvsp[(2) - (3)]).atrib == 0) {
                if ((yyvsp[(1) - (3)]).tipo == real && (yyvsp[(3) - (3)]).tipo == lista_real) {
                  (yyval).tipo = lista_real;
                  correcto = 1;
                } else if ((yyvsp[(1) - (3)]).tipo == entero && (yyvsp[(3) - (3)]).tipo == lista_entero) {
                  (yyval).tipo = lista_entero;
                  correcto = 1;
                } else {
                  errorTipoOperador((yyvsp[(2) - (3)]).lexema);
                }
              } else {
                errorTipoOperador((yyvsp[(2) - (3)]).lexema);
              }
              
              if(correcto == 1) {
                generarCodExpresion(&(yyval),&(yyvsp[(1) - (3)]),&(yyvsp[(2) - (3)]),&(yyvsp[(3) - (3)]),(yyvsp[(2) - (3)]).lexema);
              }
              else {
                generarCodNull(&(yyval));
              }
            ;}
    break;

  case 67:
#line 1328 "src/practica5.y"
    {
              if (esLista((yyvsp[(1) - (3)]).tipo) && (yyvsp[(3) - (3)]).tipo == entero) {
                (yyval).tipo = (yyvsp[(1) - (3)]).tipo;
              } else {
                errorTipoOperador((yyvsp[(2) - (3)]).lexema);
              }
            ;}
    break;

  case 68:
#line 1335 "src/practica5.y"
    {
              if(esLista((yyvsp[(1) - (3)]).tipo) && (yyvsp[(3) - (3)]).tipo == entero) {
                (yyval).tipo = listaATipo((yyvsp[(1) - (3)]).tipo);
              } else {
                errorTipoOperador((yyvsp[(2) - (3)]).lexema);
              }
            ;}
    break;

  case 69:
#line 1342 "src/practica5.y"
    {
              int correcto = 0;
              if ((yyvsp[(2) - (3)]).atrib == 0) {
                if ((yyvsp[(1) - (3)]).tipo == entero && (yyvsp[(3) - (3)]).tipo == entero) {
                  (yyval).tipo = entero;
                  correcto = 1;
                } else if ((yyvsp[(1) - (3)]).tipo == real && (yyvsp[(3) - (3)]).tipo == real) {
                  (yyval).tipo = real;
                  correcto = 1;
                } else if ((yyvsp[(1) - (3)]).tipo == lista_entero && (yyvsp[(3) - (3)]).tipo == entero) {
                  (yyval).tipo = lista_entero;
                  correcto = 1;
                } else if ((yyvsp[(1) - (3)]).tipo == lista_real && (yyvsp[(3) - (3)]).tipo == real) {
                  (yyval).tipo = lista_real;
                  correcto = 1;
                } else if ((yyvsp[(1) - (3)]).tipo == real && (yyvsp[(3) - (3)]).tipo == lista_real) {
                  (yyval).tipo = lista_real;
                  correcto = 1;
                } else if ((yyvsp[(1) - (3)]).tipo == entero && (yyvsp[(3) - (3)]).tipo == lista_entero) {
                  (yyval).tipo = lista_entero;
                  correcto = 1;
                } else {
                  errorTipoOperador((yyvsp[(2) - (3)]).lexema);
                }
              } else if ((yyvsp[(2) - (3)]).atrib == 1) {
                if ((yyvsp[(1) - (3)]).tipo == entero && (yyvsp[(3) - (3)]).tipo == entero) {
                  (yyval).tipo = entero;
                  correcto = 1;
                } else if ((yyvsp[(1) - (3)]).tipo == real && (yyvsp[(3) - (3)]).tipo == real) {
                  (yyval).tipo = real;
                  correcto = 1;
                } else if ((yyvsp[(1) - (3)]).tipo == lista_entero && (yyvsp[(3) - (3)]).tipo == entero) {
                  (yyval).tipo = lista_entero;
                  correcto = 1;
                } else if ((yyvsp[(1) - (3)]).tipo == lista_real && (yyvsp[(3) - (3)]).tipo == real) {
                  (yyval).tipo = lista_real;
                  correcto = 1;
                } else {
                  errorTipoOperador((yyvsp[(2) - (3)]).lexema);
                }
              } else if ((yyvsp[(2) - (3)]).atrib == 2) {
                if ((yyvsp[(1) - (3)]).tipo == lista_entero && (yyvsp[(3) - (3)]).tipo == entero) {
                  (yyval).tipo = lista_entero;
                  correcto = 1;
                } else if ((yyvsp[(1) - (3)]).tipo == lista_real && (yyvsp[(3) - (3)]).tipo == entero) {
                  (yyval).tipo = lista_real;
                  correcto = 1;
                } else if ((yyvsp[(1) - (3)]).tipo == lista_caracter && (yyvsp[(3) - (3)]).tipo == entero) {
                  (yyval).tipo = lista_caracter;
                  correcto = 1;
                } else if ((yyvsp[(1) - (3)]).tipo == lista_booleano && (yyvsp[(3) - (3)]).tipo == entero) {
                  (yyval).tipo = lista_booleano;
                  correcto = 1;
                } else if ((yyvsp[(1) - (3)]).tipo == entero && (yyvsp[(3) - (3)]).tipo == entero) {
                  (yyval).tipo = entero;
                  correcto = 1;
                } else {
                  errorTipoOperador((yyvsp[(2) - (3)]).lexema);
                }
              }

              if(correcto == 1) {
                generarCodExpresion(&(yyval),&(yyvsp[(1) - (3)]),&(yyvsp[(2) - (3)]),&(yyvsp[(3) - (3)]),(yyvsp[(2) - (3)]).lexema);
              }
              else {
                generarCodNull(&(yyval));
              }
            ;}
    break;

  case 70:
#line 1410 "src/practica5.y"
    {
              int correcto = 0;
              if ((yyvsp[(1) - (3)]).tipo == entero && (yyvsp[(3) - (3)]).tipo == entero) {
                (yyval).tipo = entero;
                correcto = 1;
              } else if ((yyvsp[(1) - (3)]).tipo == real && (yyvsp[(3) - (3)]).tipo == real) {
                (yyval).tipo = real;
                correcto = 1;
              } else if (esLista((yyvsp[(1) - (3)]).tipo) && esLista((yyvsp[(3) - (3)]).tipo) && (yyvsp[(1) - (3)]).tipo == (yyvsp[(3) - (3)]).tipo) {
                (yyval).tipo = (yyvsp[(1) - (3)]).tipo;
                correcto = 1;
              } else {
                errorTipoOperador((yyvsp[(2) - (3)]).lexema);
              }

              if(correcto == 1) {
                potencia(&(yyval),&(yyvsp[(1) - (3)]),&(yyvsp[(2) - (3)]),&(yyvsp[(3) - (3)]));
              }
              else {
                generarCodNull(&(yyval));
              }
            ;}
    break;

  case 71:
#line 1432 "src/practica5.y"
    {
              int correcto = 0;
              if (!esLista((yyvsp[(1) - (3)]).tipo) && !esLista((yyvsp[(3) - (3)]).tipo)) {
                if ((yyvsp[(1) - (3)]).tipo == (yyvsp[(3) - (3)]).tipo) {
                  (yyval).tipo = booleano;
                  correcto = 1;
                } else {
                  errorTipoOperador((yyvsp[(2) - (3)]).lexema);
                }
              } else {
                errorTipoOperador((yyvsp[(2) - (3)]).lexema);
              }

              if(correcto == 1) {
                generarCodExpresion(&(yyval),&(yyvsp[(1) - (3)]),&(yyvsp[(2) - (3)]),&(yyvsp[(3) - (3)]),(yyvsp[(2) - (3)]).lexema);
              }
              else {
                generarCodNull(&(yyval));
              }
            ;}
    break;

  case 72:
#line 1452 "src/practica5.y"
    { 
              int correcto = 0;
              if ((yyvsp[(1) - (3)]).tipo == entero && (yyvsp[(3) - (3)]).tipo == entero) {
                (yyval).tipo = booleano;
                correcto = 1;
              } else if ((yyvsp[(1) - (3)]).tipo == real && (yyvsp[(3) - (3)]).tipo == real) {
                (yyval).tipo = booleano;
                correcto = 1;
              } else {
                errorTipoOperador((yyvsp[(2) - (3)]).lexema);
              }

              if(correcto == 1) {
                generarCodExpresion(&(yyval),&(yyvsp[(1) - (3)]),&(yyvsp[(2) - (3)]),&(yyvsp[(3) - (3)]),(yyvsp[(2) - (3)]).lexema);
              }
              else {
                generarCodNull(&(yyval));
              }
            ;}
    break;

  case 73:
#line 1471 "src/practica5.y"
    {
              if ((yyvsp[(1) - (3)]).tipo == booleano && (yyvsp[(3) - (3)]).tipo == booleano) {
                (yyval).tipo = booleano;
                generarCodExpresion(&(yyval),&(yyvsp[(1) - (3)]),&(yyvsp[(2) - (3)]),&(yyvsp[(3) - (3)]),"||");

              } else {
                errorTipoOperador((yyvsp[(2) - (3)]).lexema);
                (yyval).codigo = (char*)malloc(strlen("") + 1);
                strcpy((yyval).codigo,"");
                (yyval).nombre = strdup("");
              }
            ;}
    break;

  case 74:
#line 1483 "src/practica5.y"
    {
              if ((yyvsp[(1) - (3)]).tipo == booleano && (yyvsp[(3) - (3)]).tipo == booleano) {
                (yyval).tipo = booleano;
                generarCodExpresion(&(yyval),&(yyvsp[(1) - (3)]),&(yyvsp[(2) - (3)]),&(yyvsp[(3) - (3)]),"&&");
              } else {
                errorTipoOperador((yyvsp[(2) - (3)]).lexema);
                (yyval).codigo = (char*)malloc(strlen("") + 1);
                strcpy((yyval).codigo,"");
                (yyval).nombre = strdup("");
              }
            ;}
    break;

  case 75:
#line 1494 "src/practica5.y"
    {
              if ((yyvsp[(1) - (3)]).tipo == booleano && (yyvsp[(3) - (3)]).tipo == booleano) {
                (yyval).tipo = booleano;
                generarCodExpresion(&(yyval),&(yyvsp[(1) - (3)]),&(yyvsp[(2) - (3)]),&(yyvsp[(3) - (3)]),"^");

              
              } else {
                errorTipoOperador((yyvsp[(2) - (3)]).lexema);
                (yyval).codigo = (char*)malloc(strlen("") + 1);
                strcpy((yyval).codigo,"");
                (yyval).nombre = strdup("");
              }
            ;}
    break;

  case 76:
#line 1507 "src/practica5.y"
    {
              if (esLista((yyvsp[(1) - (5)]).tipo) && (yyvsp[(3) - (5)]).tipo == listaATipo((yyvsp[(1) - (5)]).tipo) && (yyvsp[(5) - (5)]).tipo == entero) {
                (yyval).tipo = (yyvsp[(1) - (5)]).tipo;
              } else {
                errorTipoOperador2((yyvsp[(2) - (5)]).lexema, (yyvsp[(4) - (5)]).lexema);
              }
            ;}
    break;

  case 77:
#line 1514 "src/practica5.y"
    { if (declarado((yyvsp[(1) - (1)]).lexema) == 0) {
                      errorNoDeclarado((yyvsp[(1) - (1)]).lexema);
                    }
                    else {
                      (yyval).tipo = buscarTipoVariable((yyvsp[(1) - (1)]).lexema);

                      (yyval).lexema = (yyvsp[(1) - (1)]).lexema;
                      char *varTmp = temporal();
                      char *tipoTmp = obtenerTipo((yyval).tipo);
                      char *tab = generarTab();
                      (yyval).codigo = (char*)malloc(strlen(tab) + strlen(tipoTmp) + strlen(" ") + strlen(varTmp) + strlen(" = ") + strlen((yyvsp[(1) - (1)]).lexema) + strlen(";\n") + 1);
                      strcpy((yyval).codigo,tab);
                      strcat((yyval).codigo,tipoTmp);
                      strcat((yyval).codigo," ");
                      strcat((yyval).codigo,varTmp);
                      strcat((yyval).codigo," = ");
                      strcat((yyval).codigo,(yyvsp[(1) - (1)]).lexema);
                      strcat((yyval).codigo,";\n");

                      (yyval).nombre = strdup(varTmp); 
                    }
                  ;}
    break;

  case 78:
#line 1536 "src/practica5.y"
    { (yyval).tipo = (yyvsp[(1) - (1)]).tipo;
                               (yyval).lexema = (yyvsp[(1) - (1)]).lexema; ;}
    break;

  case 79:
#line 1538 "src/practica5.y"
    { (yyval).tipo = (yyvsp[(1) - (1)]).tipo;
                          if((yyvsp[(1) - (1)]).tipo == booleano) {
                            if(strcmp((yyvsp[(1) - (1)]).lexema,"verdadero") == 0) {
                              (yyval).lexema = "true";
                            }
                            else if(strcmp((yyvsp[(1) - (1)]).lexema,"falso") == 0) {
                              (yyval).lexema = "false";
                            }
                          }
                          else {
                            (yyval).lexema = (yyvsp[(1) - (1)]).lexema;
                          }
                          char *varTmp = temporal();
                          char *tipoTmp = obtenerTipo((yyvsp[(1) - (1)]).tipo);
                          char *tab = generarTab();
                          (yyval).codigo = (char*)malloc(strlen(tab) + strlen(tipoTmp) + strlen(" ") + strlen(varTmp) + strlen(" = ") + strlen((yyval).lexema) + strlen(";\n") + 1);
                          strcpy((yyval).codigo,tab);
                          strcat((yyval).codigo,tipoTmp);
                          strcat((yyval).codigo," ");
                          strcat((yyval).codigo,varTmp);
                          strcat((yyval).codigo," = ");
                          strcat((yyval).codigo,(yyval).lexema);
                          strcat((yyval).codigo,";\n");

                          (yyval).nombre = strdup(varTmp); 
                        ;}
    break;

  case 81:
#line 1566 "src/practica5.y"
    { (yyval).tipo = (yyvsp[(2) - (3)]).tipo; ;}
    break;

  case 82:
#line 1568 "src/practica5.y"
    { tipoTmp = (yyvsp[(1) - (1)]).tipo;
                  if((yyval).atrib == 0) {
                    (yyval).codigo = (char*)malloc(strlen("int") + 1);
                    strcpy((yyval).codigo,"int");
                  }
                  else if((yyval).atrib == 1) {
                    (yyval).codigo = (char*)malloc(strlen("float") + 1);
                    strcpy((yyval).codigo,"float");
                  }
                  else if((yyval).atrib == 2) {
                    (yyval).codigo = (char*)malloc(strlen("bool") + 1);
                    strcpy((yyval).codigo,"bool");
                  }
                  else if((yyval).atrib == 3) {
                    (yyval).codigo = (char*)malloc(strlen("char") + 1);
                    strcpy((yyval).codigo,"char");
                  } ;}
    break;

  case 83:
#line 1585 "src/practica5.y"
    { tipoTmp = obtenerTipoLista((yyvsp[(2) - (2)]).tipo); ;}
    break;


/* Line 1267 of yacc.c.  */
#line 3371 "src/y.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 1587 "src/practica5.y"


/** Aqui incluimos el fichero generado por el 'lex'
 ** que implementa la funcion 'yylex'
 **/

#include "lex.yy.c"

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_BLACK   "\x1b[0m"

/** Se debe implementar la funcion yyerror. En este caso
 ** simplemente escribimos el mensaje de error en pantalla
 **/

void lexerror(const char *msg)
{
  printf(ANSI_COLOR_RED "[Error Lexico]" ANSI_COLOR_BLACK "(Linea %d) Caracter no reconocido: %s\n", linea_actual, msg);
}

void yyerror(const char *msg)
{
  printf(ANSI_COLOR_YELLOW "[Error sintactico]" ANSI_COLOR_BLACK "(Linea %d) Error: %s\n", linea_actual, msg);
}

void mostrarErrorTipoInco(int pos, dtipo tipo)
{
  char *stringTipo;
  switch(tipo) {
    case entero:
      stringTipo = "entero";
    break;
    case real:
      stringTipo = "real";
    break;
    case booleano:
      stringTipo = "booleano";
    break;
    case caracter:
      stringTipo = "caracter";
    break;
    case lista_entero:
      stringTipo = "lista_entero";
    break;
    case lista_real:
      stringTipo = "lista_real";
    break;
    case lista_caracter:
      stringTipo = "lista_caracter";
    break;
    case lista_booleano:
      stringTipo = "lista_booleano";
    break;
    case desconocido:
      stringTipo = "desconocido";
    break;
    case no_asignado:
      stringTipo = "no_asignado";
    break;
  }
  printf(ANSI_COLOR_MAGENTA "[Error semantico]" ANSI_COLOR_BLACK "(Linea %d) Error: El parámetro de la posición %d debe ser de tipo %s\n", linea_actual, pos, stringTipo);
}

void mostrarErrorOrden()
{
  printf(ANSI_COLOR_MAGENTA "[Error semantico]" ANSI_COLOR_BLACK "(Linea %d) Error: El orden de los parámetros no es correcto\n", linea_actual);
}

void mostrarErrorMinParam(char* nomProced)
{
  printf(ANSI_COLOR_MAGENTA "[Error semantico]" ANSI_COLOR_BLACK "(Linea %d) Error: El número de parámetros es menor a los necesarios en el procedimiento %s\n", linea_actual, nomProced);
}

void mostrarErrorMaxParam(char* nomProced)
{
  printf(ANSI_COLOR_MAGENTA "[Error semantico]" ANSI_COLOR_BLACK "(Linea %d) Error: El número de parámetros es mayor a los disponibles en el procedimiento %s\n", linea_actual, nomProced);
}

void mostrarErrorProcedDesco(char* nomProced)
{
  printf(ANSI_COLOR_MAGENTA "[Error semantico]" ANSI_COLOR_BLACK "(Linea %d) Error: El procedimiento %s no ha sido declarado\n", linea_actual, nomProced);
}

void mostrarErrorTipoAsig(dtipo tipo)
{
  char *stringTipo;
  switch(tipo) {
    case entero:
      stringTipo = "entero";
    break;
    case real:
      stringTipo = "real";
    break;
    case booleano:
      stringTipo = "booleano";
    break;
    case caracter:
      stringTipo = "caracter";
    break;
    case lista_entero:
      stringTipo = "lista_entero";
    break;
    case lista_real:
      stringTipo = "lista_real";
    break;
    case lista_caracter:
      stringTipo = "lista_caracter";
    break;
    case lista_booleano:
      stringTipo = "lista_booleano";
    break;
    case desconocido:
      stringTipo = "desconocido";
    break;
    case no_asignado:
      stringTipo = "no_asignado";
    break;
  }
  printf(ANSI_COLOR_MAGENTA "[Error semantico]" ANSI_COLOR_BLACK "(Linea %d) Error: La expresion en la asignacion debe ser de tipo %s\n", linea_actual, stringTipo);
}

void errorNoDeclarado(char* lexema){
  printf(ANSI_COLOR_MAGENTA "[Error semantico]" ANSI_COLOR_BLACK "(Linea %d) Error: La variable %s no ha sido declarada\n", linea_actual, lexema);
}

void errorYaDeclarado(char* lexema){
  printf(ANSI_COLOR_MAGENTA "[Error semantico]" ANSI_COLOR_BLACK "(Linea %d) Error: La variable %s ya ha sido declarada\n", linea_actual, lexema);
}

void errorTipoOperador(char* lexema) {
  printf(ANSI_COLOR_MAGENTA "[Error semantico]" ANSI_COLOR_BLACK "(Linea %d) Error: El operador %s no admite variables del tipo recibido\n", linea_actual, lexema);
}

void errorTipoOperador2(char* lexema, char* lexema2) {
  printf(ANSI_COLOR_MAGENTA "[Error semantico]" ANSI_COLOR_BLACK "(Linea %d) Error: El operador %s %s no admite variables del tipo recibido\n", linea_actual, lexema, lexema2);
}
