program : main.o CLI.o
	g++ -g -o program main.o CLI.o
main.o : main.cpp
	g++ -g -c main.cpp
CLI.o : CLI.cpp CLI.h
	g++ -g -c CLI.cpp CLI.h
clean :
	rm program main.o CLI.o
