CC=gcc
LD=gcc

CCFLAGS= -c -O2
LDFLAGS= -O2

LIBS=

BIN=schn
OBJECTS:=$(patsubst %.c, %.o, $(wildcard *.c))
HEADERS:=$(wildcard *.h)


.PHONY: all clean run


all: $(BIN)

$(BIN): $(OBJECTS)
	$(LD) $(LIBS) $(LDFLAGS) -o bin/$@ $^

$(OBJECTS): %.o : %.c $(HEADERS)
	$(CC) $(CCFLAGS) -o $@ $<
	

clean:
	rm -rf bin/$(BIN) $(OBJECTS)
