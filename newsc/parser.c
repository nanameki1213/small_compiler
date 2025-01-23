/* original parser id follows */
/* yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93" */
/* (use YYMAJOR/YYMINOR for ifdefs dependent on parser version) */

#define YYBYACC 1
#define YYMAJOR 2
#define YYMINOR 0
#define YYPATCH 20210109

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)
#define YYENOMEM       (-2)
#define YYEOF          0
#define YYPREFIX "yy"

#define YYPURE 0

#line 2 "parser.y"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "sc.h"
char label1[BUFSIZ];
char label2[BUFSIZ];
int args;
int i;
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#line 13 "parser.y"
typedef union {
  char *lexeme;
  char *lexvalue;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 43 "y.tab.c"

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

#if !(defined(yylex) || defined(YYSTATE))
int YYLEX_DECL();
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(msg)
#endif

extern int YYPARSE_DECL();

#define TOKEN_EOF 257
#define TOKEN_ERROR 258
#define TOKEN_ID 259
#define TOKEN_NUM 260
#define TOKEN_COL 261
#define TOKEN_SEMICOL 262
#define TOKEN_COLEQ 263
#define TOKEN_EQ 264
#define TOKEN_NE 265
#define TOKEN_LT 266
#define TOKEN_LE 267
#define TOKEN_GT 268
#define TOKEN_GE 269
#define TOKEN_LPAR 270
#define TOKEN_RPAR 271
#define TOKEN_PLUS 272
#define TOKEN_MINUS 273
#define TOKEN_ASTER 274
#define TOKEN_SLASH 275
#define TOKEN_PERCENT 276
#define TOKEN_COMMA 277
#define TOKEN_SHIFTL 278
#define TOKEN_SHIFTR 279
#define TOKEN_LBRA 280
#define TOKEN_RBRA 281
#define TOKEN_IF 282
#define TOKEN_THEN 283
#define TOKEN_ELSE 284
#define TOKEN_WHILE 285
#define TOKEN_DO 286
#define TOKEN_REPEAT 287
#define TOKEN_UNTIL 288
#define TOKEN_GOTO 289
#define TOKEN_BEGIN 290
#define TOKEN_END 291
#define TOKEN_LONG 292
#define TOKEN_WORD 293
#define TOKEN_BYTE 294
#define TOKEN_AND 295
#define TOKEN_OR 296
#define TOKEN_NOT 297
#define TOKEN_RETURN 298
#define TOKEN_FUNCTION 299
#define YYERRCODE 256
typedef short YYINT;
static const YYINT yylhs[] = {                           -1,
    1,    2,    1,    4,    1,    1,    1,    1,    3,    3,
    6,    6,    7,    8,    8,    8,    8,    8,    8,    8,
    9,    9,   11,    9,   10,   10,   10,   10,    5,    5,
    5,    5,    5,    5,    5,   12,   12,   13,   12,   14,
   12,   15,   16,   12,   17,   12,   19,   20,   12,   21,
   12,   12,   12,   12,   18,   23,   18,   22,   22,   26,
   24,   27,   24,   28,   24,   25,   25,   30,   33,   34,
   29,   31,   31,   35,   35,   32,   32,   37,   38,    0,
   36,   36,   36,   39,   39,
};
static const YYINT yylen[] = {                            2,
    1,    0,    5,    0,    5,    1,    3,    2,    0,    1,
    1,    3,    2,    0,    3,    3,    3,    3,    3,    3,
    2,    3,    0,    4,    0,    3,    3,    3,    1,    3,
    3,    3,    3,    3,    3,    0,    3,    0,    4,    0,
    5,    0,    0,    8,    0,    6,    0,    0,    6,    0,
    5,    2,    2,    3,    0,    0,    3,    1,    3,    0,
    4,    0,    4,    0,    4,    0,    3,    0,    0,    0,
   10,    0,    1,    1,    3,    0,    3,    0,    0,    4,
    0,    3,    4,    0,    2,
};
static const YYINT yydefred[] = {                        78,
    0,   81,    0,    0,    0,    0,    0,    0,    0,    0,
   60,   62,   64,   68,    0,    0,   82,    0,    0,   47,
   50,    0,    0,    0,   80,    0,    0,    0,    0,   85,
   83,   38,    0,   40,    0,    0,    6,    0,    0,    0,
    0,   14,    0,   25,    0,    0,    0,   52,   58,    0,
   53,    0,   61,   63,   65,    0,    0,   37,    0,    0,
    0,    0,    0,   25,   23,    8,    0,   45,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   54,    0,
   74,    0,    0,   39,    0,   11,    0,    0,    0,    0,
    7,    0,   25,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   30,   31,   32,   33,   34,   35,   48,
    0,   59,   67,   69,    0,   41,    0,   43,    0,    0,
    0,   15,   16,   17,   18,   19,   20,    0,   26,   27,
   28,    0,   51,   76,   75,   12,    0,    3,    5,   56,
   46,   49,    0,    0,    0,    0,    0,   44,   57,   77,
   71,
};
static const YYINT yydgoto[] = {                          1,
   42,   61,   85,   62,   86,   87,   44,   67,   45,   69,
   93,   25,   57,   59,   35,  137,  100,  141,   46,  132,
   47,   50,  145,    8,   53,   26,   27,   28,    9,   29,
   82,  143,  134,  147,   83,    3,    2,   10,   16,
};
static const YYINT yysindex[] = {                         0,
    0,    0, -182, -251, -248, -244, -241, -238, -235, -203,
    0,    0,    0,    0, -232, -231,    0, -211, -240,    0,
    0, -220, -203, -240,    0, -239, -239, -239, -224,    0,
    0,    0, -240,    0, -226,    0,    0, -240, -212, -212,
 -212,    0, -214,    0, -131, -240, -203,    0,    0, -256,
    0, -190,    0,    0,    0, -201, -203,    0, -240, -240,
 -198, -202, -191,    0,    0,    0, -177,    0, -247, -240,
 -240, -240, -240, -240, -240, -205, -200, -203,    0, -192,
    0, -188, -181,    0, -168,    0, -170, -173, -240, -240,
    0, -247,    0, -212, -212, -212, -212, -212, -212, -203,
 -212, -212, -212,    0,    0,    0,    0,    0,    0,    0,
 -240,    0,    0,    0, -201,    0, -240,    0, -158, -167,
 -247,    0,    0,    0,    0,    0,    0, -165,    0,    0,
    0, -203,    0,    0,    0,    0, -147,    0,    0,    0,
    0,    0, -201, -240, -203, -142, -203,    0,    0,    0,
    0,
};
static const YYINT yyrindex[] = {                         0,
    0,    0,    1,    0,    0,    0,    0, -139,    0,  125,
    0,    0,    0,    0,    0,    0,    0, -154,    0,    0,
    0,    0, -253,    0,    0, -156, -156, -156,    0,    0,
    0,    0,    0,    0,    0,   36,    0,    0,    0,    0,
    0,    0,    0,    0,  176,    0, -160,    0,    0,    0,
    0,    0,    0,    0,    0, -141,    5,    0, -140,    0,
    0,    0,    0,    0,    0,    0,   71,    0,  104,    0,
    0,    0,    0,    0,    0,    0,    0, -253,    0,    0,
    0,    0, -126,    0,    0,    0, -125,    0, -140,    0,
    0,  132,    0,    0,    0,    0,    0,    0,    0,    5,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  160,    0,    0,    0,    0,    0,    0,    4,    0,    0,
    0,    5,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0, -245,    0,    5,    0, -133,    0,    0,    0,
    0,
};
static const YYINT yygindex[] = {                         0,
  -31,    0,   58,    0,  -17,    0,  -27,    0,   69,  -42,
    0,  -23,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  -53,   33,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,
};
#define YYTABLESIZE 467
static const YYINT yytable[] = {                         49,
   79,   43,   81,   55,   36,   78,   51,   11,   36,   66,
   12,   64,   65,   70,   13,   58,   70,   14,   36,   37,
   63,   92,   15,   77,  101,  102,   17,   30,   76,   38,
   31,   39,   40,   84,   79,    1,   70,   36,   48,   70,
   52,   70,   88,   70,   70,   56,   36,   37,  103,   32,
  121,   33,   70,   60,  112,   18,   41,   38,   34,   54,
   55,  135,  122,  123,  124,  125,  126,  127,   68,   80,
   13,   89,  120,  129,  130,  131,  128,   90,   19,   91,
  110,   20,  114,   21,   41,   22,   23,  111,  113,  146,
    4,    5,    6,  133,   24,  115,   94,   95,   96,  136,
   97,   98,  116,   21,   66,   66,  117,  118,  142,    4,
    5,    6,  138,  139,   66,  144,    7,   99,  140,  150,
   66,  149,   84,  151,   36,   42,  148,   36,   36,   72,
    9,   22,   70,   71,   72,   73,   74,   75,  104,  105,
  106,  107,  108,  109,   73,   10,  119,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   24,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   29,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   79,
    0,    0,    0,    0,    0,   55,   36,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   79,    0,    0,   79,    0,   79,   36,   79,
   79,   55,   36,    0,   55,   36,    0,    1,   79,    1,
    1,    1,    1,    1,    1,    2,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    4,    1,    0,    1,    1,
    0,    1,    0,    1,    0,    0,    1,    0,    0,    0,
    1,    1,   13,    0,   13,   13,   13,   13,   13,   13,
    0,   13,   13,   13,    0,    0,    0,   13,    0,    0,
    0,   13,    0,   13,   13,    0,   13,    0,   13,    0,
    0,   13,    0,    0,    0,   21,   13,   21,   21,   21,
   21,   21,   21,    0,   21,    0,    0,    0,    0,    0,
   21,    0,    0,    0,   21,    0,   21,   21,    0,   21,
    0,   21,    0,   22,   21,   22,   22,   22,   22,   22,
   22,    0,   22,    0,    0,    0,    0,    0,   22,    0,
    0,    0,   22,    0,   22,   22,    0,   22,    0,   22,
    0,   24,   22,   24,   24,   24,   24,   24,   24,    0,
   24,    0,    0,    0,    0,    0,   24,   29,    0,    0,
   24,    0,   24,   24,    0,   24,   29,   24,    0,    0,
   24,    0,   29,    0,    0,    0,   29,    0,   29,   29,
    0,   29,    0,   29,    0,    0,   29,
};
static const YYINT yycheck[] = {                         23,
    0,   19,   56,    0,    0,  262,   24,  259,  262,   41,
  259,   39,   40,  259,  259,   33,  262,  259,  259,  260,
   38,   64,  261,   47,  272,  273,  262,  260,   46,  270,
  262,  272,  273,   57,  291,    0,  282,  291,  259,  285,
  280,  287,   60,  289,  290,  270,  259,  260,  296,  261,
   93,  263,  298,  280,   78,  259,  297,  270,  270,   27,
   28,  115,   94,   95,   96,   97,   98,   99,  283,  260,
    0,  270,   90,  101,  102,  103,  100,  280,  282,  271,
  286,  285,  271,  287,  297,  289,  290,  288,  281,  143,
  292,  293,  294,  111,  298,  277,  274,  275,  276,  117,
  278,  279,  271,    0,  261,  262,  277,  281,  132,  292,
  293,  294,  271,  281,  271,  263,  299,  295,  284,  262,
  277,  145,  262,  147,    0,  280,  144,  288,  262,  271,
  271,    0,  264,  265,  266,  267,  268,  269,   70,   71,
   72,   73,   74,   75,  271,  271,   89,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,    0,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,    0,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  259,
   -1,   -1,   -1,   -1,   -1,  262,  262,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  282,   -1,   -1,  285,   -1,  287,  284,  289,
  290,  288,  288,   -1,  291,  291,   -1,  262,  298,  264,
  265,  266,  267,  268,  269,  270,  271,  272,  273,  274,
  275,  276,  277,  278,  279,  280,  281,   -1,  283,  284,
   -1,  286,   -1,  288,   -1,   -1,  291,   -1,   -1,   -1,
  295,  296,  262,   -1,  264,  265,  266,  267,  268,  269,
   -1,  271,  272,  273,   -1,   -1,   -1,  277,   -1,   -1,
   -1,  281,   -1,  283,  284,   -1,  286,   -1,  288,   -1,
   -1,  291,   -1,   -1,   -1,  262,  296,  264,  265,  266,
  267,  268,  269,   -1,  271,   -1,   -1,   -1,   -1,   -1,
  277,   -1,   -1,   -1,  281,   -1,  283,  284,   -1,  286,
   -1,  288,   -1,  262,  291,  264,  265,  266,  267,  268,
  269,   -1,  271,   -1,   -1,   -1,   -1,   -1,  277,   -1,
   -1,   -1,  281,   -1,  283,  284,   -1,  286,   -1,  288,
   -1,  262,  291,  264,  265,  266,  267,  268,  269,   -1,
  271,   -1,   -1,   -1,   -1,   -1,  277,  262,   -1,   -1,
  281,   -1,  283,  284,   -1,  286,  271,  288,   -1,   -1,
  291,   -1,  277,   -1,   -1,   -1,  281,   -1,  283,  284,
   -1,  286,   -1,  288,   -1,   -1,  291,
};
#define YYFINAL 1
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 299
#define YYUNDFTOKEN 341
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"TOKEN_EOF","TOKEN_ERROR",
"TOKEN_ID","TOKEN_NUM","TOKEN_COL","TOKEN_SEMICOL","TOKEN_COLEQ","TOKEN_EQ",
"TOKEN_NE","TOKEN_LT","TOKEN_LE","TOKEN_GT","TOKEN_GE","TOKEN_LPAR",
"TOKEN_RPAR","TOKEN_PLUS","TOKEN_MINUS","TOKEN_ASTER","TOKEN_SLASH",
"TOKEN_PERCENT","TOKEN_COMMA","TOKEN_SHIFTL","TOKEN_SHIFTR","TOKEN_LBRA",
"TOKEN_RBRA","TOKEN_IF","TOKEN_THEN","TOKEN_ELSE","TOKEN_WHILE","TOKEN_DO",
"TOKEN_REPEAT","TOKEN_UNTIL","TOKEN_GOTO","TOKEN_BEGIN","TOKEN_END",
"TOKEN_LONG","TOKEN_WORD","TOKEN_BYTE","TOKEN_AND","TOKEN_OR","TOKEN_NOT",
"TOKEN_RETURN","TOKEN_FUNCTION",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : program",
"factor : TOKEN_ID",
"$$1 :",
"factor : TOKEN_ID $$1 TOKEN_LPAR arglist_opt TOKEN_RPAR",
"$$2 :",
"factor : TOKEN_ID $$2 TOKEN_LBRA expression TOKEN_RBRA",
"factor : TOKEN_NUM",
"factor : TOKEN_LPAR expression TOKEN_RPAR",
"factor : TOKEN_NOT factor",
"arglist_opt :",
"arglist_opt : arglist",
"arglist : expression",
"arglist : arglist TOKEN_COMMA expression",
"term : factor factorlist",
"factorlist :",
"factorlist : factorlist TOKEN_ASTER factor",
"factorlist : factorlist TOKEN_SLASH factor",
"factorlist : factorlist TOKEN_PERCENT factor",
"factorlist : factorlist TOKEN_SHIFTL factor",
"factorlist : factorlist TOKEN_SHIFTR factor",
"factorlist : factorlist TOKEN_AND factor",
"polynomial : term termlist",
"polynomial : TOKEN_PLUS term termlist",
"$$3 :",
"polynomial : TOKEN_MINUS term $$3 termlist",
"termlist :",
"termlist : termlist TOKEN_PLUS term",
"termlist : termlist TOKEN_MINUS term",
"termlist : termlist TOKEN_OR term",
"expression : polynomial",
"expression : polynomial TOKEN_EQ polynomial",
"expression : polynomial TOKEN_NE polynomial",
"expression : polynomial TOKEN_LT polynomial",
"expression : polynomial TOKEN_LE polynomial",
"expression : polynomial TOKEN_GT polynomial",
"expression : polynomial TOKEN_GE polynomial",
"statement :",
"statement : TOKEN_ID TOKEN_COLEQ expression",
"$$4 :",
"statement : TOKEN_ID TOKEN_COL $$4 statement",
"$$5 :",
"statement : TOKEN_ID TOKEN_LPAR $$5 arglist_opt TOKEN_RPAR",
"$$6 :",
"$$7 :",
"statement : TOKEN_ID $$6 TOKEN_LBRA expression TOKEN_RBRA $$7 TOKEN_COLEQ expression",
"$$8 :",
"statement : TOKEN_IF expression TOKEN_THEN $$8 statement else_opt",
"$$9 :",
"$$10 :",
"statement : TOKEN_WHILE $$9 expression TOKEN_DO $$10 statement",
"$$11 :",
"statement : TOKEN_REPEAT $$11 statement TOKEN_UNTIL expression",
"statement : TOKEN_GOTO TOKEN_ID",
"statement : TOKEN_RETURN expression",
"statement : TOKEN_BEGIN statementlist TOKEN_END",
"else_opt :",
"$$12 :",
"else_opt : TOKEN_ELSE $$12 statement",
"statementlist : statement",
"statementlist : statementlist TOKEN_SEMICOL statement",
"$$13 :",
"variable : TOKEN_LONG TOKEN_ID $$13 size_opt",
"$$14 :",
"variable : TOKEN_WORD TOKEN_ID $$14 size_opt",
"$$15 :",
"variable : TOKEN_BYTE TOKEN_ID $$15 size_opt",
"size_opt :",
"size_opt : TOKEN_LBRA TOKEN_NUM TOKEN_RBRA",
"$$16 :",
"$$17 :",
"$$18 :",
"function : TOKEN_FUNCTION TOKEN_ID $$16 TOKEN_LPAR paramlist_opt TOKEN_RPAR $$17 variablelist $$18 statement",
"paramlist_opt :",
"paramlist_opt : paramlist",
"paramlist : variable",
"paramlist : paramlist TOKEN_COMMA variable",
"variablelist :",
"variablelist : variablelist variable TOKEN_SEMICOL",
"$$19 :",
"$$20 :",
"program : $$19 decllist $$20 statement",
"decllist :",
"decllist : decllist function TOKEN_SEMICOL",
"decllist : decllist variable addresspart TOKEN_SEMICOL",
"addresspart :",
"addresspart : TOKEN_COL TOKEN_NUM",

};
#endif

