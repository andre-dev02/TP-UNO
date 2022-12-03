CC := g++
CFLAGS := -I include/ -Wall
BUILD := build/
SRC := src/
TARGET := main.out

all: main

baralho:
	@mkdir build/baralho/
	$(CC) $(CFLAGS) -c src/baralho.hpp -o build/baralho.o
mao:
	@mkdir build/mao/
	$(CC) $(CFLAGS) -c src/mao.hpp -o build/mao.o
ajuda:
	@mkdir build/ajuda/
	$(CC) $(CFLAGS) -c src/ajuda.hpp -o build/ajuda.o
testes: 
	@mkdir build/testes/
	$(CC) $(CFLAGS) -c src/testes.hpp -o build/testes.o
main: baralho mao ajuda testes
	$(CC) $(CFLAGS) build/baralho.o build/mao.o build/ajuda.o build/testes.o src/main.cpp -o	$(TARGET)

clean:
	$(RM) -r $(BUILD)/* $(TARGET
