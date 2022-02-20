CC = gcc
all: MakeTex

MakeTex: Graph main writetex.o
	$(CC) main.o writetex.o -o MakeTex.out
	./MakeTex.out
Graph:
	$(CC)  topy.c mnk/mnk.c -lm -o topy.out
	./topy.out
	python3 main.py
main:
	$(CC) -c main.c 
mnk:
	$(CC) -c mnk/mnk.c
writetex.o:
	$(CC) -c writetex/writetex.c
clean:
	rm -rf *.o *.out *.tex *.zip data.txt graph.png graph.eps