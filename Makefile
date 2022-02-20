CC = gcc
all: MakeTex

MakeTex: Graph main writetex.o
	$(CC) main.o writetex.o -o MakeTex.out
	./MakeTex.out
Graph:
	$(CC)  Data_calc.c mnk/mnk.c average/average.c -lm -o topy.out
	./topy.out
	python3 main.py
main:
	$(CC) -c main.c 
mnk:
	$(CC) -c mnk/mnk.c
writetex.o:
	$(CC) -c writetex/writetex.c
clean:
	rm -rf *.o *.out *.tex *.zip data_mnk.txt graph.eps average_values.txt