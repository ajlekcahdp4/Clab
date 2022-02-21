CC = gcc
all: MakeTex

MakeTex: Graph main writetex.o
	$(CC) -g main.o writetex.o -o MakeTex.out
	./MakeTex.out
Graph:
	$(CC) -g Data_calc.c mnk/mnk.c average/average.c -lm -o datacalc.out
	./datacalc.out
	python3 main.py
main:
	$(CC) -c -g main.c 
mnk:
	$(CC) -c -g mnk/mnk.c
writetex.o:
	$(CC) -c -g writetex/writetex.c
clean:
	rm -rf *.o *.out *.tex *.zip tex/* data/*.pdf data/average_values.txt data/data_mnk.txt