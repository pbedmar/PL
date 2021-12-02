%{
int yylex();
%}

%{
/****************************************************************
 **
 ** Fichero: PRACTICA4.Y
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
  parametro_formal
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
  }
}

typedef struct {
  tipoEntrada   entrada ;
  char          *nombre ;
  dtipo         tipoDato ;
  //numero de parámetros que hay que pasar al procedimiento
  unsigned int  parametrosMin ;
  //número de parámetros obligatorios más por defecto
  unsigned int  parametrosMax ;
} entradaTS ;


#define MAX_TS 1000

unsigned int TOPE=0 ;
unsigned int Subprog ;
dtipo tipoTmp ;
int posParam;
int posProced;
dtipo listaParam[50];

entradaTS TS[MAX_TS] ;

typedef struct {
  int   atrib ;
  char  *lexema ;
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

int buscarProced(char* lexemaProced) {
  int pos = TOPE-1;
  while(pos >= 0 && strcmp(TS[pos].nombre, lexemaProced) != 0) {
    pos -= 1;
  }
  return pos;
}

int comprobarParam() {
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
  while(pos >= 0 && strcmp(TS[pos].nombre, lexema) != 0) {
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
  }
}


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

%token PRINCIPAL
%token LLAVEIZQ
%token LLAVEDER
%token COMA
%token LISTADE
%token PROCEDIMIENTO
%token PARDER
%token PARIZQ
%token CORCHIZQ
%token CORCHDER
%token IGUAL
%token INICIOVAR
%token FINVAR
%token SI
%token MIENTRAS
%token OTROCASO
%token PARA
%token HASTA
%token ITERANDO
%token HACER
%token LEER
%token IMPRIMIR
%token CADENA
%token ID
%token PYC
%token TIPOS
%token CONSTANTE

%right ELEM_POSI_BINA

%left OR // Operador or lógico

%left AND // Operador and lógico

%left XOR // Operador or exclusivo

%left IGUALDAD

%left RELACION

%left ADITIVOS

%left MULTIPLICATIVOS

%left POTENCIAS

%right UNARIOS NOT

%right DECRE_PRE

%right INCRE_PRE

%right UNARIO_PRE_LISTA



%right ELEM_POSI


%left MOV_LISTA

%right DOLLAR

%start programa

%%

/** Seccion de producciones que definen la gramatica. **/

programa    : cabecera_programa bloque ;

cabecera_programa   : PRINCIPAL PARIZQ PARDER ;

inicio_bloque : LLAVEIZQ { TS_InsertaMARCA(); } ;

bloque  : inicio_bloque
          declar_de_variables_locales 
          declar_procedimientos 
          sentencias 
          LLAVEDER { TS_VaciarENTRADAS(); }
        | inicio_bloque
          declar_de_variables_locales 
          sentencias 
          LLAVEDER { TS_VaciarENTRADAS(); } ;

lista_parametros    : lista_parametros COMA parametro { TS_InsertaPARAM($3.lexema, $3.tipo); }
                    | parametro { TS_InsertaPARAM($1.lexema, $1.tipo); } ;

lista_para_por_defecto  : lista_para_por_defecto COMA parametro IGUAL CONSTANTE { TS_InsertaPARAM_POR_DEF($3.lexema, $3.tipo); }
                        | parametro IGUAL CONSTANTE { TS_InsertaPARAM_POR_DEF($1.lexema, $1.tipo); }
                        | lista_para_por_defecto COMA parametro IGUAL agregado_lista { TS_InsertaPARAM_POR_DEF($3.lexema, $3.tipo); }
                        | parametro IGUAL agregado_lista { TS_InsertaPARAM_POR_DEF($1.lexema, $1.tipo); } ;

parametro   : tipos ID { $$.tipo = tipoTmp; $$.lexema = $2.lexema; } ;

declar_de_variables_locales : INICIOVAR variables_locales FINVAR
                            | ;

variables_locales   : variables_locales cuerpo_declar_variables
                    | cuerpo_declar_variables ;

cuerpo_declar_variables : tipos declar_variables PYC 
                        | error ;

declar_variables    : ID { 
                          if(enAmbito($1.lexema) == 1)
                            errorYaDeclarado($1.lexema);
                          TS_InsertaVAR($1.lexema, tipoTmp); }
                    | ID IGUAL expresion { 
                      if(enAmbito($1.lexema) == 1)
                            errorYaDeclarado($1.lexema);
                      
                      TS_InsertaVAR($1.lexema, tipoTmp); }
                    | declar_variables COMA ID { 
                      if(enAmbito($3.lexema) == 1)
                            errorYaDeclarado($3.lexema);
                      TS_InsertaVAR($3.lexema, tipoTmp); }
                    | declar_variables COMA ID IGUAL expresion { 
                      if(enAmbito($3.lexema) == 1)
                            errorYaDeclarado($3.lexema);
                      TS_InsertaVAR($3.lexema, tipoTmp); } ;

declar_procedimientos : declar_procedimientos declar_proced
                      | declar_proced ;

declar_proced : cabecera_proced bloque { Subprog = 0; } ;

inicio_cabe_proced : PROCEDIMIENTO ID { TS_InsertaPROCED($2.lexema); } ;

cabecera_proced : inicio_cabe_proced PARIZQ lista_parametros COMA lista_para_por_defecto PARDER { Subprog = 1; }
                | inicio_cabe_proced PARIZQ lista_parametros PARDER { Subprog = 1; }
                | inicio_cabe_proced PARIZQ PARDER { Subprog = 1; }
                | error ;

sentencias  : sentencias sentencia
            | sentencia ;

sentencia   : bloque
            | sentencia_asignacion
            | sentencia_if
            | MIENTRAS PARIZQ expresion PARDER sentencia
            | PARA sentencia_asignacion HASTA expresion ITERANDO expresion HACER sentencia
            | LEER lista_identificadores PYC
            | IMPRIMIR mensajes PYC
            | llamada_proced
            | expresion MOV_LISTA PYC {if (esLista($1.tipo)) { $$.tipo = $1.tipo; } else {errorTipoOperador($2.lexema); }}
            | DOLLAR expresion PYC {if (esLista($2.tipo)) { $$.tipo = $2.tipo; } else {errorTipoOperador($1.lexema); }};
                                                                      
sentencia_asignacion  : ID IGUAL expresion PYC {if (buscarTipoVariable($1.lexema) != $3.tipo){
                                                  mostrarErrorTipoAsig($3.tipo);
                                                }
                                                if (declarado($1.lexema) == 0) 
                                                  errorNoDeclarado($1.lexema);
                                              } ;

sentencia_if    : SI PARIZQ expresion PARDER sentencia
                | SI PARIZQ expresion PARDER sentencia
                  OTROCASO sentencia ;

lista_identificadores   : lista_identificadores COMA ID
                        | ID ;

mensajes    : mensajes COMA mensaje
            | mensaje ;

mensaje : expresion
        | CADENA ;

inicio_llamada : ID PARIZQ { $$.lexema = $1.lexema ;
                             posProced = buscarProced($1.lexema) ; 
                             if(posProced == -1){ 
                               mostrarErrorProcedDesco($1.lexema); 
                             }
                             posParam = 0; };

llamada_proced  : inicio_llamada lista_expresiones PARDER PYC { if(posProced != -1) {
                                                                  if(posParam < TS[posProced].parametrosMin) {
                                                                    mostrarErrorMinParam($1.lexema);
                                                                  }
                                                                  else {
                                                                    comprobarParam();
                                                                  }
                                                                } } 
                | inicio_llamada PARDER PYC { if(posProced != -1) {
                                                if(posParam < TS[posProced].parametrosMin) {
                                                  mostrarErrorMinParam($1.lexema);
                                                }
                                                else {
                                                  comprobarParam();
                                                }
                                              } };

lista_expresiones   : lista_expresiones COMA expresion { if(posProced != -1) {
                                                           if(posParam >= TS[posProced].parametrosMax) {
                                                             mostrarErrorMaxParam(TS[posProced].nombre);
                                                           }
                                                           else {
                                                             listaParam[posParam] = $3.tipo;
                                                             posParam += 1;  
                                                           }
                                                         } }
                    | expresion { if(posProced != -1) {
                                    if(posParam >= TS[posProced].parametrosMax) {
                                      mostrarErrorMaxParam(TS[posProced].nombre);
                                    }
                                    else {
                                      listaParam[posParam] = $1.tipo;
                                      posParam += 1;  
                                    } 
                                  } };

expresion   : PARIZQ expresion PARDER {$$.tipo = $2.tipo}
            | DECRE_PRE expresion {
              if (esNumerico($2.tipo)){
                $$.tipo = $2.tipo;
              } else {
                errorTipoOperador($1.lexema);
              }
            }
            | INCRE_PRE expresion {
              if (esNumerico($2.tipo)){
                $$.tipo = $2.tipo;
              } else {
                errorTipoOperador($1.lexema);
              }
            } 
            | NOT expresion {
              if ($2.tipo == booleano){
                $$.tipo = $2.tipo; //TODO: Se debe contemplar la negación de una lista de booleanos?
              } else {
                errorTipoOperador($1.lexema);
              } 
            }
            | UNARIO_PRE_LISTA expresion {
              if (esLista($2.tipo)) {
                if ($1.atrib == 0) {
                  $$.tipo = entero;
                } else if ($1.atrib == 1) {
                  $$.tipo = listaATipo($2.tipo);
                }
              } else {
                errorTipoOperador($1.lexema);
              }
            }
            | ADITIVOS expresion %prec UNARIOS {
              if (esNumerico($2.tipo)){
                $$.tipo = $2.tipo;
              } else {
                errorTipoOperador($1.lexema);
              }
            }
            | expresion ADITIVOS expresion {
              if ($1.tipo == entero && $3.tipo == entero) {
                $$.tipo = entero;
              } else if ($1.tipo == real && ($3.tipo == entero || $3.tipo == real)) {
                $$.tipo = real;
              } else if ($3.tipo == real && ($1.tipo == entero || $1.tipo == real)) {
                $$.tipo = real;
              } else if ($1.tipo == lista_entero && $3.tipo == entero) {
                $$.tipo = lista_entero;
              } else if ($1.tipo == lista_real && $3.tipo == real) {
                $$.tipo = lista_real;
              } else if ($1.tipo == entero && $3.tipo == lista_entero && $2.atrib == 0) {
                $$.tipo = lista_entero;
              } else if ($1.tipo == real && $3.tipo == lista_real && $2.atrib == 0) {
                $$.tipo = lista_real;
              } else {
                errorTipoOperador($2.lexema);
              }
            }
            | expresion DECRE_PRE expresion {
              if (esLista($1.tipo) && $3.tipo == entero) {
                $$.tipo = $1.tipo;
              } else {
                errorTipoOperador($2.lexema);
              }
            }
            | expresion ELEM_POSI expresion %prec ELEM_POSI_BINA {
              if(esLista($1.tipo) && $3.tipo == entero) {
                $$.tipo = $1.tipo;
              } else {
                errorTipoOperador($2.lexema);
              }
            }
            | expresion MULTIPLICATIVOS expresion {
              if ($1.tipo == entero && $3.tipo == entero) {
                $$.tipo = entero;
              } else if ($1.tipo == real && ($3.tipo == entero || $3.tipo == real)) {
                $$.tipo = real;
              } else if ($3.tipo == real && ($1.tipo == entero || $1.tipo == real)) {
                $$.tipo = real;
              } else if ($1.tipo == lista_entero && $3.tipo == entero) {
                $$.tipo = lista_entero;
              } else if ($1.tipo == lista_real && $3.tipo == real) {
                $$.tipo = lista_real;
              } else if ($1.tipo == entero && $3.tipo == lista_entero && $2.atrib == 0) {
                $$.tipo = lista_entero;
              } else if ($1.tipo == real && $3.tipo == lista_real && $2.atrib == 0) {
                $$.tipo = lista_real;
              } else {
                errorTipoOperador($2.lexema);
              }
            }
            | expresion POTENCIAS expresion {
              if ($1.tipo == entero && $3.tipo == entero) {
                $$.tipo = entero;
              } else if ($1.tipo == real && ($3.tipo == entero || $3.tipo == real)) {
                $$.tipo = real;
              } else if ($3.tipo == real && ($1.tipo == entero || $1.tipo == real)) {
                $$.tipo = real;
              } else if (esLista($1.tipo) && esLista($3.tipo) && $1.tipo == $3.tipo) {
                $$.tipo = $1.tipo;
              } else {
                errorTipoOperador($2.lexema);
              }
            }
            | expresion IGUALDAD expresion {
              if (!esLista($1.tipo) && !esLista($3.tipo)) {
                if ($1.tipo == $3.tipo) {
                  $$.tipo = booleano;
                } else if ($1.tipo == real && ($3.tipo == entero || $3.tipo == real)) {
                  $$.tipo = booleano;
                } else if ($3.tipo == real && ($1.tipo == entero || $1.tipo == real)) {
                  $$.tipo = booleano;
                } else {
                  errorTipoOperador($2.lexema);
                }
              } else {
                errorTipoOperador($2.lexema);
              }
            }
            | expresion RELACION expresion {
              if ($1.tipo == entero && $3.tipo == entero) {
                $$.tipo = booleano;
              } else if ($1.tipo == real && ($3.tipo == entero || $3.tipo == real)) {
                $$.tipo = booleano;
              } else if ($3.tipo == real && ($1.tipo == entero || $1.tipo == real)) {
                $$.tipo = booleano;
              } else {
                errorTipoOperador($2.lexema);
              }
            }
            | expresion OR expresion {
              if ($1.tipo == booleano && $3.tipo == booleano) {
                $$.tipo = booleano;
              } else {
                errorTipoOperador($2.lexema);
              }
            }
            | expresion AND expresion {
              if ($1.tipo == booleano && $3.tipo == booleano) {
                $$.tipo = booleano;
              } else {
                errorTipoOperador($2.lexema);
              }
            }
            | expresion XOR expresion {
              if ($1.tipo == booleano && $3.tipo == booleano) {
                $$.tipo = booleano;
              } else {
                errorTipoOperador($2.lexema);
              }
            }
            | expresion INCRE_PRE expresion ELEM_POSI expresion {
              if (esLista($1.tipo) && $3.tipo == listaATipo($1.tipo) && $5.tipo == entero) {
                $$.tipo = $1.tipo;
              } else {
                errorTipoOperador2($2.lexema, $4.lexema);
              }
            }
            | ID {if (declarado($1.lexema) == 0) 
                        errorNoDeclarado($1.lexema);}
            | agregado_lista { $$.tipo = $1.tipo; }
            | CONSTANTE { $$.tipo = $1.tipo; }
            | error ;

agregado_lista  : CORCHIZQ lista_expresiones CORCHDER ;

tipos   : TIPOS { tipoTmp = $1.tipo; }
        | LISTADE TIPOS { tipoTmp = obtenerTipoLista($1.tipo); } ;

%%

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