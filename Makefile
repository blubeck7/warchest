warchest: warchest.o
	gcc -Wall -O2 -std=c11 -o bin/warchest obj/warchest.o -lm

warchest.o: src/warchest.c inc/game_types.h
	gcc -Wall -O2 -std=c11 -c -o obj/warchest.o src/warchest.c