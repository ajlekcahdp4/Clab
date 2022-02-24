CC = gcc
all: MakeTex

MakeTex: Graph main writetex.o
	$(CC) main.o writetex.o -o MakeTex.out
	./MakeTex.out
Graph: datacalc
	python3 main.py
datacalc: mnkcalc averagecalc
	$(CC) Data_calc.c mnk.o average.o -o datacalc.out -lm
	./datacalc.out
averagecalc:
	$(CC) -c average/average.c
main:
	$(CC) -c main.c 
mnkcalc:
	$(CC) -c mnk/mnk.c
writetex.o:
	$(CC) -c writetex/writetex.c
clean:
	rm -rf *.o *.out *.tex *.zip data/*.pdf data/average_values.txt data/data_mnk.txt *.log *.aux *.pdf