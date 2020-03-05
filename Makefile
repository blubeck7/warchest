objs = coin.o ds.o game.o graphics.o hex.o history.o player.o putty.o \
       warchest.o
objs_dir = obj/coin.o obj/ds.o obj/game.o obj/graphics.o obj/hex.o \
	   obj/history.o obj/player.o obj/putty.o obj/warchest.o 
inc_dir = inc/coin.h inc/ds.h inc/game.h inc/graphics.h inc/hex.h \
	  inc/history.h inc/player.h inc/warchest.h inc/window.h

warchest: $(objs)
	gcc -Wall -O2 -std=c11 -o bin/warchest $(objs_dir) -lm

coin.o: src/coin.c $(inc_dir)
	gcc -Wall -O2 -std=c11 -c -o obj/coin.o src/coin.c

ds.o: src/ds.c $(inc_dir)
	gcc -Wall -O2 -std=c11 -c -o obj/ds.o src/ds.c

game.o: src/game.c $(inc_dir)
	gcc -Wall -O2 -std=c11 -c -o obj/game.o src/game.c

graphics.o: src/graphics.c inc/graphics.h inc/window.h
	gcc -Wall -O2 -std=c11 -c -o obj/graphics.o src/graphics.c

hex.o: src/hex.c $(inc_dir)
	gcc -Wall -O2 -std=c11 -c -o obj/hex.o src/hex.c

history.o: src/history.c $(inc_dir)
	gcc -Wall -O2 -std=c11 -c -o obj/history.o src/history.c

#move.o: src/move.c $(inc_dir)
	#gcc -Wall -O2 -std=c11 -c -o obj/move.o src/move.c

player.o: src/player.c $(inc_dir)
	gcc -Wall -O2 -std=c11 -c -o obj/player.o src/player.c

putty.o: src/putty.c inc/window.h
	gcc -Wall -O2 -std=c11 -c -o obj/putty.o src/putty.c

warchest.o: src/warchest.c $(inc_dir)
ifeq ($(debug),0)
	gcc -Wall -O2 -std=c11 -c -o obj/warchest.o src/warchest.c
else
	gcc -D DEBUG_WARCHEST -Wall -O2 -std=c11 -c -o obj/warchest.o src/warchest.c
endif

test_ds: src/ds.c inc/ds.h
	gcc -D TESTDS -Wall -O2 -std=c11 -o bin/test_ds src/ds.c

clean:
	rm ./obj/* ./bin/*
