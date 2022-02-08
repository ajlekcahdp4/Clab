all: MakeTex

MakeTex: Graph main writetex.o
	gcc main.o writetex.o -o MakeTex.out
	./MakeTex.out
Graph:
	gcc  topy.c mnk/mnk.c -lm -o topy.out
	./topy.out
	python3 main.py
main:
	gcc -c main.c 
mnk:
	gcc -c mnk/mnk.c
writetex.o:
	gcc -c writetex/writetex.c
clean:
	rm -rf *.o *.out *.tex *.zip data.txt graph.png 


