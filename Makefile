#-*-MakeFile-*-


CC=gcc
FLAGS= -g -Wall


all: frequency

frequency: main.o Trie.o 
	$(CC) $(FLAGS) -fPIC -o frequency main.o Trie.o 

main.o: main.c Trie.h
	$(CC) $(FLAGS) -c main.c

Trie.o: Trie.c Trie.h
	$(CC) $(FLAGS) -c Trie.c


.PHONY: clean all 

clean:
	rm -f *.o frequency
