compile: signals.c
	gcc signals.c

run: compile
	./a.out

clean:
	rm *.c~
