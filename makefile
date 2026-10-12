dungeon: main.o color.o terminal.o newSleep.o display.o transversal.o move.o
	gcc main.o color.o terminal.o newSleep.o display.o transversal.o move.o -o dungeon

dungeon.o: main.c color.h terminal.h
	gcc -Wall -ansi -pedantic -g main.c -c

color.o: color.c color.h
	gcc -Wall -ansi -pedantic -g color.c -c

terminal.o: terminal.c terminal.h
	gcc -Wall -ansi -pedantic -g terminal.c -c

newSleep.o: newSleep.c newSleep.h
	gcc -Wall -ansi -pedantic -g newSleep.c -c

display.o: display.c display.h
	gcc -Wall -ansi -pedantic -g display.c -c

transversal.o: transversal.c transversal.h
	gcc -Wall -ansi -pedantic -g transversal.c -c

move.o: move.c move.h
	gcc -Wall -ansi -pedantic -g move.c -c

clean:
	rm dungeon main.o color.o terminal.o newSleep.o display.o transversal.o move.o