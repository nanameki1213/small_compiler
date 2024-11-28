#include "sc.h"
#include <stdatomic.h>
#include <string.h>

extern FILE *lexout;

void parse_factor();
void parse_term();
void parse_polynomial();
void parse_expression();

void parse_factor()
{
  if (token == TOKEN_ID) {
    char *id = strdup(lexeme);
    get_token();
    if (token == TOKEN_LPAR) {
      get_token();
      parse_expression();
      while (token == TOKEN_COMMA) {
        get_token();
        parse_expression();
      }
      if (token != TOKEN_RPAR) {
        error(ERROR_SYNTAX, lexeme, lineno);
      }
      get_token();

      fprintf(lexout, "%s ", id);
    } else if (token == TOKEN_LSQR) {
      get_token();
      fprintf(lexout, "&%s ", id);
      parse_expression();
      if (token == TOKEN_RSQR) {
        get_token();
      } else {
        error(ERROR_SYNTAX, lexeme, lineno);
      }
      fprintf(lexout, "# ");
    } else {
      fprintf(lexout, "%s ", lexeme);
    }


    // gen_code("load_id", lexeme);
  } else if (token == TOKEN_NUM) {
    // gen_code("load_num", lexvalue);
    fprintf(lexout, "%s ", lexvalue);
    get_token();
  } else if (token == TOKEN_LPAR) {
    get_token();
    parse_expression();
    if (token == TOKEN_RPAR) {
      get_token();
    } else {
      error(ERROR_SYNTAX, lexeme, lineno);
    }
  } else if (token == TOKEN_NOT) {
    get_token();
    parse_factor();
    fprintf(lexout, "not ");
  } else {
    error(ERROR_SYNTAX, lexeme, lineno);
  }
}

void parse_term()
{
  parse_factor();
  while (1) {
    if (token == TOKEN_ASTER) {
      get_token();
      parse_factor();
      fprintf(lexout, "* ");
    } else if (token == TOKEN_SLASH) {
      get_token();
      parse_factor();
      fprintf(lexout, "/ ");
    } else if (token == TOKEN_AND) {
      get_token();
      parse_factor();
      fprintf(lexout, "and ");
    } else {
      break;
    }
  }
}

void parse_polynomial()
{
  if (token == TOKEN_PLUS) {
    get_token();
    parse_term();
  } else if (token == TOKEN_MINUS) {
    get_token();
    parse_term();
    fprintf(lexout, "- ");
  } else {
    parse_term();
  }
  while (1) {
    if (token == TOKEN_PLUS) {
      get_token();
      parse_term();
      fprintf(lexout, "+ ");
    } else if (token == TOKEN_MINUS) {
      get_token();
      parse_term();
      fprintf(lexout, "- ");
    } else if (token == TOKEN_OR) {
      get_token();
      parse_term();
      gen_code("or", "-");
    } else {
      break;
    }
  }
}

void parse_expression()
{
  parse_polynomial();
  if (token == TOKEN_EQ) {
    get_token();
    parse_polynomial();
    // gen_code("eq", "-");
    fprintf(lexout, "= ");
  } else if (token == TOKEN_NE) {
    get_token();
    parse_polynomial();
    // gen_code("ne", "-");
    fprintf(lexout, "<> ");
  } else if (token == TOKEN_LT) {
    get_token();
    parse_polynomial();
    // gen_code("lt", "-");
    fprintf(lexout, "< ");
  } else if (token == TOKEN_LE) {
    get_token();
    parse_polynomial();
    // gen_code("le", "-");
    fprintf(lexout, "<=");
  } else if (token == TOKEN_GT) {
    get_token();
    parse_polynomial();
    // gen_code("gt", "-");
    fprintf(lexout, "> ");
  } else if (token == TOKEN_GE) {
    get_token();
    parse_polynomial();
    // gen_code("ge", "-");
    fprintf(lexout, "<=");
  } else {
    return;
  }
}

void parse()
{
  parse_expression();
}
