objs = coin.o ds.o game.o hex.o history.o move.o player.o warchest.o
objs_dir = obj/coin.o obj/ds.o obj/game.o obj/hex.o obj/history.o \
	   obj/move.o obj/player.o obj/warchest.o 

warchest: $(objs)
	gcc -Wall -O2 -std=c11 -o bin/warchest $(objs_dir)

coin.o: src/coin.c inc/coin.h
	gcc -Wall -O2 -std=c11 -c -o obj/coin.o src/coin.c

ds.o: src/ds.c inc/ds.h
	gcc -Wall -O2 -std=c11 -c -o obj/ds.o src/ds.c

game.o: src/game.c inc/game.h inc/types.h
	gcc -Wall -O2 -std=c11 -c -o obj/game.o src/game.c

hex.o: src/hex.c inc/ds.h inc/hex.h inc/types.h
	gcc -Wall -O2 -std=c11 -c -o obj/hex.o src/hex.c

history.o: src/history.c inc/ds.h inc/history.h inc/types.h
	gcc -Wall -O2 -std=c11 -c -o obj/history.o src/history.c

move.o: src/move.c inc/coin.h inc/game.h inc/move.h inc/player.h inc/types.h
	gcc -Wall -O2 -std=c11 -c -o obj/move.o src/move.c

player.o: src/player.c inc/ds.h inc/player.h inc/types.h
	gcc -Wall -O2 -std=c11 -c -o obj/player.o src/player.c

warchest.o: src/warchest.c inc/game_types.h
	gcc -Wall -O2 -std=c11 -c -o obj/warchest.o src/warchest.c

test_ds: src/ds.c inc/ds.h
	gcc -D TESTDS -Wall -O2 -std=c11 -o bin/test_ds src/ds.c

clean:
	rm ./obj/* ./bin/*
