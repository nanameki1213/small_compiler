#include <stdio.h>
#include <ctype.h>
#include "sc.h"

static FILE *lexin;
static FILE *lexout;
static char c;

static int c_lineno = 1;
int lineno;

char lexvalue[BUFSIZ];

int token;
static int end_of_lexeme;
char lexeme[BUFSIZ];

void gen_code(char *op, char *opr)
{
  fprintf(lexout, "%-16s\t%s\n", op, opr);
}

void get_char()
{
	c = fgetc(lexin);
  if (c == '\n') {
    c_lineno += 1;
  }
	return;
}

void save_char(char c)
{
	lexeme[end_of_lexeme++] = c;
	lexeme[end_of_lexeme] = '\0';
}

void get_token()
{
  int i;
  int value = 0;

state0:
  lineno = c_lineno;

  end_of_lexeme = 0;
  if (char_pos(WHITESPACE, c) >= 0) {
    get_char();
    goto state0;
  } else if (c == '(') {
    save_char(c);
    get_char();
    goto state1;
  } else if (char_pos(ALPHABET, tolower(c)) >= 0) {
    save_char(c);
    get_char();
    goto state4;
  } else if (c == '0') {
    save_char(c);
    get_char();
    value = 0;
    goto state5;
  } else if ((i = char_pos(DIGIT, c)) >= 0) {
    save_char(c);
    value = i;
    get_char();
    goto state8;
  } else if (c == '\'') {
    save_char(c);
    get_char();
    goto state9;
  } else if (c == ':') {
    save_char(c);
    get_char();
    goto state12;
  } else if (c == '<') {
    save_char(c);
    get_char();
    goto state13;
  } else if (c == '>') {
    save_char(c);
    get_char();
    goto state14;
  } else if (c == '=') {
    save_char(c);
    get_char();
    goto state15;
  } else if (c == ')') {
    save_char(c);
    get_char();
    token = TOKEN_RPAR;
    goto final;
  } else if (c == '+') {
    save_char(c);
    get_char();
    token = TOKEN_PLUS;
    goto final;
  } else if (c == '-') {
    save_char(c);
    get_char();
    token = TOKEN_MINUS;
    goto final;
  } else if (c == '*') {
    save_char(c);
    get_char();
    token = TOKEN_ASTER;
    goto final;
  } else if (c == '%') {
    save_char(c);
    get_char();
    token = TOKEN_PERCENT;
    goto final;
  } else if (c == '/') {
    save_char(c);
    get_char();
    token = TOKEN_SLASH;
    goto final;
  } else if (c == ';') {
    save_char(c);
    get_char();
    token = TOKEN_SEMICOL;
    goto final;
  } else if (c == ',') {
    save_char(c);
    get_char();
    token = TOKEN_COMMA;
    goto final;
  } else if (c == EOF) {
    token = TOKEN_EOF;
    goto final;
  } else {
    save_char(c);
    get_char();
    token = TOKEN_ERROR;
    goto final;
  }

state1:
  if (c == '*') {
    save_char(c);
    get_char();
    goto state2;
  } else {
    token = TOKEN_LPAR;
    goto final;
  }

state2:
  if (c == '*') {
    save_char(c);
    get_char();
    goto state3;
  } else if (c == EOF) {
    goto state0;
  } else {
    save_char(c);
    get_char();
    goto state2;
  }

state3:
  if (c == '*') {
    save_char(c);
    get_char();
    goto state3;
  } else if (c == ')') {
    get_char();
    end_of_lexeme = 0;
    goto state0;
  } else if (c == EOF) {
    end_of_lexeme = 0;
    goto state0;
  } else {
    goto state2;
  }

state4:
  if (char_pos(ALPHABET, tolower(c)) >= 0) {
    save_char(c);
    get_char();
    goto state4;
  } else if (char_pos(DIGIT, c) >= 0) {
    save_char(c);
    get_char();
    goto state4;
  } else {
    int index;
    // 予約語か？
    if ((index = find_keywords(lexeme)) >= 0) {
      token = keywords[index].value;
    } else {
      token = TOKEN_ID;
    }

    goto final;
  }

state5:
  if (c == 'x') {
    save_char(c);
    get_char();
    goto state6;
  } else if ((i = char_pos(DIGIT, c)) >= 0) {
    save_char(c);
    value = i;
    get_char();
    goto state8;
  } else if (c == 'b') {
    save_char(c);
    get_char();
    goto state16;
  } else {
    token = TOKEN_NUM;
    sprintf(lexvalue, "%d", value);
    goto final;
  }

state6:
  if ((i = char_pos(HEXDIGIT, tolower(c))) >= 0) {
    save_char(c);
    value = i;
    get_char();
    goto state7;
  } else {
    get_char();
    token = TOKEN_ERROR;
    goto final;
  }

state7:
  if ((i = char_pos(HEXDIGIT, tolower(c))) >= 0) {
    save_char(c);
    value = value * 0x10 + i;
    get_char();
    goto state7;
  } else {
    token = TOKEN_NUM;
    sprintf(lexvalue, "%d", value);
    goto final;
  }

state8:
  if ((i = char_pos(DIGIT, c)) >= 0) {
    save_char(c);
    value = value * 10 + i;
    get_char();
    goto state8;
  } else {
    token = TOKEN_NUM;
    sprintf(lexvalue, "%d", value);
    goto final;
  }

state9:
  if (c == '\\') {
    save_char(c);
    get_char();
    goto state10;
  } else if (c == '\"' || c == '\'') {
    save_char(c);
    get_char();
    token = TOKEN_ERROR;
    goto final;
  } else {
    save_char(c);
    value = c;
    get_char();
    goto state11;
  }

state10:
  if (c == 'n') {
    save_char(c);
    value = '\n';
    get_char();
    goto state11;
  } else if (c == 't') {
    save_char(c);
    value = '\t';
    get_char();
    goto state11;
  } else if (c == '0') {
    save_char(c);
    value = 0;
    get_char();
    goto state11;
  } else if (c == '\'') {
    save_char(c);
    value = '\'';
    get_char();
    goto state11;
  } else if (c == '\"') {
    save_char(c);
    value = '\"';
    get_char();
    goto state11;
  } else if (c == '\\') {
    save_char(c);
    value = '\\';
    get_char();
    goto state11;
  } else {
    token = TOKEN_ERROR;
    goto final;
  }

state11:
  if (c == '\'') {
    save_char(c);
    get_char();
    token = TOKEN_NUM;
    sprintf(lexvalue, "%d", value);
    goto final;
  } else {
    token = TOKEN_ERROR;
    goto final;
  }

state12:
  if (c == '=') {
    save_char(c);
    get_char();
    token = TOKEN_COLEQ;
    goto final;
  } else {
    token = TOKEN_COL;
    goto final;
  }

state13:
  if (c == '=') {
    save_char(c);
    get_char();
    token = TOKEN_LE;
    goto final;
  } else if (c == '>') {
    save_char(c);
    get_char();
    token = TOKEN_NE;
    goto final;
  } else if (c == '<') {
    save_char(c);
    get_char();
    token = TOKEN_SHIFTL;
    goto final;
  } else {
    token = TOKEN_LT;
    goto final;
  }

state14:
  if (c == '=') {
    save_char(c);
    get_char();
    token = TOKEN_GE;
    goto final;
  } else if (c == '<') {
    save_char(c);
    get_char();
    token = TOKEN_NE;
    goto final;
  } else if (c == '>') {
    save_char(c);
    get_char();
    token = TOKEN_SHIFTR;
    goto final;
  } else {
    token = TOKEN_GT;
    goto final;
  }

state15:
  if (c == '>') {
    save_char(c);
    get_char();
    token = TOKEN_GE;
    goto final;
  } else if (c == '<') {
    save_char(c);
    get_char();
    token = TOKEN_LE;
    goto final;
  } else {
    token = TOKEN_EQ;
    goto final;
  }

state16:
  if ((i = char_pos(BINDIGIT, tolower(c))) >= 0) {
    save_char(c);
    value = i;
    get_char();
    goto state17;
  } else {
    get_char();
    token = TOKEN_ERROR;
    goto final;
  }

state17:
  if ((i = char_pos(BINDIGIT, tolower(c))) >= 0) {
    save_char(c);
    value = value * 2 + i;
    get_char();
    goto state17;
  } else {
    token = TOKEN_NUM;
    sprintf(lexvalue, "%d", value);
    goto final;
  }

final:
  return;
}

