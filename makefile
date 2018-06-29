all:
	gcc *.c -Wall -Wextra -Werror -std=c99 -pedantic -g -o TP0
clean:
	rm -f TP0 TP0.o pilha.o lista.o


