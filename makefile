flag = -c -Wall

all: ./bin/run

./bin/run: ./build/main.o
	gcc ./build/tic-tac-toe.o ./build/main.o -o ./bin/run

./build/main.o: ./build/tic-tac-toe.o
	gcc $(flag) ./src/main.c -o ./build/main.o

./build/tic-tac-toe.o:
	gcc $(flag) ./src/tic-tac-toe.c -o ./build/tic-tac-toe.o

.PHONY: test
test: ./bin/test
	./bin/test

./bin/test: ./build/test.o ./build/test_main.o ./build/tic-tac-toe.o
	gcc ./build/test_main.o ./build/test.o ./build/tic-tac-toe.o -o ./bin/test

./build/test.o:
	gcc -Ithirdparty -Isrc -c ./test/test.c -o ./build/test.o

./build/test_main.o:
	gcc -Ithirdparty -Isrc -c ./test/test_main.c -o ./build/test_main.o	

.PHONY: clean
clean:
	rm -rf ./build/*.o
