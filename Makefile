

all:
	gcc main.c -o clinic -lncurses
	./clinic
	rm ./clinic

	