CFLAGS = -c -g
CC = gcc

main : main.o hello.o add.o 
	$(CC) main.o hello.o add.o -o main
main.o : main.c
	$(CC) $(CFLAGS) main.c
hello.o: hello.c
	$(CC) $(CFLAGS) hello.c
add.o : add.c
	$(CC) $(CFLAGS) add.c

clean :
	rm *.o main

