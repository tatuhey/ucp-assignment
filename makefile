dungeon: main.o color.o terminal.o
	gcc main.o color.o terminal.o -o dungeon

dungeon.o: main.c color.h terminal.h
	gcc -Wall -ansi -pedantic -g main.c -c

color.o: color.c color.h
	gcc -Wall -ansi -pedantic -g color.c -c

terminal.o: terminal.c terminal.h
	gcc -Wall -ansi -pedantic -g terminal.c -c

clean:
	rm dungeon main.o color.o terminal.o