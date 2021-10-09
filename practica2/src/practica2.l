%option noyywrap

%{
    #include <stdio.h>
    #include <stdlib.h>
    #include "tabla.h"
    

    int val;

%}

cadena \"[^\"]*\"
id ([a-z]|[A-Z])+([a-z]|[A-Z]|[0-9]|_)*
retroceder "<<"|">>"
op3 "no"|"#"|"?"
op4 "+"|"-"
op5 "*"|"/"|"**"|"%"|"=="|"!="|"<"|"<="|">"|"y"|"o"|"o_exclusiva"
constante ([1-9])+([0-9])*|([0-9])+.([0-9])+|"verdadero"|"falso"
tipos "entero"|"real"|"booleano"|"caracter"
%%


"principal" return PRINCIPAL;
"{" return LLAVEIZQ;
"}" return LLAVEDER;
"," return COMA;
"lista de" return  LISTADE;
"procedimiento" return PROCEDIMIENTO;
")" return PARDER;
"(" return PARIZQ;
"[" return CORCHIZQ;
"]" return CORCHDER;
"=" return IGUAL;
"inicio_var" return INICIOVAR;
"fin_var" return FINVAR;
"si" return SI;
"mientras" return MIENTRAS;
"en otro caso" return OTROCASO;
"para" return PARA;
"hasta" return HASTA;
"iterando" return ITERANDO;
"hacer" return HACER;
"leer" return LEER;
"imprimir" return IMPRIMIR;
{constante} return CONSTANTE;
{tipos} return TIPOS;
{cadena} return CADENA;
{id} return ID;
{retroceder} return RETROCEDER;
"$" return DOLLAR;
";" return PYC;
"++" return OP1;
"--" return OP2;
{op3} return OP3;
{op4} return OP4;
{op5} return OP5;
"@" return OP6;

" "|"\t";

. printf("\n(Linea %d) Error lexico: token %s\n", yylineno, yytext);

%%


    int main (int argc, char *argv[]){
        if(argc == 2){
            yyin = fopen(argv[1],"rt");
            if(yyin == NULL){
                printf("El fichero %s no se puede abrir\n",argv[1]);
                exit(-1);
            }
        } else yyin = stdin;


        val = yylex();
        while (val != 0){
            printf("%d\n",val);
            val = yylex();
        }

        return 0;
    }

