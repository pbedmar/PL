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
"<<" { return RETROCEDER; }
">>" { return RETROCEDER; }
"$" { return DOLLAR; }
";" { return PYC; }
"++" { return OP1; }
"--" { return OP2; }
"no" { return OP3; }
"#"  { return OP3; }
"?"  { return OP3; }
"+"  { return OP4; }
"-"  { return OP4; }
"*"  { return OP5; }
"/"  { return OP5; }
"**" { return OP5; }
"%"  { return OP5; }
"==" { return OP5; }
"!=" { return OP5; }
"<"  { return OP5; }
"<=" { return OP5; }
">"  { return OP5; }
">=" { return OP5; }
"y"  { return OP5; }
"o"  { return OP5; }
"o_exclusiva" { return OP5; }
"@" { return OP6; }
"entero"    { return TIPOS; }
"flotante"  { return TIPOS; }
"booleano"  { return TIPOS; }
"caracter"  { return TIPOS; }
{cadena} { return CADENA; }
{constante_entero}    { return CONSTANTE; }
{constante_real}      { return CONSTANTE; }
{constante_booleano}  { return CONSTANTE; }
{constante_caracter}  { return CONSTANTE; }
{id} { return ID; }
\n  {linea_actual++; }
[ \t]+  ;
.       { lexerror(yytext); }

%%