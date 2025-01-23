#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "sc.h"

int m_option;

int main(int argc, char *argv[])
{
	FILE *in;
	FILE *out;
  FILE *tmp;

  // オプションの解析
  out = stdout;
  m_option = 0;
  int c;
  while ((c = getopt(argc, argv, "mo:")) != -1) {
    switch (c) {
      case 'm':
        m_option = 1;
        break;
      case 'o':
        if ((out = fopen(optarg, "w")) == NULL) {
          perror("fopen out_file");
          exit(1);
        }
        break;
    }
  }
  
  if (optind < argc) {
    if ((in = fopen(argv[optind], "r")) == NULL) {
      perror("fopen in_file");
      exit(1);
    }
    optind += 1;
  } else {
    fprintf(stderr, "use: %s [-m] in_file [out_file]\n", argv[0]);
    exit(1);
  }

  if ((tmp = tmpfile()) == NULL) {
    perror("fopen for tmpfile");
    exit(1);
  }

	convert(in, tmp);
  fflush(tmp);
  rewind(tmp);
  convert2(tmp, out);

	fclose(in);
	fclose(out);
  fclose(tmp);
	return 0;
}
