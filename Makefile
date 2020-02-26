warchest: warchest.o
	gcc -Wall -O2 -std=c11 -o bin/warchest obj/warchest.o -lm

warchest.o: src/warchest.c inc/game_types.h
	gcc -Wall -O2 -std=c11 -c -o obj/warchest.o src/warchest.c

test_ds: src/ds.c inc/ds.h
	gcc -D TESTDS -Wall -O2 -std=c11 -o bin/test_ds src/ds.c

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

hex.o: src/hex.c inc/ds.h inc/hex.h inc/types.h
	gcc -Wall -O2 -std=c11 -c -o obj/hex.o src/hex.c

move.o: src/move.c inc/coin.h inc/game.h inc/move.h inc/player.h inc/types.h
	gcc -Wall -O2 -std=c11 -c -o obj/move.o src/move.c

player.o: src/player.c inc/ds.h inc/player.h inc/types.h
	gcc -Wall -O2 -std=c11 -c -o obj/player.o src/player.c

clean:
	rm ./obj/* ./bin/*
