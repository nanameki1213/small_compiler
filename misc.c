#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "sc.h"

int char_pos(char *s, char c)
{
	int i;

	for (i = 0; i < s[i] != '\0'; i++) {
		if (s[i] == c) {
			return i;
		}
	}
	return -1;
}

void error(int type, char *hint)
{
	if (type == ERROR_OVERFLOW) {
		fprintf(stderr, "[%s] overflowed.\n", hint);
	} else {
		fprintf(stderr, "error: Unknown error.\n");
	}
}
