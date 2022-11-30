### MAKEFILE

Progama:
```
CC := g++
CFLAGS := -I include/ -Wall
BUILD := build/
SRC := src/
TARGET := main.out

all: main

baralho:
	@mkdir build/baralho/
	$(CC) $(CFLAGS) -c src/baralho.cpp -o build/baralho.o
mao:
	@mkdir build/mao/
	$(CC) $(CFLAGS) -c src/mao.cpp -o build/mao.o
ajuda:
	@mkdir build/ajuda/
	$(CC) $(CFLAGS) -c src/ajuda.cpp -o build/ajuda.o

main: baralho mao ajuda 
	$(CC) $(CFLAGS) build/baralho.o build/mao.o build/ajuda.o src/main.cpp -o	$(TARGET)

clean:
	$(RM) -r $(BUILD)/* $(TARGET

```
