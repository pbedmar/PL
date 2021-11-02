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
"^"  { return LLAVE_OP_TER; }
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
"<<" { return MOV_LISTA; }
">>" { return MOV_LISTA; }
"$" { return DOLLAR; }
";" { return PYC; }
"++" { return INCRE_PRE; }
"--" { return DECRE_PRE; }
"no" { return NOT; }
"#"  { return UNARIO_PRE_LISTA; }
"?"  { return UNARIO_PRE_LISTA; }
"+"  { return ADITIVOS; }
"-"  { return ADITIVOS; }
"*"  { return MULTIPLICATIVOS; }
"/"  { return MULTIPLICATIVOS; }
"**" { return POTENCIAS; }
"%"  { return MULTIPLICATIVOS; }
"==" { return IGUALDAD; }
"!=" { return IGUALDAD; }
"<"  { return RELACION; }
"<=" { return RELACION; }
">"  { return RELACION; }
">=" { return RELACION; }
"y"  { return AND; }
"o"  { return OR; }
"o_exclusiva" { return XOR; }
"@" { return ELEM_POSI; }
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