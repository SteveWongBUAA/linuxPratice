main: MyString.o main.o
	g++ MyString.o main.o -g -o main
MyString.o: MyString.cpp MyString.h
	g++ -c MyString.cpp -o MyString.o
main.o: main.cpp
	g++ -c main.cpp -o main.o
