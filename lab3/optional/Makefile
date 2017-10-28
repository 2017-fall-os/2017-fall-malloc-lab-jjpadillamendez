CFLAGS	= -g
CC	= gcc
OBJ	= report

all: $(OBJ)

report: myAllocator2.o optionalTest.o reader.o
	$(CC) $(CFLAGS) -o $@ $^
	
clean:
	rm -f *.o $(OBJ) 

