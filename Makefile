CC=gcc
CFLAGS=-g -Wall -lm
OBJ1= pgmnega.o openimg.o
OBJ = pgmmediana.o openimg.o

%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS) 

all: nega

nega: $(OBJ1)

	$(CC) -o $@ $^ $(CFLAGS) 

.PHONY:	clean

clean: 

	rm *.o 

purge: 

	rm nega
