dungeon: main.o color.o
	gcc main.o color.o -o dungeon

dungeon.o: main.c color.h
	gcc -Wall -ansi -pedantic -g main.c -c

color.o: color.c color.h
	gcc -Wall -ansi -pedantic -g color.c -c

clean:
	rm dungeon main.o color.o