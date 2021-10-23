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

el|la   { return(ARTICULO); }

\n  { /** lleva la cuenta de las líneas **/ 
      linea_actual++;
    }

[ \t]+  { /** accion vacia: se ignoran los espacios y tabuladores **/ }
.       { /** token desconocido, se produce un mensaje de error **/ 
            snprintf(buffer, MAXLONBUFFER, "el(los) caracter(es) '%s' no forma(n) ningun token conocido", yytext);
            yyerror(buffer);
        }