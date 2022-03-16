CC = gcc
CFLAGS = -Wall -Wextra -Werror -Walloc-zero -Walloca -Walloca-larger-than=8192 -Warray-bounds -Wcast-align -Wcast-qual		\
-Wchar-subscripts -Wconversion -Wdangling-else -Wduplicated-branches -Wempty-body -Wfloat-equal -Wformat-nonliteral			\
-Wformat-security -Wformat-signedness -Wformat=2 -Wformat-overflow=2 -Wformat-truncation=2 -Winline -Wlarger-than=8192		\
-Wvla-larger-than=8192 -Wlogical-op -Wopenmp-simd -Wpacked -Wpointer-arith -Wredundant-decls								\
-Wrestrict -Wshadow -Wstack-usage=8192 -Wstrict-overflow=2 -Wstringop-overflow=4 -Wsuggest-attribute=noreturn				\
-Wsuggest-final-types -Wswitch-default -Wswitch-enum -Wsync-nand -Wundef -Wunreachable-code -Wunused -Wvariadic-macros 		\
-Wno-missing-field-initializers -Wnarrowing -Wvarargs -fcheck-new -fstack-check -fstrict-overflow -flto-odr-type-merging 	\
-fchkp-first-field-has-own-bounds -fchkp-narrow-to-innermost-array

all: MakeTex

MakeTex: Graph main writetex.o
	$(CC) -g main.o writetex.o -o MakeTex.out
	./MakeTex.out
Graph: datacalc
	python3 main.py
Tex:
	$(CC) main.o writetex.o -o tex.out
	./tex.out
datacalc: mnkcalc averagecalc
	chmod +x bash_scripts/mkdir.sh
	./bash_scripts/mkdir.sh data
	$(CC) -g Data_Calc.c mnk.o average.o -o datacalc.out -lm
	./datacalc.out
averagecalc:
	$(CC) -g -c average/average.c
main:
	$(CC) -g -c main.c 
mnkcalc:
	$(CC) -g -c mnk/mnk.c
writetex.o:
	$(CC) -g -c writetex/writetex.c
clean:
	rm -rf *.o *.out *.tex *.zip data/*.pdf data/average_values.txt data/data_mnk.txt *.log *.aux *.pdf *.png