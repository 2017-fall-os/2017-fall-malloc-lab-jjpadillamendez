CFLAGS	= -g
CC	= gcc
OBJ	= allocatorTest reallocTest

all: $(OBJ)

allocatorTest: myAllocator.o allocatorTest.o 
	$(CC) $(CFLAGS) -o $@ $^
	
reallocTest: myAllocator.o malloc.o reallocTest.o
	$(CC) $(CFLAGS) -o $@ $^
clean:
	rm -f *.o $(OBJ) 
