%option noyywrap

%{
    #include <stdio.h>
    #include <stdlib.h>
    #include "string.h"
    #include "tabla.h"
    #include <regex.h>
    
    int val;
    static unsigned num_lineas = 1;     /* # de lineas  */
    void imprimir_inf(int cod, char *b, int atr);

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


"principal" {imprimir_inf(PRINCIPAL, yytext, 0); return PRINCIPAL;}
"{"  {imprimir_inf(LLAVEIZQ, yytext, 0); return LLAVEIZQ;}
"}"  {imprimir_inf(LLAVEDER, yytext, 0); return LLAVEDER;}
","  {imprimir_inf(COMA, yytext, 0); return COMA;}
"lista de" {imprimir_inf(LISTADE, yytext, 0); return LISTADE;}
"procedimiento"  {imprimir_inf(PROCEDIMIENTO, yytext, 0); return PROCEDIMIENTO;}
")"  {imprimir_inf(PARDER, yytext, 0); return PARDER;}
"("  {imprimir_inf(PARIZQ, yytext, 0); return PARIZQ;}
"["  {imprimir_inf(CORCHIZQ, yytext, 0); return CORCHIZQ;}
"]"  {imprimir_inf(CORCHDER, yytext, 0); return CORCHDER;}
"="  {imprimir_inf(IGUAL, yytext, 0); return IGUAL;} 
"inicio_var" {imprimir_inf(INICIOVAR, yytext, 0); return INICIOVAR;}
"fin_var" {imprimir_inf(FINVAR, yytext, 0); return FINVAR;}
"si" {imprimir_inf(SI, yytext, 0); return SI;}
"mientras" {imprimir_inf(MIENTRAS, yytext, 0); return MIENTRAS;}
"en otro caso" {imprimir_inf(OTROCASO, yytext, 0); return OTROCASO;}
"para" {imprimir_inf(PARA, yytext, 0); return PARA;}
"hasta" {imprimir_inf(HASTA, yytext, 0); return HASTA;}
"iterando" {imprimir_inf(ITERANDO, yytext, 0); return ITERANDO;}
"hacer" {imprimir_inf(HACER, yytext, 0); return HACER;}
"leer" {imprimir_inf(LEER, yytext, 0); return LEER;}
"imprimir" {imprimir_inf(IMPRIMIR, yytext, 0); return IMPRIMIR;}
"<<" {imprimir_inf(RETROCEDER, yytext, 0); return RETROCEDER;}
">>" {imprimir_inf(RETROCEDER, yytext, 1); return RETROCEDER;}
"$" {imprimir_inf(DOLLAR, yytext, 0); return DOLLAR;}
";" {imprimir_inf(PYC, yytext, 0); return PYC;}
"++" {imprimir_inf(OP1, yytext, 0); return OP1;}
"--" {imprimir_inf(OP2, yytext, 0); return OP2;}
"no" {imprimir_inf(OP3, yytext, 0); return OP3;}
"#"  {imprimir_inf(OP3, yytext, 1); return OP3;}
"?"  {imprimir_inf(OP3, yytext, 2); return OP3;}
"+"  {imprimir_inf(OP3, yytext, 0); return OP4;}
"-"  {imprimir_inf(OP3, yytext, 1); return OP4;}
"*"  {imprimir_inf(OP5, yytext, 0); return OP5;}
"/"  {imprimir_inf(OP5, yytext, 1); return OP5;}
"**" {imprimir_inf(OP5, yytext, 2); return OP5;}
"%"  {imprimir_inf(OP5, yytext, 3); return OP5;}
"==" {imprimir_inf(OP5, yytext, 4); return OP5;}
"!=" {imprimir_inf(OP5, yytext, 5); return OP5;}
"<"  {imprimir_inf(OP5, yytext, 6); return OP5;}
"<=" {imprimir_inf(OP5, yytext, 7); return OP5;}
">"  {imprimir_inf(OP5, yytext, 8); return OP5;}
">=" {imprimir_inf(OP5, yytext, 9); return OP5;}
"y"  {imprimir_inf(OP5, yytext, 10); return OP5;}
"o"  {imprimir_inf(OP5, yytext, 11); return OP5;}
"o_exclusiva" {imprimir_inf(OP5, yytext, 12); return OP5;}
"@" {imprimir_inf(OP6, yytext, 0); return OP6;}
"entero"  {imprimir_inf(TIPOS, yytext, 0); return TIPOS;}
"flotante"  {imprimir_inf(TIPOS, yytext, 1); return TIPOS;}
"booleano"  {imprimir_inf(TIPOS, yytext, 2); return TIPOS;}
"caracter"  {imprimir_inf(TIPOS, yytext, 3); return TIPOS;}
{cadena} {imprimir_inf(CADENA, yytext, 0); return CADENA;}
{id} {imprimir_inf(ID, yytext, 0); return ID;}
{constante_entero}    {imprimir_inf(CONSTANTE, yytext, 0); return CONSTANTE;}
{constante_real}  {imprimir_inf(CONSTANTE, yytext, 1); return CONSTANTE;}
{constante_booleano}  {imprimir_inf(CONSTANTE, yytext, 2); return CONSTANTE;}
{constante_caracter}  {imprimir_inf(CONSTANTE, yytext, 3); return CONSTANTE;}
" "|"\t" ;
"\n" ++num_lineas;

. printf("\n(Linea %d) Error lexico: token %s\n", num_lineas, yytext, 0);

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
            /*printf("%d\n",val);*/
            val = yylex();
        }

        return 0;
    }

    void imprimir_inf(int cod, char *b, int a){
        char mensaje[strlen(b)+100];
        char num[5];
        char atrib[20];
        strcat(mensaje,"Codigo: ");
        sprintf(num, "%d,", cod);
        strcat(mensaje,num);
        sprintf(atrib," Atributo: %d ",a);
        strcat(mensaje, atrib); 
        strcat(mensaje, "Lexema: ");
        strcat(mensaje, b);
        strcat(mensaje, "\n");
        printf(mensaje);
        *mensaje = NULL;
        *num = NULL;
        *atrib = NULL;

    }
