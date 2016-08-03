matrix.o: matrix.c matrix.h
	gcc matrix.c -Wall -pedantic -c
clean:
	rm *.o
