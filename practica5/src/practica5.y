%{
int yylex();
%}

%{
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
  else if(tipo == lista_entero) {
    return "Lista<int>";
  }
  else if(tipo == lista_real) {
    return "Lista<float>";
  }
  else if(tipo == lista_booleano) {
    return "Lista<bool>";
  }
  else if(tipo == lista_caracter) {
    return "Lista<char>";
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
  a->codigo = (char*)malloc(strlen("#include <stdbool.h>\n#include <stdio.h>\n#include \"Lista.cpp\"\n") + strlen("#include <math.h>\n\n") +strlen(a2->codigoGlobal) + strlen("\n") + strlen(a1->codigo) + strlen(a2->codigo) + 1);
  strcpy(a->codigo,"#include <stdbool.h>\n#include <stdio.h>\n#include \"Lista.cpp\"\n");
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

  a->codigo = (char*)malloc(strlen(tab) + strlen("{\n") + strlen(etiqEntrada) + strlen(": ;\n") + strlen(a3->codigo) + strlen(tab) + strlen("if (!") + strlen(a3->nombre) 
              + strlen(") goto ") + strlen(etiqSalida) + strlen(";\n") + strlen(a5->codigo) +strlen(tab)+strlen("goto ") + strlen(etiqEntrada) + strlen(";\n") + strlen(etiqSalida) 
              + strlen(": ;\n") + strlen(tab) + strlen("}\n\n") + 1);

  strcpy(a->codigo,tab);
  strcat(a->codigo,"{\n");
  strcat(a->codigo,etiqEntrada);
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
  strcat(a->codigo,tab);
  strcat(a->codigo,"}\n\n");

}

void genCodInsertarElementoLista(atributos *a, atributos *a1, atributos *a2, atributos *a3){
  char *varTmp = temporal();
  char *tipoTmp = obtenerTipo(a->tipo);
  char *tab = generarTab();

  printf("cod1: %s\n", a1->codigo);
  printf("cod2: %s\n", a2->codigo);
  printf("cod3: %s\n", a3->codigo);
  
  a->codigo = (char*)malloc(strlen(a1->codigo) + strlen(a2->codigo) + strlen(a3->codigo) + strlen(tab) + strlen(tipoTmp) + strlen(" ") + strlen(varTmp) + strlen(" = ") + strlen(a1->nombre) 
              + strlen(".insertarElementoLista(") + strlen(a2->nombre) + strlen(",") + strlen(a3->nombre) + strlen(");\n") + 1);
  
  strcpy(a->codigo,a1->codigo);
  strcat(a->codigo,a2->codigo);
  strcat(a->codigo,a3->codigo);
  strcat(a->codigo,tab);
  strcat(a->codigo,tipoTmp);
  strcat(a->codigo," ");
  strcat(a->codigo,varTmp);
  strcat(a->codigo," = ");
  strcat(a->codigo,a1->nombre);
  strcat(a->codigo,".insertarElementoLista(");
  strcat(a->codigo,a2->nombre);
  strcat(a->codigo,",");
  strcat(a->codigo,a3->nombre);
  strcat(a->codigo,");\n");

  a->nombre = strdup(varTmp);
  printf("operadores ++ @\n");
  printf("codigo generado: \n%s\n",a->codigo);
  
}

void genCodComienzoLista(atributos *a, atributos *a1){
  char *tab = generarTab();
  
  a->codigo = (char*)malloc(strlen(tab) + strlen(a1->lexema) + strlen(".comienzoLista();\n") + 1);
  
  strcpy(a->codigo,tab);
  strcat(a->codigo,a1->lexema);
  strcat(a->codigo,".comienzoLista();\n");

  a->nombre = strdup(a1->lexema);
  printf("operador $\n");
  printf("codigo generado: \n%s\n",a->codigo);
}

void genCodMoverLista(atributos *a, atributos *a1, char* op){
  char *tab = generarTab();
  
  if(op == ">>"){
    a->codigo = (char*)malloc(strlen(tab) + strlen(a1->lexema) + strlen(".avanzarLista();\n") + 1);
    
    strcpy(a->codigo,tab);
    strcat(a->codigo,a1->lexema);
    strcat(a->codigo,".avanzarLista();\n");
  }
  else if(op == "<<"){
    a->codigo = (char*)malloc(strlen(tab) + strlen(a1->lexema) + strlen(".retrocederLista();\n") + 1);
    
    strcpy(a->codigo,tab);
    strcat(a->codigo,a1->lexema);
    strcat(a->codigo,".retrocederLista();\n");
  }

  a->nombre = strdup(a1->lexema);
  printf("operador %s\n", op);
  printf("codigo generado: \n%s\n",a->codigo);
}

void genCodLongitudLista(atributos *a, atributos *a1){
  char *tab = generarTab();
  char *varTmp = temporal();
  char *tipoTmp = obtenerTipo(a->tipo);
  
  a->codigo = (char*)malloc(strlen(a1->codigo) + strlen(tab) + strlen(tipoTmp) + strlen(" ") + strlen(varTmp) + strlen(" = ") + strlen(a1->nombre) + strlen(".comienzoLista();\n") + 1);
  
  strcpy(a->codigo,a1->codigo);
  strcat(a->codigo,tab);
  strcat(a->codigo,tipoTmp);
  strcat(a->codigo," ");
  strcat(a->codigo,varTmp);
  strcat(a->codigo," = ");
  strcat(a->codigo,a1->nombre);
  strcat(a->codigo,".tamLista();\n");

  a->nombre = strdup(varTmp);
  printf("operador #\n");
  printf("codigo generado: \n%s\n",a->codigo);
}

void genCodObtenerElementoActual(atributos *a, atributos *a1){
  char *tab = generarTab();
  char *varTmp = temporal();
  char *tipoTmp = obtenerTipo(a->tipo);
  
  a->codigo = (char*)malloc(strlen(a1->codigo) + strlen(tab) + strlen(tipoTmp) + strlen(" ") + strlen(varTmp) + strlen(" = ") + strlen(a1->nombre) + strlen(".obtenerElementoActual();\n") + 1);
  
  strcpy(a->codigo,a1->codigo);
  strcat(a->codigo,tab);
  strcat(a->codigo,tipoTmp);
  strcat(a->codigo," ");
  strcat(a->codigo,varTmp);
  strcat(a->codigo," = ");
  strcat(a->codigo,a1->nombre);
  strcat(a->codigo,".obtenerElementoActual();\n");

  a->nombre = strdup(varTmp);
  printf("operador ?\n");
  printf("codigo generado: \n%s\n",a->codigo);
}

void genCodObtenerElementoPosicion(atributos *a, atributos *a1, atributos *a2){
  char *tab = generarTab();
  char *varTmp = temporal();
  char *tipoTmp = obtenerTipo(a->tipo);
  
  a->codigo = (char*)malloc(strlen(a1->codigo) + strlen(a2->codigo) + strlen(tab) + strlen(tipoTmp) + strlen(" ") + strlen(varTmp) + strlen(" = ") + strlen(a1->nombre) + strlen(".obtenerElementoPosicion();\n") + 1);
  
  strcpy(a->codigo,a1->codigo);
  strcat(a->codigo,a2->codigo);
  strcat(a->codigo,tab);
  strcat(a->codigo,tipoTmp);
  strcat(a->codigo," ");
  strcat(a->codigo,varTmp);
  strcat(a->codigo," = ");
  strcat(a->codigo,a1->nombre);
  strcat(a->codigo,".obtenerElementoPosicion(");
  strcat(a->codigo,a2->nombre);
  strcat(a->codigo,");\n");

  a->nombre = strdup(varTmp);
  printf("operador @\n");
  printf("codigo generado: \n%s\n",a->codigo);
}

void genCodEliminarElementoPosicion(atributos *a, atributos *a1, atributos *a2){
  char *tab = generarTab();
  char *varTmp = temporal();
  char *tipoTmp = obtenerTipo(a->tipo);
  
  a->codigo = (char*)malloc(strlen(a1->codigo) + strlen(a2->codigo) + strlen(tab) + strlen(tipoTmp) + strlen(" ") + strlen(varTmp) + strlen(" = ") + strlen(a1->nombre) + strlen(".eliminarElementoPosicion(") + strlen(a2->nombre) + strlen(");\n") + 1);
  
  strcpy(a->codigo,a1->codigo);
  strcat(a->codigo,a2->codigo);
  strcat(a->codigo,tab);
  strcat(a->codigo,tipoTmp);
  strcat(a->codigo," ");
  strcat(a->codigo,varTmp);
  strcat(a->codigo," = ");
  strcat(a->codigo,a1->nombre);
  strcat(a->codigo,".eliminarElementoPosicion(");
  strcat(a->codigo,a2->nombre);
  strcat(a->codigo,");\n");

  a->nombre = strdup(varTmp);
  printf("operador --\n");
  printf("codigo generado: \n%s\n",a->codigo);
  printf("--FIN--\n");
}

void genCodEliminarListaAPartirPosicion(atributos *a, atributos *a1, atributos *a2){
  char *tab = generarTab();
  char *varTmp = temporal();
  char *tipoTmp = obtenerTipo(a->tipo);
  
  a->codigo = (char*)malloc(strlen(a1->codigo) + strlen(a2->codigo) + strlen(tab) + strlen(tipoTmp) + strlen(" ") + strlen(varTmp) + strlen(" = ") + strlen(a1->nombre) + strlen(".eliminarListaAPartirPosicion(") + strlen(a2->nombre) + strlen(");\n") + 1);
  
  strcpy(a->codigo,a1->codigo);
  strcat(a->codigo,a2->codigo);
  strcat(a->codigo,tab);
  strcat(a->codigo,tipoTmp);
  strcat(a->codigo," ");
  strcat(a->codigo,varTmp);
  strcat(a->codigo," = ");
  strcat(a->codigo,a1->nombre);
  strcat(a->codigo,".eliminarListaAPartirPosicion(");
  strcat(a->codigo,a2->nombre);
  strcat(a->codigo,");\n");

  a->nombre = strdup(varTmp);
  printf("operador %s\n", "%");
  printf("codigo generado: \n%s\n",a->codigo);
}

void genCodConcatenarListas(atributos *a, atributos *a1, atributos *a2){
  char *tab = generarTab();
  char *varTmp = temporal();
  char *tipoTmp = obtenerTipo(a->tipo);
  
  a->codigo = (char*)malloc(strlen(a1->codigo) + strlen(a2->codigo) + strlen(tab) + strlen(tipoTmp) + strlen(" ") + strlen(varTmp) + strlen(" = ") + strlen(a1->nombre) + strlen(".concatenarListas(") + strlen(a2->nombre) + strlen(");\n") + 1);
  
  strcpy(a->codigo,a1->codigo);
  strcat(a->codigo,a2->codigo);
  strcat(a->codigo,tab);
  strcat(a->codigo,tipoTmp);
  strcat(a->codigo," ");
  strcat(a->codigo,varTmp);
  strcat(a->codigo," = ");
  strcat(a->codigo,a1->nombre);
  strcat(a->codigo,".concatenarListas(");
  strcat(a->codigo,a2->nombre);
  strcat(a->codigo,");\n");

  a->nombre = strdup(varTmp);
  printf("operador **\n");
  printf("codigo generado: \n%s\n",a->codigo);
}

void genCodSumarElementoALista(atributos *a, atributos *a1, atributos *a2){
  char *tab = generarTab();
  char *varTmp = temporal();
  char *tipoTmp = obtenerTipo(a->tipo);
  
  a->codigo = (char*)malloc(strlen(a1->codigo) + strlen(a2->codigo) + strlen(tab) + strlen(tipoTmp) + strlen(" ") + strlen(varTmp) + strlen(" = ") + strlen(a1->nombre) + strlen(".sumar(") + strlen(a2->nombre) + strlen(");\n") + 1);
  
  strcpy(a->codigo,a1->codigo);
  strcat(a->codigo,a2->codigo);
  strcat(a->codigo,tab);
  strcat(a->codigo,tipoTmp);
  strcat(a->codigo," ");
  strcat(a->codigo,varTmp);
  strcat(a->codigo," = ");
  strcat(a->codigo,a1->nombre);
  strcat(a->codigo,".sumar(");
  strcat(a->codigo,a2->nombre);
  strcat(a->codigo,");\n");

  a->nombre = strdup(varTmp);
  printf("operador +\n");
  printf("codigo generado: \n%s\n",a->codigo);
}

void genCodRestarElementoALista(atributos *a, atributos *a1, atributos *a2){
  char *tab = generarTab();
  char *varTmp = temporal();
  char *tipoTmp = obtenerTipo(a->tipo);
  
  a->codigo = (char*)malloc(strlen(a1->codigo) + strlen(a2->codigo) + strlen(tab) + strlen(tipoTmp) + strlen(" ") + strlen(varTmp) + strlen(" = ") + strlen(a1->nombre) + strlen(".restar(") + strlen(a2->nombre) + strlen(");\n") + 1);
  
  strcpy(a->codigo,a1->codigo);
  strcat(a->codigo,a2->codigo);
  strcat(a->codigo,tab);
  strcat(a->codigo,tipoTmp);
  strcat(a->codigo," ");
  strcat(a->codigo,varTmp);
  strcat(a->codigo," = ");
  strcat(a->codigo,a1->nombre);
  strcat(a->codigo,".restar(");
  strcat(a->codigo,a2->nombre);
  strcat(a->codigo,");\n");

  a->nombre = strdup(varTmp);
  printf("operador -\n");
  printf("codigo generado: \n%s\n",a->codigo);
}

void genCodMultiplicarElementoALista(atributos *a, atributos *a1, atributos *a2){
  char *tab = generarTab();
  char *varTmp = temporal();
  char *tipoTmp = obtenerTipo(a->tipo);
  
  a->codigo = (char*)malloc(strlen(a1->codigo) + strlen(a2->codigo) + strlen(tab) + strlen(tipoTmp) + strlen(" ") + strlen(varTmp) + strlen(" = ") + strlen(a1->nombre) + strlen(".multiplicar(") + strlen(a2->nombre) + strlen(");\n") + 1);
  
  strcpy(a->codigo,a1->codigo);
  strcat(a->codigo,a2->codigo);
  strcat(a->codigo,tab);
  strcat(a->codigo,tipoTmp);
  strcat(a->codigo," ");
  strcat(a->codigo,varTmp);
  strcat(a->codigo," = ");
  strcat(a->codigo,a1->nombre);
  strcat(a->codigo,".multiplicar(");
  strcat(a->codigo,a2->nombre);
  strcat(a->codigo,");\n");

  a->nombre = strdup(varTmp);
  printf("operador *\n");
  printf("codigo generado: \n%s\n",a->codigo);
}

void genCodDividirElementoALista(atributos *a, atributos *a1, atributos *a2){
  char *tab = generarTab();
  char *varTmp = temporal();
  char *tipoTmp = obtenerTipo(a->tipo);
  
  a->codigo = (char*)malloc(strlen(a1->codigo) + strlen(a2->codigo) + strlen(tab) + strlen(tipoTmp) + strlen(" ") + strlen(varTmp) + strlen(" = ") + strlen(a1->nombre) + strlen(".dividir(") + strlen(a2->nombre) + strlen(");\n") + 1);
  
  strcpy(a->codigo,a1->codigo);
  strcat(a->codigo,a2->codigo);
  strcat(a->codigo,tab);
  strcat(a->codigo,tipoTmp);
  strcat(a->codigo," ");
  strcat(a->codigo,varTmp);
  strcat(a->codigo," = ");
  strcat(a->codigo,a1->nombre);
  strcat(a->codigo,".dividir(");
  strcat(a->codigo,a2->nombre);
  strcat(a->codigo,");\n");

  a->nombre = strdup(varTmp);
  printf("operador /\n");
  printf("codigo generado: \n%s\n",a->codigo);
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

programa    : cabecera_programa bloque {  
                                          generarCodPrograma(&$$, &$1, &$2);
                                       };

cabecera_programa   : PRINCIPAL PARIZQ PARDER { 
                                                generarCodCabeProg(&$$);
                                              };

inicio_bloque : LLAVEIZQ { 
                            TS_InsertaMARCA();
                            generarCodIniBloque(&$$);
                            profun += 1;
                          } ;

bloque  : inicio_bloque
          declar_de_variables_locales 
          declar_procedimientos 
          sentencias 
          LLAVEDER  { 
                      TS_VaciarENTRADAS();

                      profun -= 1;
                      char *tab = generarTab();

                      $$.codigoGlobal = (char*)malloc(strlen($2.codigoGlobal) + 1);
                      strcpy($$.codigoGlobal,$2.codigoGlobal);

                      $$.codigo = (char*)malloc(strlen($1.codigo) + strlen($2.codigo) + strlen($3.codigo) + strlen($4.codigo) + strlen(tab) + strlen("}\n") + 1);
                      strcpy($$.codigo,$1.codigo);
                      strcat($$.codigo,$2.codigo);
                      strcat($$.codigo, $3.codigo);
                      strcat($$.codigo,$4.codigo);
                      strcat($$.codigo,tab);
                      strcat($$.codigo,"}\n"); 
                    }
        | inicio_bloque
          declar_de_variables_locales 
          sentencias 
          LLAVEDER { TS_VaciarENTRADAS();
                     profun -= 1;
                     char *tab = generarTab();
                     $$.codigo = (char*)malloc(strlen($1.codigo) + strlen($2.codigo) + strlen($3.codigo) + strlen(tab) + strlen("}\n") + 1);
                     $$.codigoGlobal = (char*)malloc(strlen($2.codigoGlobal) + 1);
                     strcpy($$.codigoGlobal,$2.codigoGlobal);

                     strcpy($$.codigo,$1.codigo);
                     strcat($$.codigo,$2.codigo);
                     strcat($$.codigo,$3.codigo);
                     strcat($$.codigo,tab);
                     strcat($$.codigo,"}\n"); 
                   } ;

lista_parametros    : lista_parametros COMA parametro { 
                                                        TS_InsertaPARAM($3.lexema, $3.tipo);

                                                        $$.codigo = (char*)malloc(strlen($1.codigo) + strlen(", ") + strlen($3.codigo) + 1);
                                                        strcpy($$.codigo, $1.codigo);
                                                        strcat($$.codigo, ", ");
                                                        strcat($$.codigo, $3.codigo);
                                                      }
                    | parametro { 
                                  TS_InsertaPARAM($1.lexema, $1.tipo); 

                                  $$.codigo = (char*)malloc(strlen($1.codigo) + 1);
                                  strcpy($$.codigo, $1.codigo);
                                } ;

lista_para_por_defecto  : lista_para_por_defecto COMA parametro IGUAL CONSTANTE { 
                            TS_InsertaPARAM_POR_DEF($3.lexema, $3.tipo); 

                            $$.codigo = (char*)malloc(strlen($1.codigo) + strlen(", ") + strlen($3.codigo) + strlen(" = ") + strlen($5.lexema) + 1);
                            strcpy($$.codigo, $1.codigo);
                            strcat($$.codigo, ", ");
                            strcat($$.codigo, $3.codigo);
                            strcat($$.codigo, " = ");
                            strcat($$.codigo, $5.lexema);
                                                                                }
                        | parametro IGUAL CONSTANTE { 
                                                      TS_InsertaPARAM_POR_DEF($1.lexema, $1.tipo); 

                                                      $$.codigo = (char*)malloc(strlen($1.codigo) + strlen(" = ") + strlen($3.lexema));
                                                      strcat($$.codigo, $1.codigo);
                                                      strcat($$.codigo, " = ");
                                                      strcat($$.codigo, $3.lexema);
                                                    }
                        | lista_para_por_defecto COMA parametro IGUAL agregado_lista  { 
                                                                                        TS_InsertaPARAM_POR_DEF($3.lexema, $3.tipo); 

                                                                                        $$.codigo = (char*)malloc(strlen($1.codigo) + strlen(", ")
                                                                                        + strlen($3.codigo) + strlen(" = ") + strlen($5.codigo) + 1);
                                                                                        strcpy($$.codigo, $1.codigo);
                                                                                        strcat($$.codigo, ", ");
                                                                                        strcat($$.codigo, $3.codigo);
                                                                                        strcat($$.codigo, " = ");
                                                                                        strcat($$.codigo, $5.codigo);
                                                                                      }
                        | parametro IGUAL agregado_lista  { 
                                                            TS_InsertaPARAM_POR_DEF($1.lexema, $1.tipo); 

                                                            $$.codigo = (char*)malloc(strlen($1.codigo) + strlen(" = ") + strlen($3.codigo));
                                                            strcat($$.codigo, $1.codigo);
                                                            strcat($$.codigo, " = ");
                                                            strcat($$.codigo, $3.codigo);
                                                          } ;

parametro   : tipos ID  { 
                          $$.tipo = tipoTmp; $$.lexema = $2.lexema; 

                          $$.codigo = (char*)malloc(strlen($1.codigo) + strlen(" ") + strlen($2.lexema) + 1);
                          strcpy($$.codigo, $1.codigo);
                          strcat($$.codigo, " ");
                          strcat($$.codigo, $2.lexema);
                        } ;

declar_de_variables_locales : INICIOVAR variables_locales FINVAR { $$.codigo = (char*)malloc(strlen($2.codigo) + 1);
                                                                   $$.codigoGlobal = (char*)malloc(strlen($2.codigoGlobal) + 1);
                                                                   strcpy($$.codigoGlobal,$2.codigoGlobal);
                                                                   strcpy($$.codigo,$2.codigo); }
                            | { $$.codigo = (char*)malloc(strlen("") + 1);
                                $$.codigoGlobal = (char*)malloc(strlen("") + 1);
                                strcpy($$.codigoGlobal,"");
                                strcpy($$.codigo,""); };

variables_locales   : variables_locales cuerpo_declar_variables { $$.codigo = (char*)malloc(strlen($1.codigo) + strlen($2.codigo) + 1);
                                                                  $$.codigoGlobal = (char*)malloc(strlen($1.codigoGlobal) + strlen($2.codigoGlobal) + 1);
                                                                  strcpy($$.codigoGlobal,$1.codigoGlobal);
                                                                  strcat($$.codigoGlobal,$2.codigoGlobal);
                                                                  strcpy($$.codigo,$1.codigo);
                                                                  strcat($$.codigo,$2.codigo); }
                    | cuerpo_declar_variables { $$.codigo = (char*)malloc(strlen($1.codigo) + 1);
                                                $$.codigoGlobal = (char*)malloc(strlen($1.codigoGlobal) + 1);
                                                strcpy($$.codigoGlobal,$1.codigoGlobal);
                                                strcpy($$.codigo,$1.codigo); } ;

cuerpo_declar_variables : tipos declar_variables PYC { if(profun > 1) {
                                                         char *tab = generarTab();
                                                         $$.codigo = (char*)malloc(strlen(tab) + strlen($1.codigo) + strlen(" ") + strlen($2.codigo) + strlen(";\n") + 1);
                                                         $$.codigoGlobal = (char*)malloc(strlen("") + 1);
                                                         strcpy($$.codigoGlobal,"");
                                                         strcpy($$.codigo,tab);
                                                         strcat($$.codigo,$1.codigo);
                                                         strcat($$.codigo, " ");
                                                         strcat($$.codigo, $2.codigo);
                                                         strcat($$.codigo, ";\n");
                                                       }
                                                       else {
                                                         $$.codigoGlobal = (char*)malloc(strlen($1.codigo) + strlen(" ") + strlen($2.codigo) + strlen(";\n") + 1);
                                                         $$.codigo = (char*)malloc(strlen("") + 1);
                                                         strcpy($$.codigo,"");
                                                         strcpy($$.codigoGlobal,$1.codigo);
                                                         strcat($$.codigoGlobal, " ");
                                                         strcat($$.codigoGlobal, $2.codigo);
                                                         strcat($$.codigoGlobal, ";\n");
                                                       } }
                        | error ;

declar_variables    : ID {  if(enAmbito($1.lexema) == 1)
                              errorYaDeclarado($1.lexema);
                            else
                              TS_InsertaVAR($1.lexema, tipoTmp);
                            
                            $$.codigo = (char*)malloc(strlen($1.lexema) + 1);
                            strcpy($$.codigo,$1.lexema);
                          }
                    | ID IGUAL expresion {  if(enAmbito($1.lexema) == 1)
                                              errorYaDeclarado($1.lexema);
                                            else
                                              TS_InsertaVAR($1.lexema, tipoTmp);
                                            
                                            $$.codigo = (char*)malloc(strlen($1.lexema) + strlen(" = ") + strlen($3.lexema) + 1);
                                            strcpy($$.codigo,$1.lexema);
                                            strcat($$.codigo," = ");
                                            strcat($$.codigo,$3.lexema);
                                         }
                    | declar_variables COMA ID {  if(enAmbito($3.lexema) == 1)
                                                    errorYaDeclarado($3.lexema);
                                                  else
                                                    TS_InsertaVAR($3.lexema, tipoTmp);
                                                  
                                                  $$.codigo = (char*)malloc(strlen($1.codigo) + strlen(", ") + strlen($3.lexema) + 1);
                                                  strcpy($$.codigo,$1.codigo);
                                                  strcat($$.codigo,", ");
                                                  strcat($$.codigo,$3.lexema);
                                                }
                    | declar_variables COMA ID IGUAL expresion {  if(enAmbito($3.lexema) == 1)
                                                                    errorYaDeclarado($3.lexema);
                                                                  else
                                                                    TS_InsertaVAR($3.lexema, tipoTmp);
                                                                    
                                                                  $$.codigo = (char*)malloc(strlen($1.codigo) + strlen(", ") + strlen($3.lexema) + strlen(" = ") + strlen($5.lexema) + 1);
                                                                  strcpy($$.codigo,$1.codigo);
                                                                  strcat($$.codigo,", ");
                                                                  strcat($$.codigo,$3.lexema);
                                                                  strcat($$.codigo," = ");
                                                                  strcat($$.codigo,$5.lexema);
                                                                  } ;

declar_procedimientos : declar_procedimientos declar_proced {
                                                              $$.codigo = (char*)malloc(strlen($1.codigo) + strlen($2.codigo) + 1);
                                                              strcpy($$.codigo, $1.codigo);
                                                              strcat($$.codigo, $2.codigo);
                                                            }
                      | declar_proced {
                                        $$.codigo = (char*)malloc(strlen($1.codigo) + 1);
                                        strcpy($$.codigo, $1.codigo);
                                      };

declar_proced : cabecera_proced bloque  { 
                                          Subprog = 0; 

                                          char *tab = generarTab();
                                          $$.codigo = (char*)malloc(strlen(tab) + strlen($1.codigo) + strlen("\n") + strlen($2.codigo) + strlen(tab) + strlen(";\n\n") + 1);
                                          strcpy($$.codigo, tab);
                                          strcat($$.codigo, $1.codigo);
                                          strcat($$.codigo, "\n");
                                          strcat($$.codigo, $2.codigo);
                                          strcat($$.codigo, tab);
                                          strcat($$.codigo, ";\n\n");
                                        } ;

inicio_cabe_proced : PROCEDIMIENTO ID { 
                                        TS_InsertaPROCED($2.lexema); 

                                        $$.codigo = (char*)malloc(strlen("auto ") + strlen($2.lexema) + strlen("= [=] ") + 1);
                                        strcpy($$.codigo, "auto ");
                                        strcat($$.codigo, $2.lexema);
                                        strcat($$.codigo, "= [=] ");
                                      } ;

cabecera_proced : inicio_cabe_proced PARIZQ lista_parametros COMA lista_para_por_defecto PARDER { 
                                                                                                  Subprog = 1; 

                                                                                                  $$.codigo = (char*)malloc(strlen($1.codigo) + strlen(" (") + strlen($3.codigo)
                                                                                                                     + strlen(", ") + strlen($5.codigo) + strlen(") ") + 1);
                                                                                                  strcpy($$.codigo, $1.codigo);
                                                                                                  strcat($$.codigo, " (");
                                                                                                  strcat($$.codigo, $3.codigo);
                                                                                                  strcat($$.codigo, ", ");
                                                                                                  strcat($$.codigo, $5.codigo);
                                                                                                  strcat($$.codigo, ") ");
                                                                                                }
                | inicio_cabe_proced PARIZQ lista_parametros PARDER { 
                                                                      Subprog = 1; 

                                                                      $$.codigo = (char*)malloc(strlen($1.codigo) + strlen("(") + strlen($3.codigo) + strlen(")") + 1);
                                                                      strcpy($$.codigo, $1.codigo);
                                                                      strcat($$.codigo, "(");
                                                                      strcat($$.codigo, $3.codigo);
                                                                      strcat($$.codigo, ")");
                                                                    }
                | inicio_cabe_proced PARIZQ PARDER  { 
                                                      Subprog = 1; 

                                                      $$.codigo = (char*)malloc(strlen($1.codigo) + strlen(" (") + strlen(") ") + 1);
                                                      strcpy($$.codigo, $1.codigo);
                                                      strcat($$.codigo, " (");
                                                      strcat($$.codigo, ") ");
                                                    }
                | error ;

sentencias  : sentencias sentencia { $$.codigo = (char*)malloc(strlen($1.codigo) + strlen($2.codigo) + 1);
                                     strcpy($$.codigo,$1.codigo);
                                     strcat($$.codigo,$2.codigo); }
            | sentencia { $$.codigo = (char*)malloc(strlen($1.codigo) + 1);
                          strcpy($$.codigo,$1.codigo); } ;

cabecera_for  : PARA sentencia_asignacion HASTA expresion 
                      { char *etiqSalida = etiqueta();
                        char *etiqEntrada = etiqueta();
                        TS_InsertaDescripControl($2.nombre, etiqEntrada, etiqSalida, NULL);
                        char *tab = generarTab();
                        
                        $$.codigo = (char*)malloc(strlen($2.codigo) + strlen(etiqEntrada) + strlen(": ;\n") + strlen($4.codigo) + strlen(tab) + strlen("if (!") + strlen($4.nombre) 
                                    + strlen(") goto ") + strlen(etiqSalida) + strlen(";\n") + 1);
                        
                        strcpy($$.codigo,$2.codigo);
                        strcat($$.codigo,etiqEntrada);
                        strcat($$.codigo,": ;\n");
                        strcat($$.codigo,$4.codigo);
                        
                        strcat($$.codigo,tab);
                        strcat($$.codigo,"if (!");
                        strcat($$.codigo,$4.nombre);
                        strcat($$.codigo,") goto ");
                        strcat($$.codigo,etiqSalida);
                        strcat($$.codigo,";\n");
                      }

sentencia   : bloque {  $$.codigo = (char*)malloc(strlen($1.codigo) + 1);
                        strcpy($$.codigo,$1.codigo);
                     }
            | sentencia_asignacion { char *tab = generarTab();
                                     $$.codigo = (char*)malloc(strlen(tab) + strlen("{\n") + strlen($1.codigo) + strlen(tab) + strlen("}\n\n") + 1);
                                     strcpy($$.codigo,tab);
                                     strcat($$.codigo,"{\n");
                                     strcat($$.codigo,$1.codigo);
                                     strcat($$.codigo,tab);
                                     strcat($$.codigo,"}\n\n"); }
            | sentencia_if {  
                              char *tab = generarTab();
                              $$.codigo = (char*)malloc(strlen(tab) + strlen("{\n") + strlen($1.codigo) + strlen(tab) + strlen("}\n\n") + 1);
                              strcpy($$.codigo,tab);
                              strcat($$.codigo,"{\n");
                              strcat($$.codigo,$1.codigo);
                              strcat($$.codigo,tab);
                              strcat($$.codigo,"}\n\n");
                           }
            | MIENTRAS PARIZQ expresion PARDER sentencia
            {
              bucleWhile(&$$,&$1,&$2,&$3,&$4,&$5);
            }
            | cabecera_for ITERANDO expresion HACER sentencia  
                                  { char *tab = generarTab();
                                    descriptorDeInstrControl descrip = buscarDescrip();
                                    $$.codigo = (char*)malloc(strlen(tab) + strlen("{\n") + strlen($1.codigo) + strlen(tab) + strlen("{\n") + strlen($5.codigo) + strlen($3.codigo) + strlen(tab) 
                                                + strlen(descrip.nombreVarControl) + strlen(" += ") + strlen($3.nombre) + strlen(";\n") + strlen(tab) + strlen("goto ") 
                                                + strlen(descrip.etiquetaEntrada) + strlen(";\n") + strlen(tab) + strlen("}\n") + strlen(descrip.etiquetaSalida) + strlen(": ;\n") + strlen(tab) + strlen("}\n\n") + 1);
                                    strcpy($$.codigo,tab);
                                    strcat($$.codigo,"{\n");
                                    strcat($$.codigo,$1.codigo);
                                    strcat($$.codigo,tab);
                                    strcat($$.codigo,"{\n");
                                    strcat($$.codigo,$5.codigo);
                                    strcat($$.codigo,$3.codigo);
                                    strcat($$.codigo,tab);
                                    strcat($$.codigo,descrip.nombreVarControl);
                                    strcat($$.codigo," += ");
                                    strcat($$.codigo,$3.nombre);
                                    strcat($$.codigo,";\n");
                                    strcat($$.codigo,tab);
                                    strcat($$.codigo,"goto ");
                                    strcat($$.codigo,descrip.etiquetaEntrada);
                                    strcat($$.codigo,";\n");
                                    strcat($$.codigo,tab);
                                    strcat($$.codigo,"}\n");
                                    strcat($$.codigo,descrip.etiquetaSalida);
                                    strcat($$.codigo,": ;\n");
                                    strcat($$.codigo,tab);
                                    strcat($$.codigo,"}\n\n");

                                    TOPE -= 1;
                                  }
            | LEER lista_identificadores PYC  {
                                                char *tab = generarTab();
                                                $$.codigo = (char*)malloc(strlen(tab) + strlen("{\n") + strlen($2.codigo) + strlen(tab) + strlen("}\n\n") + 1);
                                                strcpy($$.codigo,tab);
                                                strcat($$.codigo,"{\n");
                                                strcat($$.codigo,$2.codigo);
                                                strcat($$.codigo,"\n");
                                                strcat($$.codigo,tab);
                                                strcat($$.codigo,"}\n\n");
                                              }

            | IMPRIMIR mensajes PYC {
                                      char *tab = generarTab();
                                      $$.codigo = (char*)malloc(strlen(tab) + strlen("{\n") + strlen($2.codigo) + strlen(tab) + strlen("}\n\n") + 1);
                                      strcpy($$.codigo, tab);
                                      strcat($$.codigo, "{\n");
                                      strcat($$.codigo, $2.codigo);
                                      strcat($$.codigo, tab);
                                      strcat($$.codigo, "}\n\n");
                                    } 
            | llamada_proced  {
                                char *tab = generarTab();
                                $$.codigo = (char*)malloc(strlen(tab) + strlen("{\n") + strlen($1.codigoProced) + strlen(tab) 
                                + strlen($1.codigo) + strlen("\n") + strlen(tab) + strlen("}\n\n") + 1);
                                strcpy($$.codigo,tab);
                                strcat($$.codigo,"{\n");
                                strcat($$.codigo,$1.codigoProced);
                                strcat($$.codigo,tab);
                                strcat($$.codigo,$1.codigo);
                                strcat($$.codigo,"\n");
                                strcat($$.codigo,tab);
                                strcat($$.codigo,"}\n\n");
                              }
            | ID MOV_LISTA PYC {  $1.tipo = buscarTipoVariable($1.lexema);
                                  if (esLista($1.tipo)) { 
                                    $$.tipo = $1.tipo; 
                                    genCodMoverLista(&$$, &$1, $2.lexema);
                                  } else {
                                    errorTipoOperador($2.lexema);
                                  }
                                }
            | DOLLAR ID PYC {$2.tipo = buscarTipoVariable($2.lexema);
                              if (esLista($2.tipo)) { 
                                $$.tipo = $2.tipo; 
                                genCodComienzoLista(&$$, &$2);
                              } else {
                                errorTipoOperador($1.lexema);
                              }
                            };
                                                                      
sentencia_asignacion  : ID IGUAL expresion PYC {
                                                if (declarado($1.lexema) == 0) {
                                                  errorNoDeclarado($1.lexema);
                                                }
                                                else {
                                                  if ($1.tipo == entero && $3.tipo == real) {

                                                  } else if ($1.tipo == real && $3.tipo == entero) {

                                                  } else if (buscarTipoVariable($1.lexema) != $3.tipo){
                                                    mostrarErrorTipoAsig($3.tipo);
                                                  }
                                                }

                                                char *tab = generarTab();
                                                $$.nombre = strdup($1.lexema);
                                                $$.codigo = (char*)malloc(strlen($3.codigo) + strlen(tab) + strlen($1.lexema) + strlen(" = ") + strlen($3.nombre) + strlen(";\n") + 1);
                                                strcpy($$.codigo,$3.codigo);
                                                strcat($$.codigo,tab);
                                                strcat($$.codigo,$1.lexema);
                                                strcat($$.codigo," = ");
                                                strcat($$.codigo,$3.nombre);
                                                strcat($$.codigo,";\n");
                                                } ;

cabecera_if : SI PARIZQ expresion PARDER { char *etiqSalida = etiqueta();
                                           
                                           char *etiqElse = etiqueta();
                                           
                                           TS_InsertaDescripControl(NULL, NULL, etiqSalida, etiqElse);
                                           
                                           char *tab = generarTab();

                                           

                                           $$.codigo = (char*)malloc(strlen($3.codigo) + strlen(tab) + strlen("if (!") + strlen($3.nombre) + strlen(") goto ") + strlen(etiqElse) + strlen(";\n") + 1);
                                           
                                           strcpy($$.codigo,$3.codigo);
                                           strcat($$.codigo,tab);
                                           strcat($$.codigo,"if (!");
                                           strcat($$.codigo,$3.nombre);
                                           strcat($$.codigo,") goto ");
                                           strcat($$.codigo,etiqElse);
                                           strcat($$.codigo,";\n");
                                         } ;

sentencia_if    : cabecera_if sentencia { descriptorDeInstrControl descrip = buscarDescrip();
                                          $$.codigo = (char*)malloc(strlen($1.codigo) + strlen($2.codigo) + strlen(descrip.etiquetaElse) + strlen(": ;\n") + 1);
                                          strcpy($$.codigo,$1.codigo);
                                          strcat($$.codigo,$2.codigo);
                                          strcat($$.codigo,descrip.etiquetaElse);
                                          strcat($$.codigo,": ;\n");

                                          TOPE -= 1; 
                                        }
                | cabecera_if sentencia
                  OTROCASO sentencia {  descriptorDeInstrControl descrip = buscarDescrip();
                                        char *tab = generarTab();
                                        $$.codigo = (char*)malloc(strlen($1.codigo) + strlen($2.codigo) + strlen(tab) + strlen("goto ") + strlen(descrip.etiquetaSalida)
                                                     + strlen(";\n") + strlen(descrip.etiquetaElse) + strlen(": ;\n") + strlen($4.codigo) + strlen(descrip.etiquetaSalida)
                                                     + strlen(": ;\n") + 1);
                                        strcpy($$.codigo,$1.codigo);
                                        strcat($$.codigo,$2.codigo);
                                        strcat($$.codigo,tab);
                                        strcat($$.codigo,"goto ");
                                        strcat($$.codigo,descrip.etiquetaSalida);
                                        strcat($$.codigo,";\n");
                                        strcat($$.codigo,descrip.etiquetaElse);
                                        strcat($$.codigo,": ;\n");
                                        strcat($$.codigo,$4.codigo);
                                        strcat($$.codigo,descrip.etiquetaSalida);
                                        strcat($$.codigo,": ;\n");

                                        TOPE -= 1;
                                     };

lista_identificadores   : lista_identificadores COMA ID {
                                                          dtipo tipo = buscarTipoVariable($3.lexema);
                                                          char *tab = generarTab();
                                                          char *etiqPrintf = etiquetaPrinf(tipo);

                                                          $$.codigo = (char*)malloc(strlen($1.codigo) + strlen(tab) + strlen("scanf(\"") 
                                                          + strlen(etiqPrintf) + strlen("\", &") + strlen($3.lexema) + strlen("); getchar();\n") + 1);
                                                          strcpy($$.codigo, $1.codigo);
                                                          strcat($$.codigo, tab);
                                                          strcat($$.codigo, "scanf(\"");
                                                          strcat($$.codigo, etiqPrintf);
                                                          strcat($$.codigo, "\", &");
                                                          strcat($$.codigo, $3.lexema);
                                                          strcat($$.codigo, "); getchar();\n");
                                                        }
                        | ID {  
                                if (declarado($1.lexema) == 0) { 
                                  errorNoDeclarado($1.lexema);
                                }
                                else {
                                  dtipo tipo = buscarTipoVariable($1.lexema);
                                  char *tab = generarTab();
                                  
                                  char *etiqPrintf = etiquetaPrinf(tipo);
                                  
                                  $$.codigo = (char*)malloc(strlen(tab) + strlen("scanf(\"") + strlen(etiqPrintf) + strlen("\", &") + strlen($1.lexema) + strlen("); getchar();\n") + 1);
                                  strcpy($$.codigo, tab);
                                  strcat($$.codigo, "scanf(\"");
                                  strcat($$.codigo, etiqPrintf);
                                  strcat($$.codigo, "\", &");
                                  strcat($$.codigo, $1.lexema);
                                  strcat($$.codigo, "); getchar();\n");
                                }
                              };

mensajes    : mensajes COMA mensaje {
                                      $$.codigo = (char*)malloc(strlen($1.codigo) + strlen($3.codigo) + 1);
                                      strcpy($$.codigo,$1.codigo);
                                      strcat($$.codigo,$3.codigo);
                                    }
            | mensaje {
                        $$.codigo = (char*)malloc(strlen($1.codigo) + 1);
                        strcpy($$.codigo,$1.codigo);
                      } ;

mensaje : expresion { 
                      generarCodMensajeExp(&$$, &$1);
                    }
        | CADENA {
                    generarCodMensajeCad(&$$, &$1);
                  } ;

inicio_llamada : ID PARIZQ { $$.lexema = $1.lexema ;
                             posProced = buscarProced($1.lexema) ; 
                             if(posProced == -1){ 
                               mostrarErrorProcedDesco($1.lexema); 
                             }
                             posParam = 0; 

                             $$.codigo = (char*)malloc(strlen($1.lexema) + strlen("(") + 1);
                             strcpy($$.codigo, $1.lexema);
                             strcat($$.codigo, "("); 
                            };

llamada_proced  : inicio_llamada lista_expresiones PARDER PYC { if(posProced != -1) {
                                                                  if(posParam < TS[posProced].parametrosMin) {
                                                                    mostrarErrorMinParam($1.lexema);
                                                                  }
                                                                  else {
                                                                    comprobarParam();
                                                                  }
                                                                } 

                                                                $$.codigo = (char*)malloc(strlen($1.codigo) + strlen($2.codigo) + strlen(");") + 1);
                                                                $$.codigoProced = (char*)malloc(strlen($2.codigoProced) + 1);
                                                                strcpy($$.codigoProced, $2.codigoProced);
                                                                strcpy($$.codigo, $1.codigo);
                                                                strcat($$.codigo, $2.codigo);
                                                                strcat($$.codigo, ");");
                                                              } 
                | inicio_llamada PARDER PYC { if(posProced != -1) {
                                                if(posParam < TS[posProced].parametrosMin) {
                                                  mostrarErrorMinParam($1.lexema);
                                                }
                                                else {
                                                  comprobarParam();
                                                }
                                              } 

                                              $$.codigoProced = (char*)malloc(strlen("") + 1);
                                              strcpy($$.codigoProced, "");

                                              $$.codigo = (char*)malloc(strlen($1.codigo) + strlen(");") + 1);
                                              strcpy($$.codigo, $1.codigo);
                                              strcat($$.codigo, ");");
                                            };

lista_expresiones   : lista_expresiones COMA expresion { if($$.tipo != $3.tipo) {
                                                           $$.tipo = desconocido;
                                                         }
                                                         if(posProced != -1) {
                                                           if(posParam >= TS[posProced].parametrosMax) {
                                                             mostrarErrorMaxParam(TS[posProced].nombre);
                                                           }
                                                           else {
                                                             listaParam[posParam] = $3.tipo;
                                                             posParam += 1;  
                                                           }
                                                         } 
                                                          $$.codigoProced = (char*)malloc(strlen($1.codigoProced) + strlen($3.codigo) + strlen("\n") + 1);
                                                          strcpy($$.codigoProced, $1.codigoProced);
                                                          strcat($$.codigoProced, $3.codigo);
                                                          strcat($$.codigoProced, "\n");

                                                          $$.codigo = (char*)malloc(strlen($1.codigo) + strlen(", ") + strlen($3.nombre) + 1);
                                                          strcpy($$.codigo, $1.codigo);
                                                          strcat($$.codigo, ", ");
                                                          strcat($$.codigo, $3.nombre); 
                                                        }
                    | expresion { $$.tipo = $1.tipo;
                                  if(posProced != -1) {
                                    if(posParam >= TS[posProced].parametrosMax) {
                                      mostrarErrorMaxParam(TS[posProced].nombre);
                                    }
                                    else {
                                      listaParam[posParam] = $1.tipo;
                                      posParam += 1;  
                                    } 
                                  } 
                                  
                                  $$.codigoProced = (char*)malloc(strlen($1.codigo) + strlen("\n") + 1);
                                  strcpy($$.codigoProced, $1.codigo);
                                  strcat($$.codigoProced, "\n");

                                  $$.codigo = (char*)malloc(strlen($1.nombre) + 1);
                                  strcpy($$.codigo, $1.nombre);  
                                };

expresion   : PARIZQ expresion PARDER { $$.tipo = $2.tipo;
                                        $$.nombre = $2.nombre;
                                        $$.lexema = $2.lexema;
                                        $$.codigo = (char*)malloc(strlen($2.codigo) + 1);
                                        strcat($$.codigo,$2.codigo);
                                      }
            | DECRE_PRE expresion {
              if (esNumerico($2.tipo)){
                $$.tipo = $2.tipo;
                generarCodExpresionUnario(&$$,&$1,&$2,$1.lexema);
              } else {
                errorTipoOperador($1.lexema);
              }
            }
            | INCRE_PRE expresion {
              if (esNumerico($2.tipo)){
                $$.tipo = $2.tipo;
                generarCodExpresionUnario(&$$,&$1,&$2,$1.lexema);
              } else {
                errorTipoOperador($1.lexema);
              }
            } 
            | NOT expresion {
              if ($2.tipo == booleano){
                $$.tipo = $2.tipo;
                generarCodExpresionUnario(&$$,&$1,&$2,"!");
              } else {
                errorTipoOperador($1.lexema);
              } 
            }
            | UNARIO_PRE_LISTA expresion {
              if (esLista($2.tipo)) {
                if ($1.atrib == 0) {
                  $$.tipo = entero;
                  genCodLongitudLista(&$$, &$2);
                } else if ($1.atrib == 1) {
                  $$.tipo = listaATipo($2.tipo);
                  genCodObtenerElementoActual(&$$, &$2);
                }
              } else {
                errorTipoOperador($1.lexema);
              }
            }
            | ADITIVOS expresion %prec UNARIOS {
              if (esNumerico($2.tipo)){
                $$.tipo = $2.tipo;
                generarCodExpresionUnario(&$$,&$1,&$2,$1.lexema);
              } else {
                errorTipoOperador($1.lexema);
              }
            }
            | expresion ADITIVOS expresion {
              int correcto = 0;
              if ($1.tipo == entero && $3.tipo == entero) {
                $$.tipo = entero;
                correcto = 1;
              } else if ($1.tipo == real && $3.tipo == real) {
                $$.tipo = real;
                correcto = 1;
              } else if ($1.tipo == lista_entero && $3.tipo == entero) {
                $$.tipo = lista_entero;
                if ($2.atrib == 0)
                  genCodSumarElementoALista(&$$, &$1, &$3);
                else if ($2.atrib == 1)
                  genCodRestarElementoALista(&$$, &$1, &$3);
                correcto = 2;
              } else if ($1.tipo == lista_real && $3.tipo == real) {
                $$.tipo = lista_real;
                if ($2.atrib == 0)
                  genCodSumarElementoALista(&$$, &$1, &$3);
                else if ($2.atrib == 1)
                  genCodRestarElementoALista(&$$, &$1, &$3);
                correcto = 2;
              } else if ($2.atrib == 0) {
                if ($1.tipo == real && $3.tipo == lista_real) {
                  $$.tipo = lista_real;
                  genCodSumarElementoALista(&$$, &$3, &$1);
                  correcto = 2;
                } else if ($1.tipo == entero && $3.tipo == lista_entero) {
                  $$.tipo = lista_entero;
                  genCodSumarElementoALista(&$$, &$3, &$1);
                  correcto = 2;
                } else {
                  errorTipoOperador($2.lexema);
                }
              } else {
                errorTipoOperador($2.lexema);
              }
              
              if(correcto == 1) {
                generarCodExpresion(&$$,&$1,&$2,&$3,$2.lexema);
              }
              else if(correcto != 2){
                generarCodNull(&$$);
              }
            }
            | expresion DECRE_PRE expresion {
              if (esLista($1.tipo) && $3.tipo == entero) {
                $$.tipo = $1.tipo;
                genCodEliminarElementoPosicion(&$$, &$1, &$3);
              } else {
                errorTipoOperador($2.lexema);
              }
            }
            | expresion ELEM_POSI expresion %prec ELEM_POSI_BINA {
              if(esLista($1.tipo) && $3.tipo == entero) {
                $$.tipo = listaATipo($1.tipo);
                genCodObtenerElementoPosicion(&$$, &$1, &$3);
              } else {
                errorTipoOperador($2.lexema);
              }
            }
            | expresion MULTIPLICATIVOS expresion {
              int correcto = 0;
              if ($2.atrib == 0) {
                if ($1.tipo == entero && $3.tipo == entero) {
                  $$.tipo = entero;
                  correcto = 1;
                } else if ($1.tipo == real && $3.tipo == real) {
                  $$.tipo = real;
                  correcto = 1;
                } else if ($1.tipo == lista_entero && $3.tipo == entero) {
                  $$.tipo = lista_entero;
                  genCodMultiplicarElementoALista(&$$, &$1, &$3);
                  correcto = 2;
                } else if ($1.tipo == lista_real && $3.tipo == real) {
                  $$.tipo = lista_real;
                  genCodMultiplicarElementoALista(&$$, &$1, &$3);
                  correcto = 2;
                } else if ($1.tipo == real && $3.tipo == lista_real) {
                  $$.tipo = lista_real;
                  genCodMultiplicarElementoALista(&$$, &$3, &$1);
                  correcto = 2;
                } else if ($1.tipo == entero && $3.tipo == lista_entero) {
                  $$.tipo = lista_entero;
                  genCodMultiplicarElementoALista(&$$, &$3, &$1);
                  correcto = 2;
                } else {
                  errorTipoOperador($2.lexema);
                }
              } else if ($2.atrib == 1) {
                if ($1.tipo == entero && $3.tipo == entero) {
                  $$.tipo = entero;
                  correcto = 1;
                } else if ($1.tipo == real && $3.tipo == real) {
                  $$.tipo = real;
                  correcto = 1;
                } else if ($1.tipo == lista_entero && $3.tipo == entero) {
                  $$.tipo = lista_entero;
                  genCodDividirElementoALista(&$$, &$1, &$3);
                  correcto = 2;
                } else if ($1.tipo == lista_real && $3.tipo == real) {
                  $$.tipo = lista_real;
                  genCodDividirElementoALista(&$$, &$1, &$3);
                  correcto = 2;
                } else {
                  errorTipoOperador($2.lexema);
                }
              } else if ($2.atrib == 2) {
                if ($1.tipo == lista_entero && $3.tipo == entero) {
                  $$.tipo = lista_entero;
                  genCodEliminarListaAPartirPosicion(&$$, &$1, &$3);
                  correcto = 2;
                } else if ($1.tipo == lista_real && $3.tipo == entero) {
                  $$.tipo = lista_real;
                  genCodEliminarListaAPartirPosicion(&$$, &$1, &$3);
                  correcto = 2;
                } else if ($1.tipo == lista_caracter && $3.tipo == entero) {
                  $$.tipo = lista_caracter;
                  genCodEliminarListaAPartirPosicion(&$$, &$1, &$3);
                  correcto = 2;
                } else if ($1.tipo == lista_booleano && $3.tipo == entero) {
                  $$.tipo = lista_booleano;
                  genCodEliminarListaAPartirPosicion(&$$, &$1, &$3);
                  correcto = 2;
                } else if ($1.tipo == entero && $3.tipo == entero) {
                  $$.tipo = entero;
                  correcto = 1;
                } else {
                  errorTipoOperador($2.lexema);
                }
              }

              if(correcto == 1) {
                generarCodExpresion(&$$,&$1,&$2,&$3,$2.lexema);
              }
              else if(correcto != 2){
                generarCodNull(&$$);
              }
            }
            | expresion POTENCIAS expresion {
              int correcto = 0;
              if ($1.tipo == entero && $3.tipo == entero) {
                $$.tipo = entero;
                correcto = 1;
              } else if ($1.tipo == real && $3.tipo == real) {
                $$.tipo = real;
                correcto = 1;
              } else if (esLista($1.tipo) && esLista($3.tipo) && $1.tipo == $3.tipo) {
                $$.tipo = $1.tipo;
                genCodConcatenarListas(&$$, &$1, &$3);
                correcto = 2;
              } else {
                errorTipoOperador($2.lexema);
              }

              if(correcto == 1) {
                potencia(&$$,&$1,&$2,&$3);
              }
              else if(correcto != 2){
                generarCodNull(&$$);
              }
            }
            | expresion IGUALDAD expresion {
              int correcto = 0;
              if (!esLista($1.tipo) && !esLista($3.tipo)) {
                if ($1.tipo == $3.tipo) {
                  $$.tipo = booleano;
                  correcto = 1;
                } else {
                  errorTipoOperador($2.lexema);
                }
              } else {
                errorTipoOperador($2.lexema);
              }

              if(correcto == 1) {
                generarCodExpresion(&$$,&$1,&$2,&$3,$2.lexema);
              }
              else {
                generarCodNull(&$$);
              }
            }
            | expresion RELACION expresion { 
              int correcto = 0;
              if ($1.tipo == entero && $3.tipo == entero) {
                $$.tipo = booleano;
                correcto = 1;
              } else if ($1.tipo == real && $3.tipo == real) {
                $$.tipo = booleano;
                correcto = 1;
              } else {
                errorTipoOperador($2.lexema);
              }

              if(correcto == 1) {
                generarCodExpresion(&$$,&$1,&$2,&$3,$2.lexema);
              }
              else {
                generarCodNull(&$$);
              }
            }
            | expresion OR expresion {
              if ($1.tipo == booleano && $3.tipo == booleano) {
                $$.tipo = booleano;
                generarCodExpresion(&$$,&$1,&$2,&$3,"||");

              } else {
                errorTipoOperador($2.lexema);
                $$.codigo = (char*)malloc(strlen("") + 1);
                strcpy($$.codigo,"");
                $$.nombre = strdup("");
              }
            }
            | expresion AND expresion {
              if ($1.tipo == booleano && $3.tipo == booleano) {
                $$.tipo = booleano;
                generarCodExpresion(&$$,&$1,&$2,&$3,"&&");
              } else {
                errorTipoOperador($2.lexema);
                $$.codigo = (char*)malloc(strlen("") + 1);
                strcpy($$.codigo,"");
                $$.nombre = strdup("");
              }
            }
            | expresion XOR expresion {
              if ($1.tipo == booleano && $3.tipo == booleano) {
                $$.tipo = booleano;
                generarCodExpresion(&$$,&$1,&$2,&$3,"^");

              
              } else {
                errorTipoOperador($2.lexema);
                $$.codigo = (char*)malloc(strlen("") + 1);
                strcpy($$.codigo,"");
                $$.nombre = strdup("");
              }
            }
            | expresion INCRE_PRE expresion ELEM_POSI expresion {
              if (esLista($1.tipo) && $3.tipo == listaATipo($1.tipo) && $5.tipo == entero) {
                $$.tipo = $1.tipo;
                genCodInsertarElementoLista(&$$, &$1, &$3, &$5);
              } else {
                errorTipoOperador2($2.lexema, $4.lexema);
              }
            }
            | ID  { if (declarado($1.lexema) == 0) {
                      errorNoDeclarado($1.lexema);
                    }
                    else {
                      $$.tipo = buscarTipoVariable($1.lexema);

                      $$.lexema = $1.lexema;
                      char *varTmp = temporal();
                      char *tipoTmp = obtenerTipo($$.tipo);
                      char *tab = generarTab();
                      $$.codigo = (char*)malloc(strlen(tab) + strlen(tipoTmp) + strlen(" ") + strlen(varTmp) + strlen(" = ") + strlen($1.lexema) + strlen(";\n") + 1);
                      strcpy($$.codigo,tab);
                      strcat($$.codigo,tipoTmp);
                      strcat($$.codigo," ");
                      strcat($$.codigo,varTmp);
                      strcat($$.codigo," = ");
                      strcat($$.codigo,$1.lexema);
                      strcat($$.codigo,";\n");

                      $$.nombre = strdup(varTmp); 
                    }
                  }
            | agregado_lista { $$.tipo = $1.tipo;
                               $$.lexema = $1.lexema; }
            | CONSTANTE { $$.tipo = $1.tipo;
                          if($1.tipo == booleano) {
                            if(strcmp($1.lexema,"verdadero") == 0) {
                              $$.lexema = "true";
                            }
                            else if(strcmp($1.lexema,"falso") == 0) {
                              $$.lexema = "false";
                            }
                          }
                          else {
                            $$.lexema = $1.lexema;
                          }
                          char *varTmp = temporal();
                          char *tipoTmp = obtenerTipo($1.tipo);
                          char *tab = generarTab();
                          $$.codigo = (char*)malloc(strlen(tab) + strlen(tipoTmp) + strlen(" ") + strlen(varTmp) + strlen(" = ") + strlen($$.lexema) + strlen(";\n") + 1);
                          strcpy($$.codigo,tab);
                          strcat($$.codigo,tipoTmp);
                          strcat($$.codigo," ");
                          strcat($$.codigo,varTmp);
                          strcat($$.codigo," = ");
                          strcat($$.codigo,$$.lexema);
                          strcat($$.codigo,";\n");

                          $$.nombre = strdup(varTmp); 
                        }
            | error ;

agregado_lista  : CORCHIZQ lista_expresiones CORCHDER { $$.tipo = $2.tipo; };

tipos   : TIPOS { tipoTmp = $1.tipo;
                  if($$.atrib == 0) {
                    $$.codigo = (char*)malloc(strlen("int") + 1);
                    strcpy($$.codigo,"int");
                  }
                  else if($$.atrib == 1) {
                    $$.codigo = (char*)malloc(strlen("float") + 1);
                    strcpy($$.codigo,"float");
                  }
                  else if($$.atrib == 2) {
                    $$.codigo = (char*)malloc(strlen("bool") + 1);
                    strcpy($$.codigo,"bool");
                  }
                  else if($$.atrib == 3) {
                    $$.codigo = (char*)malloc(strlen("char") + 1);
                    strcpy($$.codigo,"char");
                  } }
        | LISTADE TIPOS { tipoTmp = obtenerTipoLista($2.tipo); 
                          if(tipoTmp == 4) {
                            $$.codigo = (char*)malloc(strlen("Lista<int>") + 1);
                            strcpy($$.codigo,"Lista<int>");
                          }
                          else if(tipoTmp == 5) {
                            $$.codigo = (char*)malloc(strlen("Lista<float>") + 1);
                            strcpy($$.codigo,"Lista<float>");
                          }
                          else if(tipoTmp == 6) {
                            $$.codigo = (char*)malloc(strlen("Lista<bool>") + 1);
                            strcpy($$.codigo,"Lista<bool>");
                          }
                          else if(tipoTmp== 7) {
                            $$.codigo = (char*)malloc(strlen("Lista<char>") + 1);
                            strcpy($$.codigo,"Lista<char>");
                          }
                        } ;

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