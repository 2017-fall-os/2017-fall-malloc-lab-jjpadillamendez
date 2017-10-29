//////////////////////////////////////////////////////////////////////
// Author: Jesus Jose Padilla Mendez    Lab Assignment 3            //
// Prof: Dr. Freudenthal    TA: Adrian Veliz                        //
// Tester that runs different test cases to check the new memory    //
// allocator methods Best fit and Next fit                          //
//////////////////////////////////////////////////////////////////////
#include "stdio.h"
#include "stdlib.h"
#include "myAllocator.h"
#include "sys/time.h"
#include <sys/resource.h>
#include <unistd.h>
#include "malloc.h"

double diffTimeval(struct timeval *t1, struct timeval *t2) {
    double d = (t1->tv_sec - t2->tv_sec) + (1.0e-6 * (t1->tv_usec - t2->tv_usec));
    return d;
}

void getutime(struct timeval *t){
    struct rusage usage;
    getrusage(RUSAGE_SELF, &usage);
    *t = usage.ru_utime;
}
// Test for Best Fit Memory Allocator, it runs different test cases such as
// 1. Best fit region is the first fit it finds
// 2. Best fit region is not the first fit it finds
// 3. The requested size is bigger than the available space
int runBestFitTest(){
    void *p1, *p2, *p3, *p4, *p5, *p6, *p7;
  
  
    printf("\nTEST CASE 1: Best fit is the first fit free block .' malloc(252)\n");
    printf(" :Initial State \n");
    p1 = malloc(254);                // Allocate different regions just to set up test case
    p2 = malloc(25400);
    p3 = malloc(300);
    p4 = malloc(100);
    freeRegion(p1);                 // Free region p1 and p3
    freeRegion(p3);
    arenaCheck();
    printf(" :Final State \n");
    p3 = malloc(252);               // Allocate new region at p3
    arenaCheck();
    freeRegion(p2); freeRegion(p3); freeRegion(p4);
    
    printf("\nTEST CASE 2: Best fit is not the first fit free block .' malloc(2550)\n");
    printf(" :Initial State \n");
    p1 = malloc(1900);               // Allocate different regions just to set up test case
    p2 = malloc(2640);
    p3 = malloc(200);
    p4 = malloc(2600);
    p5 = malloc(700);
    p6 = malloc(2590);
    p7 = malloc(400);
    freeRegion(p2);                 // Free region p2, p4, and p6
    freeRegion(p4);
    freeRegion(p6);
    arenaCheck();
    printf(" :Final State \n");
    p2 = malloc(2550);              // Allocate new region at p2
    arenaCheck();
    freeRegion(p1); freeRegion(p2); freeRegion(p3);
    freeRegion(p5); freeRegion(p7); // Free all of them
    
    printf("\nTEST CASE 3: Requested size is bigger than the arena .' malloc(2M)\n");
    printf(" :Initial State \n");
    arenaCheck();
    printf(" :Final State \n");
    p1 = malloc(0x200000);          // Try to allocate a huge region
    arenaCheck();
    
    {				/* measure time for 10000 mallocs */
        struct timeval t1, t2;
        int i;
        getutime(&t1);
        for(i = 0; i < 10000; i++)
        if (malloc(4) == 0) 
        break;
        getutime(&t2);
        printf("\n%d malloc(4) required %f seconds\n", i, diffTimeval(&t2, &t1));
    }
    
    return 0;

}
// Test for Next Fit Memory Allocator, it runs different test cases such as
// 1. Next fit region is the first fit it finds and last checked region is not the beginning of arena)
// 2. Next fit region is not found searching forward; return to the begining and searches until last checked region
// 3. The requested size is bigger than the available space
int runNextFitTest(){
    void *p1, *p2, *p3, *p4, *p5, *p6, *p7;
        
    printf("\nTEST CASE 1: Next fit is the first fit block; but, last checked region is not at the beginning.'\n");
    p1 = malloc(254);       
    printf(": p1 = malloc(254)   , "); printLastPrefix();       // Allocate different regions just to set up test case
    p2 = malloc(25400);
    printf(": p2 = malloc(25400) , "); printLastPrefix();
    p3 = malloc(300);
    printf(": p3 = malloc(25400) , "); printLastPrefix();
    freeRegion(p1);                                            // Free region p1
    printf(": freeRegion(p1) , ");  printLastPrefix();
    
    printf(" Initial State: \n");
    arenaCheck();
    printf(" Final State: \n");
    p4 = malloc(240);                                         // Allocate new region at p4
    printf(": p4 = malloc(240) , "); printLastPrefix();       
    arenaCheck();
    freeRegion(p2);
    printf(": freeRegion(p2) , "); printLastPrefix();
    freeRegion(p3); 
    printf(": freeRegion(p3) , "); printLastPrefix();
    freeRegion(p4);
    printf(": freeRegion(p4) , "); printLastPrefix();
    
    printf("\nTEST CASE 2: Prove that it searches for free space after it does not find by searching forward .' \n");
    printf(" Initial State: \n");
    p1 = malloc(500000);
    printf(": p1 = malloc(500000) , "); printLastPrefix();   // Allocate different regions just to set up test case
    p2 = malloc(500000);
    printf(": p2 = malloc(500000) , "); printLastPrefix();
    freeRegion(p1);
    printf(": freeRegion(p1) , "); printLastPrefix();
    arenaCheck();
    printf(" Final State: \n");
    p3 = malloc(500000);
    printf(": p3 = malloc(500000) , "); printLastPrefix();
    arenaCheck();
    freeRegion(p3);
    printf(": freeRegion(p3) , "); printLastPrefix();
    freeRegion(p2);
    printf(": freeRegion(p2) , "); printLastPrefix();
        
    printf("\n TEST CASE 3: Requested size is not available .' \n");
    printf(" Initial State \n");
    arenaCheck();
    printf(" Final State \n");
    printf(": p1 = malloc(2M) , "); printLastPrefix();
    p1 = malloc(0x200000);
    arenaCheck();
    
    {				/* measure time for 10000 mallocs */
        struct timeval t1, t2;
        int i;
        getutime(&t1);
        for(i = 0; i < 10000; i++)
        if (malloc(4) == 0) 
        break;
        getutime(&t2);
        printf("\n%d malloc(4) required %f seconds\n", i, diffTimeval(&t2, &t1));
    }
    return 0;
  
}
 int main(){
    changeAllocator(BEST_FIT);          // Set up best fit allocator
    printf("\n~ BEST FIT MEMORY ALLOCATOR TEST\n"); 
    runBestFitTest();
    
    cleanArena();                       // Clear Arena for test next allocator
    changeAllocator(NEXT_FIT);
     
    printf("\n\n~ NEXT FIT MEMORY ALLOCATOR TEST\n");
    runNextFitTest();
    
    return 0;
 }
