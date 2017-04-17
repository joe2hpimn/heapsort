CC = gcc 
CFILES = heapsort.c

CFLAGS = -std=c99 -Wall -Wextra 
CFLAGS += -O2 -DNDEBUG
#CFLAGS += -O0 -g

EXEC =
LIB = libheapsort.a

all: $(LIB) $(EXEC)


libheapsort.a: heapsort.o
	ar -rcs $@ $^


prefix ?= /usr/local

install: all
	install -d ${prefix}/include ${prefix}/lib
	install heapsort.h ${prefix}/include
	install libheapsort.a ${prefix}/lib

clean:
	rm -f *.o $(EXEC) $(LIB)
