all: craps.o dice.o table.o
	g++ craps.o dice.o table.o -o craps.exe

craps.o: craps.cpp dice.h table.h
	g++ -I ./include -c ./src/craps.cpp -o craps.o

dice.o: dice.cpp dice.h
	g++ -I ./include -c ./src/dice.cpp -o dice.o

table.o: table.cpp table.h
	g++ -I ./include/ -c ./src/table.cpp -o table.o

clean:
	rm -fr *.o
	rm craps.exe

