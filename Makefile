build: main.c
	gcc -o fsminishell main.c list.c
run: 
	./fsminishell

clean:
	rm fsminishell
