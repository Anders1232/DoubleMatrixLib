flags= -Wall -pedantic -c

matrix.o: matrix.c matrix.h
	gcc matrix.c $(flags)
clear:
	rm -r *.o
all:
	rm -r *.o
	gcc matrix.c $(flags)
c90:
	gcc matrix.c $(flags) -std=c90
c99:
	gcc matrix.c $(flags) -std=c99
c11:
	gcc matrix.c $(flags) -std=c11

