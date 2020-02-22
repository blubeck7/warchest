warchest: warchest.o
	gcc -Wall -O2 -std=c11 -o bin/warchest obj/warchest.o -lm

warchest.o: src/warchest.c inc/game_types.h
	gcc -Wall -O2 -std=c11 -c -o obj/warchest.o src/warchest.c

ds: ds.o
	gcc -Wall -O2 -std=c11 -o bin/ds obj/ds.o -lm

ds.o: src/ds.c inc/ds.h
	gcc -Wall -O2 -std=c11 -c -o obj/ds.o src/ds.c

test_coinqueue: coinqueue.o coin.o inc/coinqueue.h inc/coin.h
	gcc -Wall -O2 -std=c11 -o bin/test_coinqueue obj/coinqueue.o \
		obj/coin.o test/test_coinqueue.c

coinqueue.o: src/coinqueue.c inc/coinqueue.h
	gcc -Wall -O2 -std=c11 -c -o obj/coinqueue.o src/coinqueue.c

coin.o: src/coin.c inc/coin.h
	gcc -Wall -O2 -std=c11 -c -o obj/coin.o src/coin.c

game.o: src/game.c inc/game.h inc/types.h
	gcc -Wall -O2 -std=c11 -c -o obj/game.o src/game.c

clean:
	rm ./obj/* ./bin/*
