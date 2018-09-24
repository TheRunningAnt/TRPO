flag = -c -Wall

all: ./bin/run

./bin/run: ./build/main.o
	gcc ./build/tic-tac-toe.o ./build/main.o -o ./bin/run

./build/main.o: ./build/tic-tac-toe.o
	gcc $(flag) ./src/main.c -o ./build/main.o

./build/tic-tac-toe.o:
	gcc $(flag) ./src/tic-tac-toe.c -o ./build/tic-tac-toe.o

.PHONY: clean
clean:
	rm -rf ./build/*.o
