warchest: warchest.o
	gcc -Wall -O2 -std=c11 -o bin/warchest obj/warchest.o -lm

warchest.o: src/warchest.c inc/game_types.h
	gcc -Wall -O2 -std=c11 -c -o obj/warchest.o src/warchest.c

ds: ds.o
	gcc -Wall -O2 -std=c11 -o bin/ds obj/ds.o -lm

ds.o: src/ds.c inc/ds.h
	gcc -Wall -O2 -std=c11 -c -o obj/ds.o src/ds.c
