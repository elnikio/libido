
examples: spiral.c pendulum.c spiralDDA.c
	gcc spiral.c -g -lido -o spiral -Wall -L/usr/include/libido -lm -lncurses -pthread
	gcc spiralDDA.c -g -lido -o spiralDDA -Wall -L/usr/include/libido -lm -lncurses -pthread
	gcc pendulum.c -g -lido -lm -o pendulum -L/usr/include/libido -pthread -lncurses -Wall
	gcc colortest.c -g -lido -lm -o colortest -L/usr/include/libido -pthread -lncurses -Wall

spiral: spiral.c
	gcc spiral.c -g -lido -o spiral -Wall -L/usr/include/libido -lm -lncurses -pthread

spiralDDA: spiralDDA.c
	gcc spiralDDA.c -g -lido -o spiralDDA -Wall -L/usr/include/libido -lm -lncurses -pthread

pendulum: pendulum.c
	gcc pendulum.c -g -lido -lm -o pendulum -L/usr/include/libido -pthread -lncurses -Wall

linetest: linetest.c
	gcc linetest.c -g -lido -lm -o linetest -L/usr/include/libido -pthread -lncurses -Wall

colortest: colortest.c
	gcc colortest.c -g -lido -lm -o colortest -L/usr/include/libido -pthread -lncurses -Wall
