#!/bin/bash
#gcc main.c /usr/include/libido/libido.a -lGL -lGLU -lGLEW -lglut -lm -g -Wall
#gcc doctor.c arithmetic.c generic.c plot.c set.c vector.c string.c -lGL -lGLU -lGLEW -lglut -lm -g -Wall
sudo gcc plot.c string.c vector.c -g -lido -lm -lncurses -pthread