#if YYDEBUG
int      yydebug;
#endif

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;
int      yynerrs;

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  10000
#endif
#endif

#define YYINITSTACKSIZE 200

typedef struct {
    unsigned stacksize;
    YYINT    *s_base;
    YYINT    *s_mark;
    YYINT    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
} YYSTACKDATA;
/* variables for the parser stack */
static YYSTACKDATA yystack;

#if YYDEBUG
#include <stdio.h>	/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    YYINT *newss;
    YYSTYPE *newvs;

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return YYENOMEM;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = (int) (data->s_mark - data->s_base);
    newss = (YYINT *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return YYENOMEM;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return YYENOMEM;

    data->l_base = newvs;
    data->l_mark = newvs + i;

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab

int
YYPARSE_DECL()
{
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yym = 0;
    yyn = 0;
    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        yychar = YYLEX;
        if (yychar < 0) yychar = YYEOF;
#if YYDEBUG
        if (yydebug)
        {
            if ((yys = yyname[YYTRANSLATE(yychar)]) == NULL) yys = yyname[YYUNDFTOKEN];
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if (((yyn = yysindex[yystate]) != 0) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if (((yyn = yyrindex[yystate]) != 0) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag != 0) goto yyinrecovery;

    YYERROR_CALL("syntax error");

    goto yyerrlab; /* redundant goto avoids 'unused label' warning */
yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if (((yyn = yysindex[*yystack.s_mark]) != 0) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
                --yystack.s_mark;
                --yystack.l_mark;
            }
        }
    }
    else
    {
        if (yychar == YYEOF) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            if ((yys = yyname[YYTRANSLATE(yychar)]) == NULL) yys = yyname[YYUNDFTOKEN];
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym > 0)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);

    switch (yyn)
    {
case 1:
#line 32 "parser.y"
	{ gen_code("load_id", yystack.l_mark[0].lexeme); }
break;
case 2:
#line 33 "parser.y"
	{ args = 0; }
break;
case 3:
#line 35 "parser.y"
	{ gen_code("load_num", "0");
                  gen_code("store_arg", "-");
                  gen_code("call", yystack.l_mark[-4].lexeme);
                  gen_code("load_arg", "-");
                  for (i = 0; i < args; i++) {
                    gen_code("cancel_arg", "-");
                  }
                }
break;
case 4:
#line 43 "parser.y"
	{ gen_code("load_adr", yystack.l_mark[0].lexeme); }
break;
case 5:
#line 45 "parser.y"
	{ gen_code("add_index", yystack.l_mark[-4].lexeme);
                  gen_code("load_ind", yystack.l_mark[-4].lexeme);
                }
break;
case 6:
#line 48 "parser.y"
	{ gen_code("load_num", yystack.l_mark[0].lexvalue); }
break;
case 8:
#line 50 "parser.y"
	{ gen_code("not", "-"); }
break;
case 11:
#line 58 "parser.y"
	{ gen_code("store_arg", "-");
                  args += 1;
                }
break;
case 12:
#line 62 "parser.y"
	{ gen_code("store_arg", "-");
                  args += 1;
                }
break;
case 15:
#line 72 "parser.y"
	{ gen_code("mul", "-"); }
break;
case 16:
#line 74 "parser.y"
	{ gen_code("div", "-"); }
break;
case 17:
#line 76 "parser.y"
	{ gen_code("mod", "-"); }
break;
case 18:
#line 78 "parser.y"
	{ gen_code("shiftl", "-"); }
break;
case 19:
#line 80 "parser.y"
	{ gen_code("shiftr", "-"); }
break;
case 20:
#line 82 "parser.y"
	{ gen_code("and", "-"); }
break;
case 23:
#line 87 "parser.y"
	{ gen_code("neg", "-"); }
break;
case 26:
#line 93 "parser.y"
	{ gen_code("add", "-"); }
break;
case 27:
#line 95 "parser.y"
	{ gen_code("sub", "-"); }
break;
case 28:
#line 97 "parser.y"
	{ gen_code("or", "-"); }
break;
case 30:
#line 102 "parser.y"
	{ gen_code("eq", "-"); }
break;
case 31:
#line 104 "parser.y"
	{ gen_code("ne", "-"); }
break;
case 32:
#line 106 "parser.y"
	{ gen_code("lt", "-"); }
break;
case 33:
#line 108 "parser.y"
	{ gen_code("le", "-"); }
break;
case 34:
#line 110 "parser.y"
	{ gen_code("gt", "-"); }
break;
case 35:
#line 112 "parser.y"
	{ gen_code("ge", "-"); }
break;
case 37:
#line 117 "parser.y"
	{ gen_code("store_id", yystack.l_mark[-2].lexeme); }
break;
case 38:
#line 118 "parser.y"
	{ gen_code("label", yystack.l_mark[-1].lexeme); }
break;
case 40:
#line 120 "parser.y"
	{ args = 0; }
break;
case 41:
#line 122 "parser.y"
	{ gen_code("load_num", "0");
                          gen_code("store_arg", "-");
                          gen_code("call", yystack.l_mark[-4].lexeme);
                          gen_code("cancel_arg", "-");
                          for (i = 0; i < args; i++) {
                            gen_code("cancel_arg", "-");
                          }
                        }
break;
case 42:
#line 130 "parser.y"
	{            gen_code("load_adr", yystack.l_mark[0].lexeme); }
break;
case 43:
#line 132 "parser.y"
	{ gen_code("add_index", yystack.l_mark[-4].lexeme); }
break;
case 44:
#line 134 "parser.y"
	{ gen_code("store_ind", yystack.l_mark[-7].lexeme); }
break;
case 45:
#line 136 "parser.y"
	{ gen_code("tst", "-");
                        strcpy(label1, new_label());
                        gen_code("jeq", label1);
                      }
break;
case 47:
#line 141 "parser.y"
	{ strcpy(label1, new_label());
                        gen_code("label", label1);
                      }
break;
case 48:
#line 144 "parser.y"
	{ strcpy(label2, new_label());
                          gen_code("tst", "-");
                          gen_code("jeq", label2);
                        }
break;
case 49:
#line 148 "parser.y"
	{ gen_code("jmp", label1);
                gen_code("label", label2);
              }
break;
case 50:
#line 151 "parser.y"
	{  strcpy(label1, new_label());
                     gen_code("label", label1);
                  }
break;
case 51:
#line 155 "parser.y"
	{ gen_code("tst", "-");
                    gen_code("jeq", label1);
                  }
break;
case 52:
#line 158 "parser.y"
	{ gen_code("jmp", yystack.l_mark[0].lexeme); }
break;
case 53:
#line 160 "parser.y"
	{ gen_code("store_id", "ans");
                  gen_code("return", "-");
                  }
break;
case 55:
#line 166 "parser.y"
	{ gen_code("label", label1); }
break;
case 56:
#line 167 "parser.y"
	{ strcpy(label2, new_label());
                  gen_code("jmp", label2);
                  gen_code("label", label1);
                }
break;
case 57:
#line 171 "parser.y"
	{ gen_code("label", label2); }
break;
case 60:
#line 178 "parser.y"
	{ gen_code("var_long", yystack.l_mark[0].lexeme); }
break;
case 62:
#line 180 "parser.y"
	{ gen_code("var_word", yystack.l_mark[0].lexeme); }
break;
case 64:
#line 182 "parser.y"
	{ gen_code("var_byte", yystack.l_mark[0].lexeme); }
break;
case 67:
#line 188 "parser.y"
	{ gen_code("set_size", yystack.l_mark[-1].lexvalue); }
break;
case 68:
#line 192 "parser.y"
	{ gen_code("start_func", yystack.l_mark[0].lexeme); }
break;
case 69:
#line 195 "parser.y"
	{ gen_code("start_prologue", "-"); }
break;
case 70:
#line 196 "parser.y"
	{ gen_code("end_prologue", "-"); }
break;
case 71:
#line 197 "parser.y"
	{ gen_code("end_func", "-"); }
break;
case 78:
#line 212 "parser.y"
	{ gen_code("start", "main"); }
break;
case 79:
#line 213 "parser.y"
	{ gen_code("label", "main"); }
break;
case 80:
#line 214 "parser.y"
	{ gen_code("end", "-"); }
break;
case 85:
#line 223 "parser.y"
	{ gen_code("set_address", yystack.l_mark[0].lexvalue); }
break;
#line 922 "y.tab.c"
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
        if (yychar < 0)
        {
            yychar = YYLEX;
            if (yychar < 0) yychar = YYEOF;
#if YYDEBUG
            if (yydebug)
            {
                if ((yys = yyname[YYTRANSLATE(yychar)]) == NULL) yys = yyname[YYUNDFTOKEN];
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == YYEOF) goto yyaccept;
        goto yyloop;
    }
    if (((yyn = yygindex[yym]) != 0) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yystack.s_mark, yystate);
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
    *++yystack.s_mark = (YYINT) yystate;
    *++yystack.l_mark = yyval;
    goto yyloop;

yyoverflow:
    YYERROR_CALL("yacc stack overflow");

yyabort:
    yyfreestack(&yystack);
    return (1);

yyaccept:
    yyfreestack(&yystack);
    return (0);
}
