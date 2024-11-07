calc	:	main.o scanner.o keywords.o misc.o parser.o
	gcc -o calc main.o scanner.o keywords.o misc.o parser.o

main.o	:	main.c sc.h
	gcc -c main.c
scanner.o	:	scanner.c	sc.h
	gcc -c scanner.c
keywords.o	:	keywords.c sc.h
	gcc -c keywords.c
misc.o	:	misc.c sc.h
	gcc -c misc.c
parser.o	:	parser.c	sc.h
	gcc -c parser.c
clean	:	
	rm calc *.o
wc	:	
	wc *.c
