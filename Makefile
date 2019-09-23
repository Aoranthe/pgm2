CC=gcc
CFLAGS=-g -Wall -lm

nega = pgmnega.o openimg.o

rota = pgmrot.o openimg.o

lbp = pgmlbp.o openimg.o



%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS) 

all: pgmrotacao pgmnega

pgmnega: $(nega)
	$(CC) -o $@ $^ $(CFLAGS) 

pgmlbp: $(lbp)
	$(CC) -o $@ $^ $(CFLAGS)

pgmrotacao: $(rota)
	$(CC) -o $@ $^ $(CFLAGS) 

.PHONY:	clean

clean: 

	rm *.o 

purge: 

	rm pgmrotacao pgmnega pgmlbp
