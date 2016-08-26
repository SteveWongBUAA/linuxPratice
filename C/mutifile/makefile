CC=g++
CFLAGS=-I.
DEPS=coordin.h
OBJ=file1.o file2.o

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)	

target: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) 

clean:
	-rm *.o
	-rm target
