CFLAGS= -g -Wall -Wextra -fsanitize=address

test.exe : test.o tree.o io.o heap.o stack.o huffman.o
	gcc ${CFLAGS} -o test.exe test.o tree.o io.o heap.o stack.o huffman.o

tree.o : tree.c
	gcc ${CFLAGS} -c -o tree.o tree.c

io.o : io.c
	gcc ${CFLAGS} -c -o io.o io.c

heap.o : heap.c
	gcc ${CFLAGS} -c -o heap.o heap.c

stack.o : stack.c
	gcc ${CFLAGS} -c -o stack.o stack.c

huffman.o : huffman.c
	gcc ${CFLAGS} -c -o huffman.o huffman.c

test.o : test.c
	gcc ${CFLAGS} -c -o test.o test.c
clean :
	rm *.o test.exe
