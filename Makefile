#test_graphics: test_graphics.o graphics.o
	#gcc -Wall -std=c11 -o bin/test_graphics \
		#obj/test_graphics.o obj/graphics.o

#graphics.o: src/graphics.c inc/graphics.h
	#gcc -Wall -std=c11 -c -o obj/graphics.c src/graphics.c -lm

putty_test: putty_test.o putty.o
	gcc -Wall -std=c11 -o bin/putty_test obj/putty_test.o obj/putty.o

graphics_test: graphics_test.o graphics.o putty.o
	gcc -Wall -std=c11 -o bin/graphics_test obj/graphics_test.o \
		obj/graphics.o obj/putty.o -lm

graphics_test.o: test/graphics_test.c inc/graphics.h inc/window.h
	gcc -Wall -std=c11 -c -o obj/graphics_test.o test/graphics_test.c

graphics.o: src/graphics.c inc/graphics.h inc/window.h
	gcc -Wall -std=c11 -c -o obj/graphics.o src/graphics.c -lm

putty_test.o: test/putty_test.c inc/window.h
	gcc -Wall -std=c11 -c -o obj/putty_test.o test/putty_test.c

putty.o: src/putty.c inc/window.h
	gcc -Wall -std=c11 -c -o obj/putty.o src/putty.c
