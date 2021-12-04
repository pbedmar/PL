/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "src/practica4.y"

int yylex();
#line 5 "src/practica4.y"

/****************************************************************
 **
 ** Fichero: PRACTICA4.Y
 ** Función: Pruebas de YACC para practicas de PL
 **
 ****************************************************************/

#define _POSIX_C_SOURCE 200809L

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/** La siguiente declaracion permite que 'yyerror' se puede invocar desde el
 ** fuente de lex (practica3.l)
 **/

void lexerror(const char *msg);
void yyerror(const char *msg);

/** La siguiente variable se usará para conocer el numero de la línea
 ** que se esta leyendo en cada momento. Tambies es posible usar la variable
 ** 'yylineno' que tambien nos muestra la linea actual. Para ello es necesario
 ** invocar a flex con la opcion '-l' (compatibilidad con lex).
 **/

int linea_actual = 1;


typedef enum {
  marca,
  procedimiento,
  variable,
  parametro_formal
} tipoEntrada ;

typedef enum {
  entero,
  real,
  caracter,
  booleano,
  lista_entero,
  lista_real,
  lista_caracter,
  lista_booleano,
  desconocido,
  no_asignado
} dtipo ;

dtipo obtenerTipoLista(dtipo tipo) {
  switch(tipo) {
    case entero:
      return lista_entero;
    break;
    case real:
      return lista_real;
    break;
    case caracter:
      return lista_caracter;
    break;
    case booleano:
      return lista_booleano;
    break;
  }
}

typedef struct {
  tipoEntrada   entrada ;
  char          *nombre ;
  dtipo         tipoDato ;
  //numero de parámetros que hay que pasar al procedimiento
  unsigned int  parametrosMin ;
  //número de parámetros obligatorios más por defecto
  unsigned int  parametrosMax ;
} entradaTS ;


#define MAX_TS 1000

unsigned int TOPE=0 ;
unsigned int Subprog ;
dtipo tipoTmp ;
int posParam;
int posProced;
dtipo listaParam[50];

entradaTS TS[MAX_TS] ;

typedef struct {
  int   atrib ;
  char  *lexema ;
  dtipo tipo ;
} atributos ;

#define YYSTYPE atributos

void mostrarErrorTipoInco(int pos, dtipo tipo);

void mostrarErrorOrden();

void mostrarErrorMinParam(char* nomProced);

void mostrarErrorMaxParam(char* nomProced);

void mostrarErrorProcedDesco(char* nomProced);

void mostrarErrorTipoAsig(dtipo tipo);

void errorNoDeclarado(char* lexema);

void errorYaDeclarado(char* lexema);

void errorTipoOperador(char* lexema);

void errorTipoOperador2(char* lexema, char* lexema2);

unsigned int procedMasProximo() {
  unsigned int pos = TOPE - 1;

  while(TS[pos].entrada != procedimiento) {
    pos -= 1;
  }

  return pos;
}

void TS_InsertaMARCA() {
  entradaTS aux = {marca, "", desconocido, 0, 0};
  unsigned int posEntradaProced;
  int numParam;

  TS[TOPE] = aux;
  TOPE += 1;

  if(Subprog == 1) {
    posEntradaProced = procedMasProximo();
    numParam = TS[posEntradaProced].parametrosMax;
    
    for(int i = 0; i < numParam; ++i) { 
      int pos = posEntradaProced + i + 1;    
      TS[TOPE] = TS[pos];
      TS[TOPE].entrada = variable;   
      TOPE += 1;
    } 
  }
}

void TS_InsertaPROCED(char* lexema) {
  entradaTS aux = {procedimiento, lexema, desconocido, 0, 0};
  TS[TOPE] = aux;
  TOPE = TOPE + 1;
}

void TS_InsertaVAR(char* lexema, dtipo tipo) {
  entradaTS aux = {variable, lexema, tipo, 0, 0};
  TS[TOPE] = aux;
  TOPE = TOPE + 1;
}

void TS_InsertaPARAM(char* lexema, dtipo tipo) {
  entradaTS aux = {parametro_formal, lexema, tipo, 0, 0};
  TS[TOPE] = aux;
  TOPE = TOPE + 1;
  unsigned int pos = procedMasProximo();
  TS[pos].parametrosMin += 1;
  TS[pos].parametrosMax += 1;
}

void TS_InsertaPARAM_POR_DEF(char* lexema, dtipo tipo) {
  entradaTS aux = {parametro_formal, lexema, tipo, 0, 0};
  TS[TOPE] = aux;
  TOPE = TOPE + 1;
  unsigned int pos = procedMasProximo();
  TS[pos].parametrosMax += 1;
}

void TS_VaciarENTRADAS() {
  TOPE = TOPE - 1;
  while(TS[TOPE].entrada != marca) {
    TOPE = TOPE - 1;
  }
}

int buscarProced(char* lexemaProced) {
  int pos = TOPE-1;
  while(pos >= 0 && strcmp(TS[pos].nombre, lexemaProced) != 0) {
    pos -= 1;
  }
  return pos;
}

void comprobarParam() {
  int i = 0;
  while(i < posParam) {
    dtipo tipo = TS[posProced + i + 1].tipoDato;

    if(tipo != listaParam[i]) {
      if(i < TS[posProced].parametrosMin) {
        mostrarErrorTipoInco(i, tipo);
        i += 1;
      }
      else {
        i += 1;
        if(i == TS[posProced].parametrosMax) {
          mostrarErrorOrden();
          i = posParam;
        }
      }
    }
    else {
      i += 1;
    }
  }
}

dtipo buscarTipoVariable(char* lexema){
  int pos = TOPE-1;
  while(pos > 0 && strcmp(TS[pos].nombre, lexema) != 0) {
    pos -= 1;
  }

  return TS[pos].tipoDato;
}

