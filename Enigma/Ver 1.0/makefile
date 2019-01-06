main: main.o enigma.o
	g++ main.o enigma.o -o main

main.o: main.cpp
	g++ -Wall -c main.cpp

enigma.o: enigma.cpp
	g++ -Wall -c enigma.cpp

clean:
	rm enigma.o main.o main
