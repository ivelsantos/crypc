CC=gcc
CFLAGS=-Wall

main: main.c
	$(CC) $(CFLAGS) main.c subscipher.c

clean:
	rm out.txt dout.txt
