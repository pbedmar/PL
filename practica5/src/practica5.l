%option noyywrap

%{
/**********************************************************
 **
 ** Fichero: PRACTICA5.L
 ** Función: Pruebas de FLEX para prácticas de PL
 **
 **********************************************************/

  #define _POSIX_C_SOURCE 200809L

  #include <stdlib.h>
  #include <string.h>
  #include <stdio.h>
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

"principal" { return PRINCIPAL; }
"{"  { return LLAVEIZQ; }
"}"  { return LLAVEDER; }
","  { return COMA; }
"lista de" { return LISTADE; }
"procedimiento"  { return PROCEDIMIENTO; }
")"  { return PARDER; }
"("  { return PARIZQ; }
"["  { return CORCHIZQ; }
"]"  { return CORCHDER; }
"="  { return IGUAL; } 
"inicio_var" { return INICIOVAR; }
"fin_var" { return FINVAR; }
"si" { return SI; }
"mientras" { return MIENTRAS; }
"en otro caso" { return OTROCASO; }
"para" { return PARA; }
"hasta" { return HASTA; }
"iterando" { return ITERANDO; }
"hacer" { return HACER; }
"leer" { return LEER; }
"imprimir" { return IMPRIMIR; }
"<<" { yylval.atrib = 0 ; yylval.lexema = "<<" ; return MOV_LISTA; }
">>" { yylval.atrib = 1 ; yylval.lexema = ">>" ; return MOV_LISTA; }
"$" { yylval.atrib = 0 ; yylval.lexema = "$" ; return DOLLAR; }
";" { return PYC; }
"++" { yylval.atrib = 0 ; yylval.lexema = "++" ; return INCRE_PRE; }
"--" { yylval.atrib = 0 ; yylval.lexema = "--" ; return DECRE_PRE; }
"no" { yylval.atrib = 0 ; yylval.lexema = "no" ; return NOT; }
"#" { yylval.atrib = 0 ; yylval.lexema = "#" ; return UNARIO_PRE_LISTA; }
"?" { yylval.atrib = 1 ; yylval.lexema = "?" ; return UNARIO_PRE_LISTA; }
"+" { yylval.atrib = 0 ; yylval.lexema = "+" ; return ADITIVOS; }
"-" { yylval.atrib = 1 ; yylval.lexema = "-" ; return ADITIVOS; }
"*" { yylval.atrib = 0 ; yylval.lexema = "*" ; return MULTIPLICATIVOS; }
"/" { yylval.atrib = 1 ; yylval.lexema = "/" ; return MULTIPLICATIVOS; }
"**" { yylval.atrib = 0 ; yylval.lexema = "**" ; return POTENCIAS; }
"%" { yylval.atrib = 2 ; yylval.lexema = "%" ; return MULTIPLICATIVOS; }
"==" { yylval.atrib = 0 ; yylval.lexema = "==" ; return IGUALDAD; }
"!=" { yylval.atrib = 1 ; yylval.lexema = "!=" ; return IGUALDAD; }
"<" { yylval.atrib = 0 ; yylval.lexema = "<" ; return RELACION; }
"<=" { yylval.atrib = 1 ; yylval.lexema = "<=" ; return RELACION; }
">" { yylval.atrib = 2 ; yylval.lexema = ">" ; return RELACION; }
">=" { yylval.atrib = 3 ; yylval.lexema = ">=" ; return RELACION; }
"y" { yylval.atrib = 0 ; yylval.lexema = "y" ; return AND; }
"o" { yylval.atrib = 0 ; yylval.lexema = "o" ; return OR; }
"o_exclusiva" { yylval.atrib = 0 ; yylval.lexema = "o_exclusiva" ; return XOR; }
"@" { yylval.atrib = 0 ; yylval.lexema = "@" ; return ELEM_POSI; }
"entero"    { yylval.atrib = 0 ; yylval.tipo = entero ; return TIPOS; }
"flotante"  { yylval.atrib = 1 ; yylval.tipo = real ; return TIPOS; }
"booleano"  { yylval.atrib = 2 ; yylval.tipo = booleano ; return TIPOS; }
"caracter"  { yylval.atrib = 3 ; yylval.tipo = caracter ; return TIPOS; }
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