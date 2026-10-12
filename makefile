dungeon: main.o color.o terminal.o newSleep.o
	gcc main.o color.o terminal.o newSleep.o -o dungeon

dungeon.o: main.c color.h terminal.h
	gcc -Wall -ansi -pedantic -g main.c -c

color.o: color.c color.h
	gcc -Wall -ansi -pedantic -g color.c -c

terminal.o: terminal.c terminal.h
	gcc -Wall -ansi -pedantic -g terminal.c -c

newSleep.o: newSleep.c newSleep.h
	gcc -Wall -ansi -pedantic -g newSleep.c -c

clean:
	rm dungeon main.o color.o terminal.o newSleep.o