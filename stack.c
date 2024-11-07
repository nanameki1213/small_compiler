#include "sc.h"

int sp = -1;
int stack[MAX_OPERANDS];

void push(int x)
{
  if (sp < MAX_OPERANDS) {
    stack[++sp] = x;
  } else {
    error(ERROR_OVERFLOW, "push", 0);
  }
}

int pop()
{
  int x;
  if (sp >= 0) {
    x = stack[sp--];
  } else {
    x = 0;
    error(ERROR_INTERNAL, "pop", 0);
  }

  return x;
}
