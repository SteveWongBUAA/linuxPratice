main: main.o vect.o
	g++ -g -Wall main.o vect.o -o main
mian.o: main.cpp
	g++ -c -Wall main.cpp -o main.o
vect.o: vect.cpp vect.h
	g++ -c -Wall vect.cpp -o vect.o
clean:
	-rm *.o 
	-rm main
