CC=gcc
CFLAGS=-g -Wall -lm

nega = pgmnega.o openimg.o
mediana = pgmmediana.o openimg.o
rota = pgmrot.o openimg.o

%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS) 

all: pgmmediana pgmrotacao pgmnegativo

pgmnegativo: $(nega)
	$(CC) -o $@ $^ $(CFLAGS) 

pgmmediana: $(mediana)
	$(CC) -o $@ $^ $(CFLAGS) 

pgmrotacao: $(rota)
	$(CC) -o $@ $^ $(CFLAGS) 

.PHONY:	clean

clean: 

	rm *.o 

purge: 

	rm pgmrotacao pgmnegativo pgmmediana