//comprueba si un lexama ha sido declarado
int declarado(char *lexema){
  int i = 0;
  
  while(i < TOPE){
    if (strcmp(TS[i].nombre,lexema) == 0){
      //printf("Se ha encontrado el lexema %s\n",lexema);
      return 1;
    }
      
    i+=1;
  }
  //printf("No se ha encontrado el lexema %s\n",lexema);
  return 0;
  
}

int enAmbito(char *lexema){
  int i = TOPE -1;

  while((strcmp(TS[i].nombre,"") != 0) && i > 0){
    if((strcmp(TS[i].nombre,lexema) == 0))
      return 1;
    i -= 1;

  }

  
  return 0;
}

bool esListaNumerica(dtipo tipo){
  return tipo == lista_entero || tipo == lista_real;
}

bool esLista(dtipo tipo){
  return esListaNumerica(tipo) || tipo == lista_caracter || tipo == lista_booleano;
}

bool esNumerico(dtipo tipo){
  return tipo == entero || tipo == real;
}

dtipo listaATipo(dtipo tipo) {
  if (tipo == lista_entero) {
    return entero;
  } else if (tipo == lista_real) {
    return real;
  } else if (tipo == lista_booleano) {
    return booleano;
  } else if (tipo == lista_caracter) {
    return caracter;
  }
}

int tipoANumero(dtipo tipo) {
  switch (tipo) {
    case entero:
      return 0;
    break;
    case real:
      return 1;
    break;
    case lista_entero:
      return 2;
    break;
    case lista_real:
      return 3;
    break;
    default:
      return 99;
  }
}



#line 376 "src/y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_SRC_Y_TAB_H_INCLUDED
# define YY_YY_SRC_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    PRINCIPAL = 258,
    LLAVEIZQ = 259,
    LLAVEDER = 260,
    COMA = 261,
    LISTADE = 262,
    PROCEDIMIENTO = 263,
    PARDER = 264,
    PARIZQ = 265,
    CORCHIZQ = 266,
    CORCHDER = 267,
    IGUAL = 268,
    INICIOVAR = 269,
    FINVAR = 270,
    SI = 271,
    MIENTRAS = 272,
    OTROCASO = 273,
    PARA = 274,
    HASTA = 275,
    ITERANDO = 276,
    HACER = 277,
    LEER = 278,
    IMPRIMIR = 279,
    CADENA = 280,
    ID = 281,
    PYC = 282,
    TIPOS = 283,
    CONSTANTE = 284,
    ELEM_POSI_BINA = 285,
    OR = 286,
    AND = 287,
    XOR = 288,
    IGUALDAD = 289,
    RELACION = 290,
    ADITIVOS = 291,
    MULTIPLICATIVOS = 292,
    POTENCIAS = 293,
    UNARIOS = 294,
    NOT = 295,
    DECRE_PRE = 296,
    INCRE_PRE = 297,
    UNARIO_PRE_LISTA = 298,
    ELEM_POSI = 299,
    MOV_LISTA = 300,
    DOLLAR = 301
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SRC_Y_TAB_H_INCLUDED  */



#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   473

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  47
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  29
/* YYNRULES -- Number of rules.  */
#define YYNRULES  81
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  167

#define YYUNDEFTOK  2
#define YYMAXUTOK   301


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   395,   395,   397,   399,   401,   406,   411,   412,   414,
     415,   416,   417,   419,   421,   422,   424,   425,   427,   428,
     430,   435,   440,   445,   451,   452,   454,   456,   458,   459,
     460,   461,   463,   464,   466,   467,   468,   469,   470,   471,
     472,   473,   474,   475,   477,   488,   489,   492,   493,   495,
     496,   498,   499,   501,   508,   516,   525,   537,   548,   549,
     556,   563,   570,   581,   588,   615,   622,   630,   663,   676,
     691,   702,   709,   716,   723,   730,   736,   737,   738,   740,
     742,   743
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "PRINCIPAL", "LLAVEIZQ", "LLAVEDER",
  "COMA", "LISTADE", "PROCEDIMIENTO", "PARDER", "PARIZQ", "CORCHIZQ",
  "CORCHDER", "IGUAL", "INICIOVAR", "FINVAR", "SI", "MIENTRAS", "OTROCASO",
  "PARA", "HASTA", "ITERANDO", "HACER", "LEER", "IMPRIMIR", "CADENA", "ID",
  "PYC", "TIPOS", "CONSTANTE", "ELEM_POSI_BINA", "OR", "AND", "XOR",
  "IGUALDAD", "RELACION", "ADITIVOS", "MULTIPLICATIVOS", "POTENCIAS",
  "UNARIOS", "NOT", "DECRE_PRE", "INCRE_PRE", "UNARIO_PRE_LISTA",
  "ELEM_POSI", "MOV_LISTA", "DOLLAR", "$accept", "programa",
  "cabecera_programa", "inicio_bloque", "bloque", "lista_parametros",
  "lista_para_por_defecto", "parametro", "declar_de_variables_locales",
  "variables_locales", "cuerpo_declar_variables", "declar_variables",
  "declar_procedimientos", "declar_proced", "inicio_cabe_proced",
  "cabecera_proced", "sentencias", "sentencia", "sentencia_asignacion",
  "sentencia_if", "lista_identificadores", "mensajes", "mensaje",
  "inicio_llamada", "llamada_proced", "lista_expresiones", "expresion",
  "agregado_lista", "tipos", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301
};
# endif

