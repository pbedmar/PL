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
"#" { yylval.atrib = 0 ; return UNARIO_PRE_LISTA; }
"?" { yylval.atrib = 0 ; return UNARIO_PRE_LISTA; }
"+" { yylval.atrib = 0 ; return ADITIVOS; }
"-" { yylval.atrib = 1 ; return ADITIVOS; }
"*" { yylval.atrib = 0 ; return MULTIPLICATIVOS; }
"/" { yylval.atrib = 1 ; return MULTIPLICATIVOS; }
"**" { yylval.atrib = 0 ; return POTENCIAS; }
"%" { yylval.atrib = 2 ; return MULTIPLICATIVOS; }
"==" { yylval.atrib = 0 ; return IGUALDAD; }
"!=" { yylval.atrib = 1 ; return IGUALDAD; }
"<" { yylval.atrib = 0 ; return RELACION; }
"<=" { yylval.atrib = 1 ; return RELACION; }
">" { yylval.atrib = 2 ; return RELACION; }
">=" { yylval.atrib = 3 ; return RELACION; }
"y" { yylval.atrib = 0 ; return AND; }
"o" { yylval.atrib = 0 ; return OR; }
"o_exclusiva" { yylval.atrib = 0 ; return XOR; }
"@" { yylval.atrib = 0 ; return ELEM_POSI; }
"entero"    { yylval.atrib = 0 ; return TIPOS; }
"flotante"  { yylval.atrib = 1 ; return TIPOS; }
"booleano"  { yylval.atrib = 2 ; return TIPOS; }
"caracter"  { yylval.atrib = 3 ; return TIPOS; }
{cadena} { yylval.atrib = 0 ; return CADENA; }
{constante_entero}    { yylval.atrib = 0 ; yylval.tipo = entero ; return CONSTANTE; }
{constante_real}      { yylval.atrib = 1 ; yylval.tipo = real ; return CONSTANTE; }
{constante_booleano}  { yylval.atrib = 2 ; yylval.tipo = booleano ; return CONSTANTE; }
{constante_caracter}  { yylval.atrib = 3 ; yylval.tipo = caracter ; return CONSTANTE; }
{id} { yylval.lexema = strdup(yytext) ; return ID; }
\n  {linea_actual++; }
[ \t]+  ;
.       { lexerror(yytext); }

%%