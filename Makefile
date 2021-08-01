./a.out: a.cpp Makefile
	g++ a.cpp -Wall -Wpedantic -std=c++17

run:
	./a.out < pipe > pipe2

server:
	while ! python3 server.py > pipe < pipe2 ; do sleep 1 ; done

clean:
	-rm a.out
