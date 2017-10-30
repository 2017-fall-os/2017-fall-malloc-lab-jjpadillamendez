CFLAGS	= -g
CC	= gcc
OBJ	= mallocTest allocatorTest reallocTest resizeTest memalignTest

all: $(OBJ)

mallocTest: myAllocator.o malloc.o mallocTest.o
	$(CC) $(CFLAGS) -o $@ $^
	
allocatorTest: myAllocator.o allocatorTest.o 
	$(CC) $(CFLAGS) -o $@ $^
	
reallocTest: myAllocator.o malloc.o reallocTest.o
	$(CC) $(CFLAGS) -o $@ $^
	
resizeTest: myAllocator.o resizeTest.o
	$(CC) $(CFLAGS) -o $@ $^
	
memalignTest: myAllocator.o memalign2.o
	$(CC) $(CFLAGS) -o $@ $^
clean:
	rm -f *.o $(OBJ) 
