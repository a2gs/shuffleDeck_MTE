CC = g++
CFLAGS = -g -Wall -std=c++14 -D_XOPEN_SOURCE=700

RM = rm -rf

all:
	$(CC) -o deck deck.cpp $(CFLAGS)

clean:
	-$(RM) deck
