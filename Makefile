CC=gcc
CFLAGS=-Wall

output: main.o subscipher.o
	$(CC) main.o subscipher.o -o output

main.o: main.c
	$(CC) -c main.c

subscipher.o: subscipher.c subscipher.h
	$(CC) -c subscipher.c

clean:
	rm *.o output
