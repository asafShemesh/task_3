all: Main

Main: StrList.o Main.o
	gcc -Wall StrList.o Main.o -o Main

Main.o: Main.c StrList.h
	gcc -Wall -c Main.c

StrList.o: StrList.c StrList.h
	gcc -Wall -c StrList.c

clean:
	rm -f *.o Main

.PHONY: clean all
