#test_graphics: test_graphics.o graphics.o
	#gcc -Wall -std=c11 -o bin/test_graphics \
		#obj/test_graphics.o obj/graphics.o

test_graphics: test/test_graphics.c src/graphics.c
	gcc -Wall -std=c11 -o bin/test_graphics test/test_graphics.c -lm

graphics.o: src/graphics.c inc/graphics.h
	gcc -Wall -std=c11 -c -o obj/graphics.c src/graphics.c -lm
