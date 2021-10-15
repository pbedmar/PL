%option noyywrap

%{
    #include <stdio.h>
    #include <stdlib.h>
    #include "string.h"
    #include "tabla.h"
    #include <regex.h>
    

    int val;
    static unsigned num_lineas = 1;     /* # de lineas  */
    void imprimir_inf(int cod, char *b);

%}

letra [a-z]|[A-Z]
digitoSC [1-9]
digitoCC [0-9]

cadena \"[^\"]*\"
id ({letra})+({letra}|{digitoCC}|_)*
retroceder "<<"|">>"
op3 "no"|"#"|"?"
op4 "+"|"-"
op5 "*"|"/"|"**"|"%"|"=="|"!="|"<"|"<="|">"|"y"|"o"|"o_exclusiva"
constante_entero {digitoSC}({digitoCC})*|0
constante_flotante ({digitoSC}({digitoCC})*|0).({digitoCC})+
constante_booleano "verdadero"|"falso"
constante_caracter ‘{letra}‘
constante {constante_entero}|{constante_flotante}|{constante_booleano}|{constante_caracter}
tipos "entero"|"real"|"booleano"|"caracter"
%%


"principal" {imprimir_inf(PRINCIPAL, yytext); return PRINCIPAL;}
"{"  {imprimir_inf(LLAVEIZQ, yytext); return LLAVEIZQ;}
"}"  {imprimir_inf(LLAVEDER, yytext); return LLAVEDER;}
","  {imprimir_inf(COMA, yytext); return COMA;}
"lista de" {imprimir_inf(LISTADE, yytext); return LISTADE;}
"procedimiento"  {imprimir_inf(PROCEDIMIENTO, yytext); return PROCEDIMIENTO;}
")"  {imprimir_inf(PARDER, yytext); return PARDER;}
"("  {imprimir_inf(PARIZQ, yytext); return PARIZQ;}
"["  {imprimir_inf(CORCHIZQ, yytext); return CORCHIZQ;}
"]"  {imprimir_inf(CORCHDER, yytext); return CORCHDER;}
"="  {imprimir_inf(IGUAL, yytext); return IGUAL;}
"inicio_var" {imprimir_inf(INICIOVAR, yytext); return INICIOVAR;}
"fin_var" {imprimir_inf(FINVAR, yytext); return FINVAR;}
"si" {imprimir_inf(SI, yytext); return SI;}
"mientras" {imprimir_inf(MIENTRAS, yytext); return MIENTRAS;}
"en otro caso" {imprimir_inf(OTROCASO, yytext); return OTROCASO;}
"para" {imprimir_inf(PARA, yytext); return PARA;}
"hasta" {imprimir_inf(HASTA, yytext); return HASTA;}
"iterando" {imprimir_inf(ITERANDO, yytext); return ITERANDO;}
"hacer" {imprimir_inf(HACER, yytext); return HACER;}
"leer" {imprimir_inf(LEER, yytext); return LEER;}
"imprimir" {imprimir_inf(IMPRIMIR, yytext); return IMPRIMIR;}
{constante} {imprimir_inf(CONSTANTE, yytext); return CONSTANTE;}
{tipos} {imprimir_inf(TIPOS, yytext); return TIPOS;}
{cadena} {imprimir_inf(CADENA, yytext); return CADENA;}
{id} {imprimir_inf(ID, yytext); return ID;}
{retroceder} {imprimir_inf(RETROCEDER, yytext); return RETROCEDER;}
"$" {imprimir_inf(DOLLAR, yytext); return DOLLAR;}
";" {imprimir_inf(PYC, yytext); return PYC;}
"++" {imprimir_inf(OP1, yytext); return OP1;}
"--" {imprimir_inf(OP2, yytext); return OP2;}
{op3} {imprimir_inf(OP3, yytext); return OP3;}
{op4} {imprimir_inf(OP4, yytext); return OP4;}
{op5} {imprimir_inf(OP5, yytext); return OP5;}
"@" {imprimir_inf(OP6, yytext); return OP6;}

