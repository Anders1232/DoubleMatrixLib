matrix.o: matrix.c matrix.h
	gcc matrix.c -Wall -pedantic -c
clear:
	rm -r *.o
all:
	rm -r *.o
	gcc matrix.c -Wall -pedantic -c
