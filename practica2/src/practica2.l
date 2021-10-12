%option noyywrap

%{
    #include <stdio.h>
    #include <stdlib.h>
    #include "string.h"
    #include "tabla.h"
    #include <regex.h>
    

    int val;
    static unsigned num_lineas = 1;     /* # de lineas  */
    void imprimir_inf(int cod, char *b, char *atr);

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
constante_flotante ({digitoSC}(digitoCC)*|0).({digitoCC})+
constante_booleano "verdadero"|"falso"
constante_caracter ‘{letra}‘
constante {constante_entero}|{constante_flotante}|{constante_booleano}|{constante_caracter}
tipos "entero"|"real"|"booleano"|"caracter"
%%


"principal" {imprimir_inf(PRINCIPAL, yytext, yytext); return PRINCIPAL;}
"{"  {imprimir_inf(LLAVEIZQ, yytext, yytext); return LLAVEIZQ;}
"}"  {imprimir_inf(LLAVEDER, yytext, yytext); return LLAVEDER;}
","  {imprimir_inf(COMA, yytext, yytext); return COMA;}
"lista de" {imprimir_inf(LISTADE, yytext, yytext); return LISTADE;}
"procedimiento"  {imprimir_inf(PROCEDIMIENTO, yytext, yytext); return PROCEDIMIENTO;}
")"  {imprimir_inf(PARDER, yytext, yytext); return PARDER;}
"("  {imprimir_inf(PARIZQ, yytext, yytext); return PARIZQ;}
"["  {imprimir_inf(CORCHIZQ, yytext, yytext); return CORCHIZQ;}
"]"  {imprimir_inf(CORCHDER, yytext, yytext); return CORCHDER;}
"="  {imprimir_inf(IGUAL, yytext, yytext); return IGUAL;}
"inicio_var" {imprimir_inf(INICIOVAR, yytext, yytext); return INICIOVAR;}
"fin_var" {imprimir_inf(FINVAR, yytext, yytext); return FINVAR;}
"si" {imprimir_inf(SI, yytext, yytext); return SI;}
"mientras" {imprimir_inf(MIENTRAS, yytext, yytext); return MIENTRAS;}
"en otro caso" {imprimir_inf(OTROCASO, yytext, yytext); return OTROCASO;}
"para" {imprimir_inf(PARA, yytext, yytext); return PARA;}
"hasta" {imprimir_inf(HASTA, yytext, yytext); return HASTA;}
"iterando" {imprimir_inf(ITERANDO, yytext, yytext); return ITERANDO;}
"hacer" {imprimir_inf(HACER, yytext, yytext); return HACER;}
"leer" {imprimir_inf(LEER, yytext, yytext); return LEER;}
"imprimir" {imprimir_inf(IMPRIMIR, yytext, yytext); return IMPRIMIR;}
{constante} {imprimir_inf(CONSTANTE, yytext, yytext); return CONSTANTE;}
{tipos} {imprimir_inf(TIPOS, yytext, yytext); return TIPOS;}
{cadena} {imprimir_inf(CADENA, yytext, yytext); return CADENA;}
{id} {imprimir_inf(ID, yytext, yytext); return ID;}
{retroceder} {imprimir_inf(RETROCEDER, yytext, yytext); return RETROCEDER;}
"$" {imprimir_inf(DOLLAR, yytext, yytext); return DOLLAR;}
";" {imprimir_inf(PYC, yytext, yytext); return PYC;}
"++" {imprimir_inf(OP1, yytext, yytext); return OP1;}
"--" {imprimir_inf(OP2, yytext, yytext); return OP2;}
{op3} {imprimir_inf(OP3, yytext, yytext); return OP3;}
{op4} {imprimir_inf(OP4, yytext, yytext); return OP4;}
{op5} {imprimir_inf(OP5, yytext, yytext); return OP5;}
"@" {imprimir_inf(OP6, yytext, yytext); return OP6;}

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

    void imprimir_inf(int cod, char *b, char *atr){
        char mensaje[strlen(b)+100];
        char num[5];
        strcat(mensaje,"Codigo: ");
        sprintf(num, "%d", cod);
        strcat(mensaje, num);
        strcat(mensaje, ", Atributo: "); 

        // Compilo expresiones regulares
        regex_t regex0, regex1, regex2, regex3;
        int c_entero = regcomp(&regex0, "([1-9]([0-9])* | 0)", 0);
        int c_real = regcomp(&regex1, "([1-9]([0-9])* | 0).([0-9])", 1);
        int c_booleano = regcomp(&regex2, "(“verdadero” | “falso”)", 2);
        int c_caracter = regcomp(&regex3, "(‘[a-z]‘ | ‘[A-Z]‘)", 3);

        if(c_entero || c_real || c_booleano || c_caracter){
            fprintf(stderr, "Error compilando regex\n");
            exit(1);
        }

        // Ejecuto expresiones regulares

        // La función regexec () compara la cadena terminada en nulo especificada por cadena con la expresión regular compilada preg inicializada
        // por una llamada anterior a regcomp () . Si encuentra una coincidencia, regexec () devuelve 0; de lo contrario, devuelve un valor 
        // distinto de cero, lo que indica que no hay coincidencia o un error.

        if (cod != 281 && cod != 286 && cod != 287 && cod != 288 && cod != 290 && cod != 291)
            strcat(mensaje, "0");
        else if (cod == 291){
            if (regexec (&regex0, b, 0, NULL, 0))
                strcat(mensaje, "0");
            else if (regexec (&regex1, b, 0, NULL, 1))
                strcat(mensaje, "1");
            else if (regexec (&regex2, b, 0, NULL, 2))
                strcat(mensaje, "2");
            else if (regexec (&regex3, b, 0, NULL, 3))
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

