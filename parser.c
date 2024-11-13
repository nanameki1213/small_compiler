#include "sc.h"

void parse_factor();
void parse_term();
void parse_polynomial();
void parse_expression();

void parser_factor()
{
  if (token == TOKEN_ID) {
    gen_code("load_id", lexeme);
    get_token();
  } else if (token == TOKEN_NUM) {
    gen_code("load_num", lexvalue);
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
    parser_factor();
    gen_code("not", "-");
  } else {
    error(ERROR_SYNTAX, lexeme, lineno);
  }
}

void parse_term()
{
  parser_factor();
  while (1) {
    if (token == TOKEN_ASTER) {
      get_token();
      parser_factor();
      gen_code("mul", "-");
    } else if (token == TOKEN_SLASH) {
      get_token();
      parser_factor();
      gen_code("div", "-");
    } else if (token == TOKEN_AND) {
      get_token();
      parser_factor();
      gen_code("and", "-");
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
    gen_code("neg", "-");
  } else {
    parse_term();
  }
  while (1) {
    if (token == TOKEN_PLUS) {
      get_token();
      parse_term();
      gen_code("add", "-");
    } else if (token == TOKEN_MINUS) {
      get_token();
      parse_term();
      gen_code("sub", "-");
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
    gen_code("eq", "-");
  } else if (token == TOKEN_NE) {
    get_token();
    parse_polynomial();
    gen_code("ne", "-");
  } else if (token == TOKEN_LT) {
    get_token();
    parse_polynomial();
    gen_code("lt", "-");
  } else if (token == TOKEN_LE) {
    get_token();
    parse_polynomial();
    gen_code("le", "-");
  } else if (token == TOKEN_GT) {
    get_token();
    parse_polynomial();
    gen_code("gt", "-");
  } else if (token == TOKEN_GE) {
    get_token();
    parse_polynomial();
    gen_code("ge", "-");
  } else {
    return;
  }
}

void parse_statement()
{
  if (token == TOKEN_ID) {
    get_token();
    if (token == TOKEN_COLEQ) {
      get_token();
      parse_expression();
    } else if (token == TOKEN_COL) {
      get_token();
      parse_statement();
    } else {
      error(ERROR_SYNTAX, lexeme, lineno);
    }
  } else if (token == TOKEN_IF) {
    get_token();
    parse_expression();
    if (token == TOKEN_THEN) {
      get_token();
      parse_statement();
      if (token == TOKEN_ELSE) {
        get_token();
        parse_statement();
      } else {
        ;
      }
    }
  } else if (token == TOKEN_WHILE) {
    get_token();
    parse_expression();
    if (token == TOKEN_DO) {
      get_token();
      parse_statement();
    } else {
      error(ERROR_SYNTAX, lexeme, lineno);
    }
  } else if (token == TOKEN_REPEAT) {
    get_token();
    parse_expression();
    if (token == TOKEN_UNTIL) {
      get_token();
      parse_expression();
    } else {
      error(ERROR_SYNTAX, lexeme, lineno);
    }
  } else if (token == TOKEN_GOTO) {
    get_token();
    if (token == TOKEN_ID) {
      get_token();
    } else {
      error(ERROR_SYNTAX, lexeme, lineno);
    }
  } else if (token == TOKEN_BEGIN) {
    get_token();
    parse_statement();
    while (token == TOKEN_SEMICOL) {
      get_token();
      parse_statement();
    }
    if (token == TOKEN_END) {
      get_token();
    }
  } else {
    error(ERROR_SYNTAX, lexeme, lineno); 
  }
}

void parse()
{
  parse_expression();
}
