%option noyywrap

%{
/**********************************************************
 **
 ** Fichero: PRACTICA3.L
 ** Función: Pruebas de FLEX para prácticas de PL
 **
 **********************************************************/


  #include <stdio.h>
  #include <stdlib.h>
  #include "string.h"
%}

letra [a-z]|[A-Z]
digitoSC [1-9]
digitoCC [0-9]

cadena \"[^\"]*\"
id ({letra})+({letra}|{digitoCC}|_)*
constante_entero {digitoSC}({digitoCC})*|0
constante_real ({digitoSC}({digitoCC})*|0).({digitoCC})+
constante_booleano "verdadero"|"falso"
constante_caracter '[^\"']'
%%

"principal" { yylval.atrib = 0 ; return PRINCIPAL; }
"{"  { yylval.atrib = 0 ; return LLAVEIZQ; }
"}"  { yylval.atrib = 0 ; return LLAVEDER; }
","  { yylval.atrib = 0 ; return COMA; }
"lista de" { yylval.atrib = 0 ; return LISTADE; }
"procedimiento"  { yylval.atrib = 0 ; return PROCEDIMIENTO; }
")"  { yylval.atrib = 0 ; return PARDER; }
"("  { yylval.atrib = 0 ; return PARIZQ; }
"["  { yylval.atrib = 0 ; return CORCHIZQ; }
"]"  { yylval.atrib = 0 ; return CORCHDER; }
"="  { yylval.atrib = 0 ; return IGUAL; } 
"inicio_var" { yylval.atrib = 0 ; return INICIOVAR; }
"fin_var" { yylval.atrib = 0 ; return FINVAR; }
"si" { yylval.atrib = 0 ; return SI; }
"mientras" { yylval.atrib = 0 ; return MIENTRAS; }
"en otro caso" { yylval.atrib = 0 ; return OTROCASO; }
"para" { yylval.atrib = 0 ; return PARA; }
"hasta" { yylval.atrib = 0 ; return HASTA; }
"iterando" { yylval.atrib = 0 ; return ITERANDO; }
"hacer" { yylval.atrib = 0 ; return HACER; }
"leer" { yylval.atrib = 0 ; return LEER; }
"imprimir" { yylval.atrib = 0 ; return IMPRIMIR; }
"<<" { yylval.atrib = 0 ; return MOV_LISTA; }
">>" { yylval.atrib = 1 ; return MOV_LISTA; }
"$" { yylval.atrib = 0 ; return DOLLAR; }
";" { yylval.atrib = 0 ; return PYC; }
"++" { yylval.atrib = 0 ; return INCRE_PRE; }
"--" { yylval.atrib = 0 ; return DECRE_PRE; }
"no" { yylval.atrib = 0 ; return NOT; }
"#" { yylval.atrib = 0 ;  UNARIO_PRE_LISTA; }
"?" { yylval.atrib = 0 ;  UNARIO_PRE_LISTA; }
"+" { yylval.atrib = 0 ;  ADITIVOS; }
"-" { yylval.atrib = 1 ;  ADITIVOS; }
"*" { yylval.atrib = 0 ;  MULTIPLICATIVOS; }
"/" { yylval.atrib = 1 ;  MULTIPLICATIVOS; }
"**" { yylval.atrib = 0 ; return POTENCIAS; }
"%" { yylval.atrib = 2 ;  MULTIPLICATIVOS; }
"==" { yylval.atrib = 0 ; return IGUALDAD; }
"!=" { yylval.atrib = 1 ; return IGUALDAD; }
"<" { yylval.atrib = 0 ;  RELACION; }
"<=" { yylval.atrib = 1 ; return RELACION; }
">" { yylval.atrib = 2 ;  RELACION; }
">=" { yylval.atrib = 3 ; return RELACION; }
"y" { yylval.atrib = 0 ;  AND; }
"o" { yylval.atrib = 0 ;  OR; }
"o_exclusiva" { yylval.atrib = 0 ; return XOR; }
"@" { yylval.atrib = 0 ; return ELEM_POSI; }
"entero"    { yylval.atrib = 0 ; return TIPOS; }
"flotante"  { yylval.atrib = 1 ; return TIPOS; }
"booleano"  { yylval.atrib = 2 ; return TIPOS; }
"caracter"  { yylval.atrib = 3 ; return TIPOS; }
{cadena} { yylval.atrib = 0 ; return CADENA; }
{constante_entero}    { yylval.atrib = 0 ; yylval.tipo = dtipo.entero ; return CONSTANTE; }
{constante_real}      { yylval.atrib = 1 ; yylval.tipo = dtipo.real ; return CONSTANTE; }
{constante_booleano}  { yylval.atrib = 2 ; yylval.tipo = dtipo.booleano ; return CONSTANTE; }
{constante_caracter}  { yylval.atrib = 3 ; yylval.tipo = dtipo.caracter ; return CONSTANTE; }
{id} { yylval.lexema = strdup(yytext) ; return ID; }
\n  {linea_actual++; }
[ \t]+  ;
.       { lexerror(yytext); }

%%