void print_token()
{
	if (token == TOKEN_EOF) {
		fprintf(stdout, "EOF\n");
	} else if (token == TOKEN_ERROR) {
		fprintf(stdout, "ERROR\t[%s]\n", lexeme);
	} else if (token == TOKEN_ID) {
		fprintf(stdout, "ID\t[%s]\n", lexeme);
	} else if (token == TOKEN_NUM) {
		fprintf(stdout, "NUM\t[%s]\t[%s]\n", lexeme, lexvalue);
  } else if (token == TOKEN_COL) {
 		fprintf(stdout, "COL\t[%s]\n", lexeme);
  } else if (token == TOKEN_SEMICOL) {
 		fprintf(stdout, "SEMICOL\t[%s]\n", lexeme);
  } else if (token == TOKEN_COLEQ) {
 		fprintf(stdout, "COLEQ\t[%s]\n", lexeme);
  } else if (token == TOKEN_EQ) {
 		fprintf(stdout, "EQ\t[%s]\n", lexeme);
  } else if (token == TOKEN_NE) {
 		fprintf(stdout, "NE\t[%s]\n", lexeme);
  } else if (token == TOKEN_LT) {
 		fprintf(stdout, "LT\t[%s]\n", lexeme);
  } else if (token == TOKEN_LE) {
 		fprintf(stdout, "LE\t[%s]\n", lexeme);
  } else if (token == TOKEN_GT) {
 		fprintf(stdout, "GT\t[%s]\n", lexeme);
  } else if (token == TOKEN_GE) {
 		fprintf(stdout, "GE\t[%s]\n", lexeme);
  } else if (token == TOKEN_LPAR) {
 		fprintf(stdout, "LPAR\t[%s]\n", lexeme);
  } else if (token == TOKEN_RPAR) {
 		fprintf(stdout, "RPAR\t[%s]\n", lexeme);
  } else if (token == TOKEN_PLUS) {
 		fprintf(stdout, "PLUS\t[%s]\n", lexeme);
  } else if (token == TOKEN_MINUS) {
 		fprintf(stdout, "MINUS\t[%s]\n", lexeme);
  } else if (token == TOKEN_ASTER) {
 		fprintf(stdout, "ASTER\t[%s]\n", lexeme);
  } else if (token == TOKEN_SLASH) {
 		fprintf(stdout, "SLASH\t[%s]\n", lexeme);
  } else if (token == TOKEN_IF) {
    fprintf(stdout, "IF\t[%s]\n", lexeme);
  } else if (token == TOKEN_THEN) {
    fprintf(stdout, "THEN\t[%s]\n", lexeme);
  } else if (token == TOKEN_ELSE) {
    fprintf(stdout, "ELSE\t[%s]\n", lexeme);
  } else if (token == TOKEN_WHILE) {
    fprintf(stdout, "WHILE\t[%s]\n", lexeme);
  } else if (token == TOKEN_DO) {
    fprintf(stdout, "DO\t[%s]\n", lexeme);
  } else if (token == TOKEN_REPEAT) {
    fprintf(stdout, "REPEAT\t[%s]\n", lexeme);
  } else if (token == TOKEN_UNTIL) {
    fprintf(stdout, "UNTIL\t[%s]\n", lexeme);
  } else if (token == TOKEN_GOTO) {
    fprintf(stdout, "GOTO\t[%s]\n", lexeme);
  } else if (token == TOKEN_BEGIN) {
    fprintf(stdout, "BEGIN\t[%s]\n", lexeme);
  } else if (token == TOKEN_END) {
    fprintf(stdout, "END\t[%s]\n", lexeme);
  } else if (token == TOKEN_LONG) {
    fprintf(stdout, "LONG\t[%s]\n", lexeme);
  } else if (token == TOKEN_WORD) {
    fprintf(stdout, "WORD\t[%s]\n", lexeme);
  } else if (token == TOKEN_BYTE) {
    fprintf(stdout, "BYTE\t[%s]\n", lexeme);
  } else if (token == TOKEN_AND) {
    fprintf(stdout, "AND\t[%s]\n", lexeme);
  } else if (token == TOKEN_OR) {
    fprintf(stdout, "OR\t[%s]\n", lexeme);
  } else if (token == TOKEN_NOT) {
    fprintf(stdout, "NOT\t[%s]\n", lexeme);
  } else if (token == TOKEN_FUNCTION) {
    fprintf(stdout, "FUNCTION\t[%s]\n", lexeme);
  } else if (token == TOKEN_RETURN) {
    fprintf(stdout, "RETURN\t[%s]\n", lexeme);
  } else if (token == TOKEN_COMMA) {
    fprintf(stdout, "COMMA\t[%s]\n", lexeme);
  } else if (token == TOKEN_PERCENT) {
    fprintf(stdout, "PERCENT\t[%s]\n", lexeme);
  } else {
    fprintf(stdout, "print_token: Unknown token.\n");
  }
}

void convert(FILE *in, FILE *out)
{
	lexin = in;
	lexout = out;
  setup_keywords();
	get_char();
	get_token();
  parse();
	while (token != TOKEN_EOF) {
    error(ERROR_SYNTAX, lexeme, lineno);
	}
}
