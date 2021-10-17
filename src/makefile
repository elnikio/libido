libido.so: arithmetic.o list.o matrix.o search.o string.o vector.o generic.o logic.o plot.o plot_templates.o
	ar rc libido.a matrix.o string.o vector.o generic.o plot.o
	ranlib libido.a

#libido.a: libido.so
#	ar -cvq libido.a *.o

#plot: ./src/plot.c
#	gcc ./src/plot.c src/string.c src/vector.c -g -lido -lm -lncurses -o a.out

#arithmetic: arithmetic.c
#	gcc -o arithmetic.o -c arithmetic.c -g -fPIC -Wall

#list: list.c
#	gcc -o list.o -c list.c -g -fPIC -Wall

matrix: matrix.c
	gcc -o matrix.o -c matrix.c -g -fPIC -Wall

#search: search.c
#	gcc -o search.o -c search.c -g -fPIC -Wall

string: string.c
	gcc -o string.o -c string.c -g -fPIC -Wall

vector: vector.c
	gcc -o vector.o -c vector.c -g -fPIC -Wall -lm

generic: generic.c
	gcc -o generic.o -c generic.c -g -fPIC -Wall

#logic: logic.c
#	gcc -o logic.o -c logic.c -g -fPIC -Wall

plot: plot.c
	gcc -o plot.o -c plot.c -g -fPIC -Wall -lm -lncurses -pthread