#define YYPACT_NINF (-138)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-32)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       5,    11,    30,    89,    85,  -138,  -138,    90,  -138,  -138,
      77,    91,  -138,    83,  -138,    75,  -138,    86,   109,    93,
     236,   236,   113,   128,   119,   120,     6,    50,  -138,   236,
     236,   236,   236,   236,   236,  -138,    91,  -138,   129,    89,
     125,  -138,  -138,  -138,   214,  -138,   345,  -138,  -138,  -138,
    -138,   137,     9,  -138,  -138,  -138,    20,    22,   360,   236,
     236,   142,   127,  -138,    53,  -138,    73,  -138,   360,  -138,
     236,   145,   145,   145,     1,   114,   315,  -138,   159,    16,
    -138,  -138,  -138,   135,   100,   236,   236,   236,   236,   236,
     236,   236,   236,   236,   236,   236,   146,   236,   148,  -138,
    -138,   236,  -138,   249,   264,   236,   151,  -138,     6,  -138,
     331,  -138,  -138,  -138,   112,  -138,   153,  -138,   154,   387,
     399,   410,   420,   429,   115,    45,   145,   145,   374,   360,
    -138,   360,   167,   360,   193,   193,   282,  -138,  -138,  -138,
      -2,  -138,  -138,  -138,   236,   236,   166,  -138,   236,   134,
     177,   114,   360,   193,   299,    -2,  -138,    -7,  -138,   193,
     178,  -138,  -138,  -138,     8,  -138,  -138
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     1,     4,    15,     2,     3,
       0,     0,    19,     0,    80,     0,    17,     0,    78,     0,
       0,     0,     0,     0,     0,     0,     0,    75,    77,     0,
       0,     0,     0,     0,     0,    34,     0,    25,     0,     0,
       0,    33,    35,    36,     0,    41,     0,    76,    81,    14,
      16,    20,     0,    27,    78,    75,     0,     0,    57,     0,
       0,     0,     0,    48,     0,    52,     0,    50,    51,    53,
       0,    63,    61,    59,    60,    62,     0,    24,     0,     0,
      26,     6,    32,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    18,
      58,     0,    79,     0,     0,     0,     0,    39,     0,    40,
       0,    43,     5,    30,     0,     8,     0,    55,     0,    71,
      72,    73,    69,    70,    64,    67,    68,    65,     0,    66,
      42,    21,    22,    56,     0,     0,     0,    47,    49,    44,
       0,    29,    13,    54,     0,     0,    45,    37,     0,     0,
       7,    74,    23,     0,     0,     0,    28,     0,    46,     0,
       0,    10,    12,    38,     0,     9,    11
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -138,  -138,  -138,  -138,    -1,  -138,  -138,  -122,  -138,  -138,
     157,  -138,  -138,   156,  -138,  -138,   160,   -37,   169,  -138,
    -138,  -138,    98,  -138,  -138,   163,   -20,  -137,    81
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     7,    35,   114,   149,   115,    11,    15,
      16,    52,    36,    37,    38,    39,    40,    41,    42,    43,
      64,    66,    67,    44,    45,    57,    46,    47,   116
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      56,    58,     8,    82,    21,    13,    68,    54,     1,    71,
      72,    73,    74,    75,    76,    98,    20,    21,   150,    21,
     162,     4,   161,    13,    58,   113,    14,   166,   101,   100,
       5,    65,    55,   160,   102,    28,    99,   165,    80,   103,
     104,    82,    29,    94,    14,    95,    30,    31,    32,    33,
     110,    85,    86,    87,    88,    89,    90,    91,    92,   106,
      69,    93,    94,    70,    95,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,    12,   131,    12,   108,
     107,   133,    13,    92,    13,   136,    93,    94,    68,    95,
      49,    17,    18,     6,     9,     6,    17,   146,   147,    19,
     109,    20,    21,    14,    10,    14,   101,    22,    23,   118,
      24,    48,    51,   -31,    25,    26,   158,    27,   140,    53,
      28,   141,   163,    59,   151,   152,    54,    29,   154,     6,
      81,    30,    31,    32,    33,    20,    21,    34,    60,    79,
     155,    22,    23,   156,    24,    61,    63,   105,    25,    26,
      97,    27,    91,    92,    28,    70,    93,    94,    95,    95,
      54,    29,   117,     6,   112,    30,    31,    32,    33,    20,
      21,    34,    50,   130,   132,    22,    23,   137,    24,   142,
     145,   143,    25,    26,   153,    27,    93,    94,    28,    95,
     157,   164,    77,    62,    54,    29,    78,     6,     0,    30,
      31,    32,    33,    20,    21,    34,   138,    84,     0,    22,
      23,     0,    24,     0,     0,    54,    25,    26,     0,    27,
       0,     0,    28,    83,    20,    21,     0,     0,     0,    29,
       0,     0,     0,    30,    31,    32,    33,    54,     0,    34,
      55,     0,     0,    28,     0,     0,    20,    21,     0,     0,
      29,     0,     0,     0,    30,    31,    32,    33,   134,     0,
       0,     0,    55,     0,     0,    28,     0,     0,     0,     0,
       0,     0,    29,   135,     0,     0,    30,    31,    32,    33,
      85,    86,    87,    88,    89,    90,    91,    92,     0,     0,
      93,    94,     0,    95,     0,    85,    86,    87,    88,    89,
      90,    91,    92,   148,     0,    93,    94,     0,    95,     0,
       0,     0,     0,    85,    86,    87,    88,    89,    90,    91,
      92,   159,     0,    93,    94,     0,    95,     0,     0,     0,
      85,    86,    87,    88,    89,    90,    91,    92,     0,     0,
      93,    94,   111,    95,     0,     0,    85,    86,    87,    88,
      89,    90,    91,    92,     0,     0,    93,    94,   139,    95,
       0,     0,    85,    86,    87,    88,    89,    90,    91,    92,
       0,     0,    93,    94,     0,    95,    85,    86,    87,    88,
      89,    90,    91,    92,     0,     0,    93,    94,     0,    95,
      96,    85,    86,    87,    88,    89,    90,    91,    92,     0,
       0,    93,    94,     0,    95,    85,    86,    87,    88,    89,
      90,    91,    92,     0,     0,    93,    94,     0,   144,    86,
      87,    88,    89,    90,    91,    92,     0,     0,    93,    94,
       0,    95,    87,    88,    89,    90,    91,    92,     0,     0,
      93,    94,     0,    95,    88,    89,    90,    91,    92,     0,
       0,    93,    94,     0,    95,    89,    90,    91,    92,     0,
       0,    93,    94,     0,    95,    90,    91,    92,     0,     0,
      93,    94,     0,    95
};

