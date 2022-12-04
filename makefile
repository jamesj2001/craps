all: craps.o dice.o table.o
	g++ craps.o dice.o table.o -o craps.exe

craps.o: ./src/craps.cpp ./include/dice.h ./include/table.h
	g++ -I ./include -c ./src/craps.cpp -o craps.o

dice.o: ./src/dice.cpp ./include/dice.h
	g++ -I ./include -c ./src/dice.cpp -o dice.o

table.o: ./src/table.cpp ./include/table.h
	g++ -I ./include/ -c ./src/table.cpp -o table.o

clean:
	rm ./*.o
	rm ./craps.exe

