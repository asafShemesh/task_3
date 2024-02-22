all: StrList

StrList: StrList.o Main.o
	gcc -Wall -g StrList.o Main.o -o StrList

Main.o: Main.c StrList.h
	gcc -Wall -g -c Main.c

StrList.o: StrList.c StrList.h
	gcc -Wall -g -c StrList.c

clean:
	rm -f *.o StrList

.PHONY: clean all
