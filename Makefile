warchest: warchest.o graphics.o putty.o
	gcc -Wall -O2 -std=c11 -lm -o bin/warchest \
	obj/warchest.o obj/graphics.o obj/putty.o

warchest.o: src/warchest.c inc/graphics.h inc/game_types.h inc/window.h
	gcc -Wall -O2 -std=c11 -c -o obj/warchest.o src/warchest.c

graphics.o: src/graphics.c inc/graphics.h inc/window.h
	gcc -Wall -O2 -std=c11 -c -o obj/graphics.o src/graphics.c

putty.o: src/putty.c inc/window.h
	gcc -Wall -O2 -std=c11 -c -o obj/putty.o src/putty.c
