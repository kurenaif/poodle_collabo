./a.out: a.cpp
	g++ a.cpp -std=c++17

run:
	./a.out < pipe > pipe2