" "|"\t";
"\n" ++num_lineas;

. printf("\n(Linea %d) Error lexico: token %s\n", num_lineas, yytext);

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

    void imprimir_inf(int cod, char *b){
        char mensaje[strlen(b)+100];
        char num[5];
        strcat(mensaje,"Codigo: ");
        sprintf(num, "%d", cod);
        strcat(mensaje, num);
        strcat(mensaje, ", Atributo: "); 

        if (cod != 281 && cod != 286 && cod != 287 && cod != 288 && cod != 290 && cod != 291)
            strcat(mensaje, "0");
        else if (cod == 291){
            // Compilo expresiones regulares
            regex_t regex0, regex1, regex2, regex3;
            int c_entero = regcomp(&regex0, "([1-9]([0-9])* | 0)", 0);
            int c_real = regcomp(&regex1, "([1-9]([0-9])* | 0).([0-9])+", 0);
            int c_booleano = regcomp(&regex2, "(“verdadero” | “falso”)", 0);
            int c_caracter = regcomp(&regex3, "(‘[a-z]‘ | ‘[A-Z]‘)", 0);

            if(c_entero || c_real || c_booleano || c_caracter){
                fprintf(stderr, "Error compilando regex\n");
                exit(1);
            }

            // Ejecuto expresiones regulares

            // La función regexec () compara la cadena terminada en nulo especificada por cadena con la expresión regular compilada preg inicializada
            // por una llamada anterior a regcomp () . Si encuentra una coincidencia, regexec () devuelve 0; de lo contrario, devuelve un valor 
            // distinto de cero, lo que indica que no hay coincidencia o un error.

            
            if (!regexec(&regex0, b, 0, NULL, 0))
                strcat(mensaje, "0");
            else if (!regexec(&regex1, b, 0, NULL, 0))
                strcat(mensaje, "1");
            else if (!regexec(&regex2, b, 0, NULL, 0))
                strcat(mensaje, "2");
            else if (!regexec (&regex3, b, 0, NULL, 0))
                strcat(mensaje, "3");

        }
        else{
            if (!strcmp(b, "<<") || !strcmp(b, "no") || !strcmp(b, "+") || !strcmp(b, "*") || !strcmp(b, "entero") || !strcmp(b, "constante_entero"))
                strcat(mensaje, "0");
            else if (!strcmp(b, ">>") || !strcmp(b, "#") || !strcmp(b, "-") || !strcmp(b, "/") || !strcmp(b, "real") || !strcmp(b, "constante_real"))
                strcat(mensaje, "1");
            else if (!strcmp(b, "?") || !strcmp(b, "**") || !strcmp(b, "booleano") || !strcmp(b, "constante_booleano"))
                strcat(mensaje, "2");
            else if (!strcmp(b, "%") || !strcmp(b, "caracter") || !strcmp(b, "constante_caracter"))
                strcat(mensaje, "3");
            else if (!strcmp(b, "=="))
                strcat(mensaje, "4");
            else if (!strcmp(b, "!="))
                strcat(mensaje, "5");
            else if (!strcmp(b, "<"))
                strcat(mensaje, "6");
            else if (!strcmp(b, "<="))
                strcat(mensaje, "7");
            else if (!strcmp(b, ">"))
                strcat(mensaje, "8");
            else if (!strcmp(b, ">="))
                strcat(mensaje, "9");
            else if (!strcmp(b, "y"))
                strcat(mensaje, "10");
            else if (!strcmp(b, "o"))
                strcat(mensaje, "11");
            else if (!strcmp(b, "o_exclusiva"))
                strcat(mensaje, "12");
        }
        
        strcat(mensaje, ", Lexema: ");
        strcat(mensaje, b);
        strcat(mensaje, "\n");
        printf(mensaje);
        *mensaje = NULL;
        *num = NULL;

    }

