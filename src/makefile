
libido.a: libido.so
	ar -cvq libido.a *.o

#plot: ./src/plot.c
#	gcc ./src/plot.c src/string.c src/vector.c -g -lido -lm -lncurses -o a.out

arithmetic: arithmetic.c
	gcc -o arithmetic.o -c arithmetic.c -g

list: list.c
	gcc -o list.o -c list.c -g

matrix: matrix.c
	gcc -o matrix.o -c matrix.c -g

search: search.c
	gcc -o search.o -c search.c -g

string: string.c
	gcc -o string.o -c string.c -g

vector: vector.c
	gcc -o vector.o -c vector.c -g

generic: generic.c
	gcc -o generic.o -c generic.c -g

logic: logic.c
	gcc -o logic.o -c logic.c -g

plot: plot.c
	gcc -o plot.o -c plot.c -g

libido.so: arithmetic.o list.o matrix.o search.o string.o vector.o generic.o logic.o plot.o
	gcc -shared -o libido.so arithmetic.o list.o matrix.o search.o string.o vector.o generic.o logic.o plot.o -g

