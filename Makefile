
main: main.c
	gcc main.c src/string.c src/memory.c  && ./a.out

clean: 
	rm a.out

run: 
	make main && make clean