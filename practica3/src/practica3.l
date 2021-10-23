%{
/**********************************************************
 **
 ** Fichero: PRACTICA3.L
 ** Función: Pruebas de FLEX para prácticas de PL
 **
 **********************************************************/

/** Buffer usado para almacenamiento temporal de cadenas de texto **/

#define MAXLONBUFFER 200
char buffer[MAXLONBUFFER];

%}

/** La siguiente declaración indica que no se va a escribir la función 'yywrap'
/** evita que se tenga que enlazar con -lfl, o que se tenga que escribir 'yywrap'

%option noyywrap

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
\n  { /** lleva la cuenta de las líneas **/ 
      linea_actual++;
    }
[ \t]+  { /** accion vacia: se ignoran los espacios y tabuladores **/ }
.       { /** token desconocido, se produce un mensaje de error **/ 
            snprintf(buffer, MAXLONBUFFER, "Cadena de caracteres no reconocida: %s, yytext);
            yyerror(buffer);
        }