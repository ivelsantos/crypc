CC=clang
CFLAGS=-Wall

main: main.c
	$(CC) $(CFLAGS) main.c subscipher.c