static const yytype_int16 yycheck[] =
{
      20,    21,     3,    40,    11,     7,    26,     1,     3,    29,
      30,    31,    32,    33,    34,     6,    10,    11,   140,    11,
     157,    10,    29,     7,    44,     9,    28,   164,     6,     9,
       0,    25,    26,   155,    12,    29,    27,    29,    39,    59,
      60,    78,    36,    42,    28,    44,    40,    41,    42,    43,
      70,    31,    32,    33,    34,    35,    36,    37,    38,     6,
      10,    41,    42,    13,    44,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,     1,    97,     1,     6,
      27,   101,     7,    38,     7,   105,    41,    42,   108,    44,
      15,    10,     1,     4,     9,     4,    15,   134,   135,     8,
      27,    10,    11,    28,    14,    28,     6,    16,    17,     9,
      19,    28,    26,     4,    23,    24,   153,    26,     6,    26,
      29,     9,   159,    10,   144,   145,     1,    36,   148,     4,
       5,    40,    41,    42,    43,    10,    11,    46,    10,    10,
       6,    16,    17,     9,    19,    26,    26,    20,    23,    24,
      13,    26,    37,    38,    29,    13,    41,    42,    44,    44,
       1,    36,    27,     4,     5,    40,    41,    42,    43,    10,
      11,    46,    15,    27,    26,    16,    17,    26,    19,    26,
      13,    27,    23,    24,    18,    26,    41,    42,    29,    44,
      13,    13,    36,    24,     1,    36,    36,     4,    -1,    40,
      41,    42,    43,    10,    11,    46,   108,    44,    -1,    16,
      17,    -1,    19,    -1,    -1,     1,    23,    24,    -1,    26,
      -1,    -1,    29,     9,    10,    11,    -1,    -1,    -1,    36,
      -1,    -1,    -1,    40,    41,    42,    43,     1,    -1,    46,
      26,    -1,    -1,    29,    -1,    -1,    10,    11,    -1,    -1,
      36,    -1,    -1,    -1,    40,    41,    42,    43,     9,    -1,
      -1,    -1,    26,    -1,    -1,    29,    -1,    -1,    -1,    -1,
      -1,    -1,    36,     9,    -1,    -1,    40,    41,    42,    43,
      31,    32,    33,    34,    35,    36,    37,    38,    -1,    -1,
      41,    42,    -1,    44,    -1,    31,    32,    33,    34,    35,
      36,    37,    38,    21,    -1,    41,    42,    -1,    44,    -1,
      -1,    -1,    -1,    31,    32,    33,    34,    35,    36,    37,
      38,    22,    -1,    41,    42,    -1,    44,    -1,    -1,    -1,
      31,    32,    33,    34,    35,    36,    37,    38,    -1,    -1,
      41,    42,    27,    44,    -1,    -1,    31,    32,    33,    34,
      35,    36,    37,    38,    -1,    -1,    41,    42,    27,    44,
      -1,    -1,    31,    32,    33,    34,    35,    36,    37,    38,
      -1,    -1,    41,    42,    -1,    44,    31,    32,    33,    34,
      35,    36,    37,    38,    -1,    -1,    41,    42,    -1,    44,
      45,    31,    32,    33,    34,    35,    36,    37,    38,    -1,
      -1,    41,    42,    -1,    44,    31,    32,    33,    34,    35,
      36,    37,    38,    -1,    -1,    41,    42,    -1,    44,    32,
      33,    34,    35,    36,    37,    38,    -1,    -1,    41,    42,
      -1,    44,    33,    34,    35,    36,    37,    38,    -1,    -1,
      41,    42,    -1,    44,    34,    35,    36,    37,    38,    -1,
      -1,    41,    42,    -1,    44,    35,    36,    37,    38,    -1,
      -1,    41,    42,    -1,    44,    36,    37,    38,    -1,    -1,
      41,    42,    -1,    44
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,    48,    49,    10,     0,     4,    50,    51,     9,
      14,    55,     1,     7,    28,    56,    57,    75,     1,     8,
      10,    11,    16,    17,    19,    23,    24,    26,    29,    36,
      40,    41,    42,    43,    46,    51,    59,    60,    61,    62,
      63,    64,    65,    66,    70,    71,    73,    74,    28,    15,
      57,    26,    58,    26,     1,    26,    73,    72,    73,    10,
      10,    26,    65,    26,    67,    25,    68,    69,    73,    10,
      13,    73,    73,    73,    73,    73,    73,    60,    63,    10,
      51,     5,    64,     9,    72,    31,    32,    33,    34,    35,
      36,    37,    38,    41,    42,    44,    45,    13,     6,    27,
       9,     6,    12,    73,    73,    20,     6,    27,     6,    27,
      73,    27,     5,     9,    52,    54,    75,    27,     9,    73,
      73,    73,    73,    73,    73,    73,    73,    73,    73,    73,
      27,    73,    26,    73,     9,     9,    73,    26,    69,    27,
       6,     9,    26,    27,    44,    13,    64,    64,    21,    53,
      54,    73,    73,    18,    73,     6,     9,    13,    64,    22,
      54,    29,    74,    64,    13,    29,    74
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    47,    48,    49,    50,    51,    51,    52,    52,    53,
      53,    53,    53,    54,    55,    55,    56,    56,    57,    57,
      58,    58,    58,    58,    59,    59,    60,    61,    62,    62,
      62,    62,    63,    63,    64,    64,    64,    64,    64,    64,
      64,    64,    64,    64,    65,    66,    66,    67,    67,    68,
      68,    69,    69,    70,    71,    71,    72,    72,    73,    73,
      73,    73,    73,    73,    73,    73,    73,    73,    73,    73,
      73,    73,    73,    73,    73,    73,    73,    73,    73,    74,
      75,    75
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     3,     1,     5,     4,     3,     1,     5,
       3,     5,     3,     2,     3,     0,     2,     1,     3,     1,
       1,     3,     3,     5,     2,     1,     2,     2,     6,     4,
       3,     1,     2,     1,     1,     1,     1,     5,     8,     3,
       3,     1,     3,     3,     4,     5,     7,     3,     1,     3,
       1,     1,     1,     2,     4,     3,     3,     1,     3,     2,
       2,     2,     2,     2,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     5,     1,     1,     1,     1,     3,
       1,     2
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 4:
#line 399 "src/practica4.y"
                         { TS_InsertaMARCA(); }
#line 1825 "src/y.tab.c"
    break;

  case 5:
#line 405 "src/practica4.y"
                   { TS_VaciarENTRADAS(); }
#line 1831 "src/y.tab.c"
    break;

  case 6:
#line 409 "src/practica4.y"
                   { TS_VaciarENTRADAS(); }
#line 1837 "src/y.tab.c"
    break;

  case 7:
#line 411 "src/practica4.y"
                                                      { TS_InsertaPARAM(yyvsp[0].lexema, yyvsp[0].tipo); }
#line 1843 "src/y.tab.c"
    break;

  case 8:
#line 412 "src/practica4.y"
                                { TS_InsertaPARAM(yyvsp[0].lexema, yyvsp[0].tipo); }
#line 1849 "src/y.tab.c"
    break;

  case 9:
#line 414 "src/practica4.y"
                                                                                { TS_InsertaPARAM_POR_DEF(yyvsp[-2].lexema, yyvsp[-2].tipo); }
#line 1855 "src/y.tab.c"
    break;

  case 10:
#line 415 "src/practica4.y"
                                                    { TS_InsertaPARAM_POR_DEF(yyvsp[-2].lexema, yyvsp[-2].tipo); }
#line 1861 "src/y.tab.c"
    break;

  case 11:
#line 416 "src/practica4.y"
                                                                                     { TS_InsertaPARAM_POR_DEF(yyvsp[-2].lexema, yyvsp[-2].tipo); }
#line 1867 "src/y.tab.c"
    break;

  case 12:
#line 417 "src/practica4.y"
                                                         { TS_InsertaPARAM_POR_DEF(yyvsp[-2].lexema, yyvsp[-2].tipo); }
#line 1873 "src/y.tab.c"
    break;

  case 13:
#line 419 "src/practica4.y"
                       { yyval.tipo = tipoTmp; yyval.lexema = yyvsp[0].lexema; }
#line 1879 "src/y.tab.c"
    break;

  case 20:
#line 430 "src/practica4.y"
                         { 
                          if(enAmbito(yyvsp[0].lexema) == 1)
                            errorYaDeclarado(yyvsp[0].lexema);
                          else
                            TS_InsertaVAR(yyvsp[0].lexema, tipoTmp); }
#line 1889 "src/y.tab.c"
    break;

  case 21:
#line 435 "src/practica4.y"
                                         { 
                      if(enAmbito(yyvsp[-2].lexema) == 1)
                            errorYaDeclarado(yyvsp[-2].lexema);
                      else
                        TS_InsertaVAR(yyvsp[-2].lexema, tipoTmp); }
#line 1899 "src/y.tab.c"
    break;

  case 22:
#line 440 "src/practica4.y"
                                               { 
                      if(enAmbito(yyvsp[0].lexema) == 1)
                            errorYaDeclarado(yyvsp[0].lexema);
                      else
                        TS_InsertaVAR(yyvsp[0].lexema, tipoTmp); }
#line 1909 "src/y.tab.c"
    break;

  case 23:
#line 445 "src/practica4.y"
                                                               { 
                      if(enAmbito(yyvsp[-2].lexema) == 1)
                            errorYaDeclarado(yyvsp[-2].lexema);
                      else
                        TS_InsertaVAR(yyvsp[-2].lexema, tipoTmp); }
#line 1919 "src/y.tab.c"
    break;

  case 26:
#line 454 "src/practica4.y"
                                       { Subprog = 0; }
#line 1925 "src/y.tab.c"
    break;

  case 27:
#line 456 "src/practica4.y"
                                      { TS_InsertaPROCED(yyvsp[0].lexema); }
#line 1931 "src/y.tab.c"
    break;

  case 28:
#line 458 "src/practica4.y"
                                                                                                { Subprog = 1; }
#line 1937 "src/y.tab.c"
    break;

  case 29:
#line 459 "src/practica4.y"
                                                                    { Subprog = 1; }
#line 1943 "src/y.tab.c"
    break;

  case 30:
#line 460 "src/practica4.y"
                                                   { Subprog = 1; }
#line 1949 "src/y.tab.c"
    break;

  case 42:
#line 474 "src/practica4.y"
                                      {if (esLista(yyvsp[-2].tipo)) { yyval.tipo = yyvsp[-2].tipo; } else {errorTipoOperador(yyvsp[-1].lexema); }}
#line 1955 "src/y.tab.c"
    break;

  case 43:
#line 475 "src/practica4.y"
                                   {if (esLista(yyvsp[-1].tipo)) { yyval.tipo = yyvsp[-1].tipo; } else {errorTipoOperador(yyvsp[-2].lexema); }}
#line 1961 "src/y.tab.c"
    break;

  case 44:
#line 477 "src/practica4.y"
                                               {
                                                if (declarado(yyvsp[-3].lexema) == 0) {
                                                  errorNoDeclarado(yyvsp[-3].lexema);
                                                }
                                                else {
                                                  if (buscarTipoVariable(yyvsp[-3].lexema) != yyvsp[-1].tipo){
                                                    mostrarErrorTipoAsig(yyvsp[-1].tipo);
                                                  }
                                                }
                                                }
#line 1976 "src/y.tab.c"
    break;

  case 53:
#line 501 "src/practica4.y"
                           { yyval.lexema = yyvsp[-1].lexema ;
                             posProced = buscarProced(yyvsp[-1].lexema) ; 
                             if(posProced == -1){ 
                               mostrarErrorProcedDesco(yyvsp[-1].lexema); 
                             }
                             posParam = 0; }
#line 1987 "src/y.tab.c"
    break;

  case 54:
#line 508 "src/practica4.y"
                                                              { if(posProced != -1) {
                                                                  if(posParam < TS[posProced].parametrosMin) {
                                                                    mostrarErrorMinParam(yyvsp[-3].lexema);
                                                                  }
                                                                  else {
                                                                    comprobarParam();
                                                                  }
                                                                } }
#line 2000 "src/y.tab.c"
    break;

  case 55:
#line 516 "src/practica4.y"
                                            { if(posProced != -1) {
                                                if(posParam < TS[posProced].parametrosMin) {
                                                  mostrarErrorMinParam(yyvsp[-2].lexema);
                                                }
                                                else {
                                                  comprobarParam();
                                                }
                                              } }
#line 2013 "src/y.tab.c"
    break;

  case 56:
#line 525 "src/practica4.y"
                                                       { if(yyval.tipo != yyvsp[0].tipo) {
                                                           yyval.tipo = desconocido;
                                                         }
                                                         if(posProced != -1) {
                                                           if(posParam >= TS[posProced].parametrosMax) {
                                                             mostrarErrorMaxParam(TS[posProced].nombre);
                                                           }
                                                           else {
                                                             listaParam[posParam] = yyvsp[0].tipo;
                                                             posParam += 1;  
                                                           }
                                                         } }
#line 2030 "src/y.tab.c"
    break;

  case 57:
#line 537 "src/practica4.y"
                                { yyval.tipo = yyvsp[0].tipo;
                                  if(posProced != -1) {
                                    if(posParam >= TS[posProced].parametrosMax) {
                                      mostrarErrorMaxParam(TS[posProced].nombre);
                                    }
                                    else {
                                      listaParam[posParam] = yyvsp[0].tipo;
                                      posParam += 1;  
                                    } 
                                  } }
#line 2045 "src/y.tab.c"
    break;

  case 58:
#line 548 "src/practica4.y"
                                      {yyval.tipo = yyvsp[-1].tipo;}
#line 2051 "src/y.tab.c"
    break;

  case 59:
#line 549 "src/practica4.y"
                                  {
              if (esNumerico(yyvsp[0].tipo)){
                yyval.tipo = yyvsp[0].tipo;
              } else {
                errorTipoOperador(yyvsp[-1].lexema);
              }
            }
#line 2063 "src/y.tab.c"
    break;

  case 60:
#line 556 "src/practica4.y"
                                  {
              if (esNumerico(yyvsp[0].tipo)){
                yyval.tipo = yyvsp[0].tipo;
              } else {
                errorTipoOperador(yyvsp[-1].lexema);
              }
            }
#line 2075 "src/y.tab.c"
    break;

  case 61:
#line 563 "src/practica4.y"
                            {
              if (yyvsp[0].tipo == booleano){
                yyval.tipo = yyvsp[0].tipo;
              } else {
                errorTipoOperador(yyvsp[-1].lexema);
              } 
            }
#line 2087 "src/y.tab.c"
    break;

  case 62:
#line 570 "src/practica4.y"
                                         {
              if (esLista(yyvsp[0].tipo)) {
                if (yyvsp[-1].atrib == 0) {
                  yyval.tipo = entero;
                } else if (yyvsp[-1].atrib == 1) {
                  yyval.tipo = listaATipo(yyvsp[0].tipo);
                }
              } else {
                errorTipoOperador(yyvsp[-1].lexema);
              }
            }
#line 2103 "src/y.tab.c"
    break;

  case 63:
#line 581 "src/practica4.y"
                                               {
              if (esNumerico(yyvsp[0].tipo)){
                yyval.tipo = yyvsp[0].tipo;
              } else {
                errorTipoOperador(yyvsp[-1].lexema);
              }
            }
#line 2115 "src/y.tab.c"
    break;

  case 64:
#line 588 "src/practica4.y"
                                           {
              int tipo1 = tipoANumero(yyvsp[-2].tipo);
              int tipo2 = tipoANumero(yyvsp[0].tipo);
              int sumaTipos = tipo1 + tipo2;

              if (tipo1 == 99 || tipo2 == 99) {
                errorTipoOperador(yyvsp[-1].lexema);
              } else if (sumaTipos <= 8 && sumaTipos >= 6) {
                errorTipoOperador(yyvsp[-1].lexema);
              } else {
                if (sumaTipos == 0) {
                  yyval.tipo = entero;
                } else if (sumaTipos==1 || sumaTipos==2) {
                  yyval.tipo = real;
                } else {
                  if (tipo1 >= 3 && tipo2 <=1) {
                    if (sumaTipos==3) {
                      yyval.tipo = lista_entero;
                    } else {
                      yyval.tipo = lista_real;
                    }
                  } else {
                    errorTipoOperador(yyvsp[-1].lexema);
                  }
                }
              }
            }
#line 2147 "src/y.tab.c"
    break;

  case 65:
#line 615 "src/practica4.y"
                                            {
              if (esLista(yyvsp[-2].tipo) && yyvsp[0].tipo == entero) {
                yyval.tipo = yyvsp[-2].tipo;
              } else {
                errorTipoOperador(yyvsp[-1].lexema);
              }
            }
#line 2159 "src/y.tab.c"
    break;

  case 66:
#line 622 "src/practica4.y"
                                                                 {
              if(esLista(yyvsp[-2].tipo) && yyvsp[0].tipo == entero) {
                yyval.tipo = listaATipo(yyvsp[-2].tipo);
              } else {
                errorTipoOperador(yyvsp[-1].lexema);
                printf("kk: %i %i",yyvsp[-2].tipo,yyvsp[0].tipo);
              }
            }
#line 2172 "src/y.tab.c"
    break;

  case 67:
#line 630 "src/practica4.y"
                                                  {
              int tipo1 = tipoANumero(yyvsp[-2].tipo);
              int tipo2 = tipoANumero(yyvsp[0].tipo);
              int sumaTipos = tipo1 + tipo2;

              if (tipo1 == 99 || tipo2 == 99) {
                errorTipoOperador(yyvsp[-1].lexema);
              } else if (sumaTipos <= 8 && sumaTipos >= 6) {
                errorTipoOperador(yyvsp[-1].lexema);
              } else {
                if (yyvsp[-1].atrib == 1) {
                  if (sumaTipos <=2) {
                    yyval.tipo = real;
                  } else {
                    if (tipo1 >= 3 && tipo2 <=1){
                      yyval.tipo = lista_real;
                    } else {
                      errorTipoOperador(yyvsp[-1].lexema);
                    }
                  }
                } else {
                  if (sumaTipos == 0) {
                    yyval.tipo = entero;
                  } else if (sumaTipos==1 || sumaTipos==2) {
                    yyval.tipo = real;
                  } else if (sumaTipos==3) {
                    yyval.tipo = lista_entero;
                  } else {
                    yyval.tipo = lista_real;
                  }
                }
              }
            }
#line 2210 "src/y.tab.c"
    break;

  case 68:
#line 663 "src/practica4.y"
                                            {
              if (yyvsp[-2].tipo == entero && yyvsp[0].tipo == entero) {
                yyval.tipo = entero;
              } else if (yyvsp[-2].tipo == real && (yyvsp[0].tipo == entero || yyvsp[0].tipo == real)) {
                yyval.tipo = real;
              } else if (yyvsp[0].tipo == real && (yyvsp[-2].tipo == entero || yyvsp[-2].tipo == real)) {
                yyval.tipo = real;
              } else if (esLista(yyvsp[-2].tipo) && esLista(yyvsp[0].tipo) && yyvsp[-2].tipo == yyvsp[0].tipo) {
                yyval.tipo = yyvsp[-2].tipo;
              } else {
                errorTipoOperador(yyvsp[-1].lexema);
              }
            }
#line 2228 "src/y.tab.c"
    break;

  case 69:
#line 676 "src/practica4.y"
                                           {
              if (!esLista(yyvsp[-2].tipo) && !esLista(yyvsp[0].tipo)) {
                if (yyvsp[-2].tipo == yyvsp[0].tipo) {
                  yyval.tipo = booleano;
                } else if (yyvsp[-2].tipo == real && (yyvsp[0].tipo == entero || yyvsp[0].tipo == real)) {
                  yyval.tipo = booleano;
                } else if (yyvsp[0].tipo == real && (yyvsp[-2].tipo == entero || yyvsp[-2].tipo == real)) {
                  yyval.tipo = booleano;
                } else {
                  errorTipoOperador(yyvsp[-1].lexema);
                }
              } else {
                errorTipoOperador(yyvsp[-1].lexema);
              }
            }
#line 2248 "src/y.tab.c"
    break;

  case 70:
#line 691 "src/practica4.y"
                                           {
              if (yyvsp[-2].tipo == entero && yyvsp[0].tipo == entero) {
                yyval.tipo = booleano;
              } else if (yyvsp[-2].tipo == real && (yyvsp[0].tipo == entero || yyvsp[0].tipo == real)) {
                yyval.tipo = booleano;
              } else if (yyvsp[0].tipo == real && (yyvsp[-2].tipo == entero || yyvsp[-2].tipo == real)) {
                yyval.tipo = booleano;
              } else {
                errorTipoOperador(yyvsp[-1].lexema);
              }
            }
#line 2264 "src/y.tab.c"
    break;

  case 71:
#line 702 "src/practica4.y"
                                     {
              if (yyvsp[-2].tipo == booleano && yyvsp[0].tipo == booleano) {
                yyval.tipo = booleano;
              } else {
                errorTipoOperador(yyvsp[-1].lexema);
              }
            }
#line 2276 "src/y.tab.c"
    break;

  case 72:
#line 709 "src/practica4.y"
                                      {
              if (yyvsp[-2].tipo == booleano && yyvsp[0].tipo == booleano) {
                yyval.tipo = booleano;
              } else {
                errorTipoOperador(yyvsp[-1].lexema);
              }
            }
#line 2288 "src/y.tab.c"
    break;

  case 73:
#line 716 "src/practica4.y"
                                      {
              if (yyvsp[-2].tipo == booleano && yyvsp[0].tipo == booleano) {
                yyval.tipo = booleano;
              } else {
                errorTipoOperador(yyvsp[-1].lexema);
              }
            }
#line 2300 "src/y.tab.c"
    break;

  case 74:
#line 723 "src/practica4.y"
                                                                {
              if (esLista(yyvsp[-4].tipo) && yyvsp[-2].tipo == listaATipo(yyvsp[-4].tipo) && yyvsp[0].tipo == entero) {
                yyval.tipo = yyvsp[-4].tipo;
              } else {
                errorTipoOperador2(yyvsp[-3].lexema, yyvsp[-1].lexema);
              }
            }
#line 2312 "src/y.tab.c"
    break;

  case 75:
#line 730 "src/practica4.y"
                 {if (declarado(yyvsp[0].lexema) == 0) {
                    errorNoDeclarado(yyvsp[0].lexema);
                  }
                  else {
                    yyval.tipo = buscarTipoVariable(yyvsp[0].lexema);
                  }}
#line 2323 "src/y.tab.c"
    break;

  case 76:
#line 736 "src/practica4.y"
                             { yyval.tipo = yyvsp[0].tipo; }
#line 2329 "src/y.tab.c"
    break;

  case 77:
#line 737 "src/practica4.y"
                        { yyval.tipo = yyvsp[0].tipo; }
#line 2335 "src/y.tab.c"
    break;

  case 79:
#line 740 "src/practica4.y"
                                                      { yyval.tipo = yyvsp[-1].tipo; }
#line 2341 "src/y.tab.c"
    break;

  case 80:
#line 742 "src/practica4.y"
                { tipoTmp = yyvsp[0].tipo; }
#line 2347 "src/y.tab.c"
    break;

  case 81:
#line 743 "src/practica4.y"
                        { tipoTmp = obtenerTipoLista(yyvsp[0].tipo); }
#line 2353 "src/y.tab.c"
    break;


#line 2357 "src/y.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[+*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 745 "src/practica4.y"


/** Aqui incluimos el fichero generado por el 'lex'
 ** que implementa la funcion 'yylex'
 **/

#include "lex.yy.c"

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_BLACK   "\x1b[0m"

/** Se debe implementar la funcion yyerror. En este caso
 ** simplemente escribimos el mensaje de error en pantalla
 **/

void lexerror(const char *msg)
{
  printf(ANSI_COLOR_RED "[Error Lexico]" ANSI_COLOR_BLACK "(Linea %d) Caracter no reconocido: %s\n", linea_actual, msg);
}

void yyerror(const char *msg)
{
  printf(ANSI_COLOR_YELLOW "[Error sintactico]" ANSI_COLOR_BLACK "(Linea %d) Error: %s\n", linea_actual, msg);
}

void mostrarErrorTipoInco(int pos, dtipo tipo)
{
  char *stringTipo;
  switch(tipo) {
    case entero:
      stringTipo = "entero";
    break;
    case real:
      stringTipo = "real";
    break;
    case booleano:
      stringTipo = "booleano";
    break;
    case caracter:
      stringTipo = "caracter";
    break;
    case lista_entero:
      stringTipo = "lista_entero";
    break;
    case lista_real:
      stringTipo = "lista_real";
    break;
    case lista_caracter:
      stringTipo = "lista_caracter";
    break;
    case lista_booleano:
      stringTipo = "lista_booleano";
    break;
    case desconocido:
      stringTipo = "desconocido";
    break;
    case no_asignado:
      stringTipo = "no_asignado";
    break;
  }
  printf(ANSI_COLOR_MAGENTA "[Error semantico]" ANSI_COLOR_BLACK "(Linea %d) Error: El parámetro de la posición %d debe ser de tipo %s\n", linea_actual, pos, stringTipo);
}

void mostrarErrorOrden()
{
  printf(ANSI_COLOR_MAGENTA "[Error semantico]" ANSI_COLOR_BLACK "(Linea %d) Error: El orden de los parámetros no es correcto\n", linea_actual);
}

void mostrarErrorMinParam(char* nomProced)
{
  printf(ANSI_COLOR_MAGENTA "[Error semantico]" ANSI_COLOR_BLACK "(Linea %d) Error: El número de parámetros es menor a los necesarios en el procedimiento %s\n", linea_actual, nomProced);
}

void mostrarErrorMaxParam(char* nomProced)
{
  printf(ANSI_COLOR_MAGENTA "[Error semantico]" ANSI_COLOR_BLACK "(Linea %d) Error: El número de parámetros es mayor a los disponibles en el procedimiento %s\n", linea_actual, nomProced);
}

void mostrarErrorProcedDesco(char* nomProced)
{
  printf(ANSI_COLOR_MAGENTA "[Error semantico]" ANSI_COLOR_BLACK "(Linea %d) Error: El procedimiento %s no ha sido declarado\n", linea_actual, nomProced);
}

void mostrarErrorTipoAsig(dtipo tipo)
{
  char *stringTipo;
  switch(tipo) {
    case entero:
      stringTipo = "entero";
    break;
    case real:
      stringTipo = "real";
    break;
    case booleano:
      stringTipo = "booleano";
    break;
    case caracter:
      stringTipo = "caracter";
    break;
    case lista_entero:
      stringTipo = "lista_entero";
    break;
    case lista_real:
      stringTipo = "lista_real";
    break;
    case lista_caracter:
      stringTipo = "lista_caracter";
    break;
    case lista_booleano:
      stringTipo = "lista_booleano";
    break;
    case desconocido:
      stringTipo = "desconocido";
    break;
    case no_asignado:
      stringTipo = "no_asignado";
    break;
  }
  printf(ANSI_COLOR_MAGENTA "[Error semantico]" ANSI_COLOR_BLACK "(Linea %d) Error: La expresion en la asignacion debe ser de tipo %s\n", linea_actual, stringTipo);
}

void errorNoDeclarado(char* lexema){
  printf(ANSI_COLOR_MAGENTA "[Error semantico]" ANSI_COLOR_BLACK "(Linea %d) Error: La variable %s no ha sido declarada\n", linea_actual, lexema);
}

void errorYaDeclarado(char* lexema){
  printf(ANSI_COLOR_MAGENTA "[Error semantico]" ANSI_COLOR_BLACK "(Linea %d) Error: La variable %s ya ha sido declarada\n", linea_actual, lexema);
}

void errorTipoOperador(char* lexema) {
  printf(ANSI_COLOR_MAGENTA "[Error semantico]" ANSI_COLOR_BLACK "(Linea %d) Error: El operador %s no admite variables del tipo recibido\n", linea_actual, lexema);
}

void errorTipoOperador2(char* lexema, char* lexema2) {
  printf(ANSI_COLOR_MAGENTA "[Error semantico]" ANSI_COLOR_BLACK "(Linea %d) Error: El operador %s %s no admite variables del tipo recibido\n", linea_actual, lexema, lexema2);
}
