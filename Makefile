SRC: stack.c main.c Unity/unity.c

a.out: $(SRC)
	gcc $^ -o $@

test: a.out
	./a.out

analyze: test
	cppcheck --enable=all *.c

memory_leak: test
	valgrind ./a.out

clear:
	clear                  