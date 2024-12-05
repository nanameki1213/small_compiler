#include <stdio.h>
#include <string.h>
#include "sc.h"

static FILE *codein;
static FILE *codeout;

static int idle_sp = -1;
static char *idle[BUFSIZ];

static int inuse_sp = -1;
static char *inuse[BUFSIZ];

extern int m_option;

void push_idle(char *r)
{
  idle[++idle_sp] = r;
}

char *pop_idle()
{
  char *r;

  if (idle_sp >= 0) {
    r = idle[idle_sp--];
  } else {
    r = NULL;
    error(ERROR_INTERNAL, "pop_idle", 0);
  }

  return r;
}

void push_inuse(char *r)
{
  inuse[++inuse_sp] = r;
}

char *pop_inuse()
{
  char *r;

  if (inuse_sp >= 0) {
    r = inuse[inuse_sp--];
  } else {
    r = NULL;
    error(ERROR_INTERNAL, "pop_inuse", 0);
  }

  return r;
}

void encode(char *op, char *opr)
{
  if (m_option == 1) {
    fprintf(codeout, "; %-16s\t%s\n", op, opr);
  }
  int current_id;
  if (strcmp(op, "start") == 0) {
    fprintf(codeout, "\t\t.cpu\t\t300HA\n");
    fprintf(codeout, "\t\t.section\tA,code,locate=H'000000\n");
    fprintf(codeout, "\t\t.data.l\t\treset\n");
    fprintf(codeout, "\t\t.section\tB,code,locate=H'000100\n");
    fprintf(codeout, "reset:\t\tmov.l\t\t#H'FFFF10,ER7\n");
    fprintf(codeout, "\t\tbra\t\t%s\n", opr);
  } else if (strcmp(op, "end") == 0) {
    fprintf(codeout, "\t\tbra\t\t$\n");
    encode_constants(codeout);
    fprintf(codeout, "\t\t.section\tC,data,locate=H'FFBF20\n");
    encode_symbols(codeout);
    fprintf(codeout, "\t\t.end\n");
  } else if (strcmp(op, "label") == 0) {
    fprintf(codeout, "%s\t\t.equ\t\t$\n", opr);
  } else if (strcmp(op, "load_num") == 0) {
    enter_constants(opr);
  } else if (strcmp(op, "var_long") == 0) {
    current_id = enter_symbols(opr, TYPE_LONG);
  } else if (strcmp(op, "var_word") == 0) {
    current_id = enter_symbols(opr, TYPE_WORD);
  } else if (strcmp(op, "var_byte") == 0) {
    current_id = enter_symbols(opr, TYPE_BYTE);
  } else if (strcmp(op, "set_address") == 0) {
    if (current_id == UNDEFINED) {
      error(ERROR_INTERNAL, "encode:  set_address", 0);
      return;
    }
    symbols[current_id].offset = atoi(opr);
    fprintf(codeout, "%s\t\t.equ\t\tH'%08X\n",
            symbols[current_id].label, atoi(opr));
  } else {
    ;
  }
}

void convert2(FILE *in, FILE *out)
{
  char op[BUFSIZ];
  char opr[BUFSIZ];

  codein = in;
  codeout = out;
  setup_constants();
  setup_symbols();
  while (fscanf(codein, "%s %s", op, opr) != EOF) {
    encode(op, opr);
  }
}

char *ER2R(char *er)
{
  char *r;

  if (strcmp(er, "ER0") == 0) {
    r = "R0";
  } else if (strcmp(er, "ER1") == 0) {
    r = "R1";
  } else if (strcmp(er, "ER2") == 0) {
    r = "R2";
  } else if (strcmp(er, "ER3") == 0) {
    r = "R3";
  } else if (strcmp(er, "ER4") == 0) {
    r = "R4";
  } else if (strcmp(er, "ER5") == 0) {
    r = "R5";
  } else if (strcmp(er, "ER6") == 0) {
    r = "R6";
  } else if (strcmp(er, "ER7") == 0) {
    r = "R7";
  } else {
    error(ERROR_INTERNAL, "ER2R", 0);
    r = NULL;
  }

  return r;
}

char *ER2RL(char *er)
{
  char *rl;

  if (strcmp(er, "ER0") == 0) {
    rl = "R0L";
  } else if (strcmp(er, "ER1") == 0) {
    rl = "R1L";
  } else if (strcmp(er, "ER2") == 0) {
    rl = "R2L";
  } else if (strcmp(er, "ER3") == 0) {
    rl = "R3L";
  } else if (strcmp(er, "ER4") == 0) {
    rl = "R4L";
  } else if (strcmp(er, "ER5") == 0) {
    rl = "R5L";
  } else if (strcmp(er, "ER6") == 0) {
    rl = "R6L";
  } else if (strcmp(er, "ER7") == 0) {
    rl = "R7L";
  } else {
    error(ERROR_INTERNAL, "ER2R", 0);
    rl = NULL;
  }

  return rl;
}
