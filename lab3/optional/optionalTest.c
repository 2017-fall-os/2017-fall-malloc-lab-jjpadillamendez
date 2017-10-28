#include "stdio.h"
#include "stdlib.h"
#include "myAllocator2.h"
#include "reader.h"
#include "assert2.h"

const int MAX = 1008;	/* 2M */
const int MIN = 8;  

#define MEMORY_ERROR 1

#define FIRST_FIT 0
#define BEST_FIT 1
#define NEXT_FIT 2

int rand2(int v, int max, int min){
    return (v % (max - min)) + min;
}
void *malloc2(int allocator, int size){
    switch(allocator){
        case FIRST_FIT:
            return firstFitAllocRegion(size);
        case BEST_FIT:
            return bestFitAllocRegion(size);
        case NEXT_FIT:
            return nextFitAllocRegion(size);
    }
    return (void *)0;
}
void runTest(int allocator){
    int v, r, size, numOfRegions;
    int *p1, stop;
  
    r = initReader("mallocLab-rands.txt");                // Open file of random numbers
    assert2(r == 1, "Error: Cannot Open File");
  
    stop = 0;
    size = 0;
    while(stop == 0){
        v = readFile();
        assert2(v != 0, "Error: When trying to read the file");
        numOfRegions = rand2(v, 11, 1);                    
        size = rand2(v, MAX, MIN);                         // Saving state of the first allocated region ..
        p1 = malloc2(allocator, size);                   // .. which is needed to free at the end
        if(p1){
            numOfRegions--;
            for(int i=0; i < numOfRegions; i++){
                v = readFile();
                assert2(v != 0, "Error: When trying to read the file");
                size = rand2(v, MAX, MIN);
                if(malloc2(allocator, size) == 0){
                    stop = MEMORY_ERROR;                // No more space to allocate
                    break;
                }
            }
            freeRegion(p1);                                 // Free first allocated region of the round
        }else{
            stop = MEMORY_ERROR;                            // No more space to allocate
        }
    }
    arenaCheck();
    if(stop == MEMORY_ERROR){
        displayMemoryReport();
        printf("    Failed Allocation\n");
        printf("\tAmount:       %d \n", size);
    }
    r = closeReader();                                      // Close file of random numbers
    assert2(r == 1, "Error: Cannot Close File");
    
    
}
int main(){
//     printf("\nFirst Fit Memory Allocator Report\n");
//     runTest(FIRST_FIT);
    printf("\nBest Fit Memory Allocator Report\n");
    runTest(BEST_FIT);
//     printf("\nNext Fit Memory Allocator Report\n");
//     runTest(NEXT_FIT);
    return 0;
  
}



 
