sc	:	parser.o scanner.o main.o keywords.o constants.o symbols.o encoder.o misc.o
	gcc -o sc parser.o scanner.o main.o keywords.o constants.o symbols.o \
		encoder.o misc.o -ll
parser.o	:	parser.y	sc.h
	yacc	-vd	parser.y
	mv	y.tab.c	parser.c
	mv	y.tab.h	parser.h
	gcc -Wno-implicit-function-declaration -c parser.c
scanner.o : scanner.l parser.h sc.h
	lex scanner.l
	mv lex.yy.c scanner.c
	gcc -Wno-implicit-function-declaration -c scanner.c
main.o : main.c sc.h
	gcc -Wall -c main.c
keywords.o : keywords.c parser.h sc.h
	gcc -Wall -c keywords.c
constants.o : constants.c sc.h
	gcc -Wall -c constants.c
symbols.o : symbols.c sc.h
	gcc -Wall -c symbols.c
encoder.o : encoder.c sc.h
	gcc -Wall -c encoder.c
misc.o : misc.c sc.h
	gcc -Wall -c misc.c
clean :
	rm parser.c parser.h scanner.c y.output y.tab.h y.tab.c lex.yy.c sc *.o *.core
