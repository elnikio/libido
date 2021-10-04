#!/bin/bash
gcc -o arithmetic.o -c arithmetic.c -g
gcc -o list.o -c list.c -g
gcc -o matrix.o -c matrix.c -g
gcc -o search.o -c search.c -g
gcc -o string.o -c string.c -g
gcc -o vector.o -c vector.c -g
gcc -o generic.o -c generic.c -g
gcc -o logic.o -c logic.c -g
gcc -o set.o -c set.c -g
gcc -o plot.o -c plot.c -g
gcc -shared -o libido.so arithmetic.o list.o matrix.o search.o string.o vector.o generic.o logic.o set.o plot.o -g
ar -cvq libido.a *.o
q - arithmetic.o
q - list.o
q - matrix.o
q - search.o
q - string.o
q - vector.o
q - generic.o
q - logic.o
q - set.o
q - plot.o
