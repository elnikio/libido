#!/bin/bash
gcc -o arithmetic.o -c arithmetic.c -g
gcc -o list.o -c list.c -g
gcc -o matrix.o -c matrix.c -g
gcc -o search.o -c search.c -g
gcc -o string.o -c string.c -g
gcc -o vector.o -c vector.c -g
gcc -o generic.o -c generic.c -g
gcc -o logic.o -c logic.c -g
gcc -o colors.o -c colors.c -g
gcc -o plot.o -c plot.c -g
gcc -o plot_templates.o -c plot_templates.c -g
gcc -shared -o libido.so arithmetic.o list.o matrix.o search.o string.o vector.o generic.o logic.o colors.o plot.o plot_templates.o -g -no-pie -lm -lncurses -pthread
ar -cvq libido.a *.o
q - arithmetic.o
q - list.o
q - matrix.o
q - search.o
q - string.o
q - vector.o
q - generic.o
q - logic.o
q - colors.o
q - plot.o
q - plot_templates.o
