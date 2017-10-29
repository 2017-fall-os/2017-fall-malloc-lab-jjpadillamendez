CFLAGS	= -g
CC	= gcc
OBJ	= myAllocatorTest1 test1 test2 allocatorTest reallocTest

all: $(OBJ)

myAllocatorTest1: myAllocator.o myAllocatorTest1.o 
	$(CC) $(CFLAGS) -o $@ $^
	
allocatorTest: myAllocator.o allocatorTest.o nextFitTester.o bestFitTester.o
	$(CC) $(CFLAGS) -o $@ $^

test1: myAllocator.o malloc.o test1.o
	$(CC) $(CFLAGS) -o $@ $^

test2: myAllocator.o malloc.o test2.o
	$(CC) $(CFLAGS) -o $@ $^
	
reallocTest: myAllocator.o malloc.o reallocTest.o
	$(CC) $(CFLAGS) -o $@ $^
clean:
	rm -f *.o $(OBJ) 

