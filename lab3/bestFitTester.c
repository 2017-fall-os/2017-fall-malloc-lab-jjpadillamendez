#include "stdio.h"
#include "stdlib.h"
#include "myAllocator.h"
#include "allocatorTest.h"
#include "sys/time.h"
#include <sys/resource.h>
#include <unistd.h>
#include "bestFitTester.h"

int runBestFitTest(){
  void *p1, *p2, *p3, *p4, *p5, *p6, *p7;
  
  
  printf("\nTEST CASE 1: Best fit is the first fit free block .' bestFitAllocRegion(252)\n");
  printf(" :Initial State \n");
  p1 = bestFitAllocRegion(254);        // Allocate four different chuncks of memory 
  p2 = bestFitAllocRegion(25400);
  p3 = bestFitAllocRegion(300);
  p4 = bestFitAllocRegion(100);
  freeRegion(p1);                     // Free region p1 and p3
  freeRegion(p3);
  arenaCheck();
  printf(" :Final State \n");
  p3 = bestFitAllocRegion(252);      // Allocate new region at p3
  arenaCheck();
  freeRegion(p2); freeRegion(p3); freeRegion(p4);
  
  printf("\nTEST CASE 2: Best fit is not the first fit free block .' bestFitAllocRegion(2550)\n");
  printf(" :Initial State \n");
  p1 = bestFitAllocRegion(1900);        // Allocate four different chuncks of memory 
  p2 = bestFitAllocRegion(2640);
  p3 = bestFitAllocRegion(200);
  p4 = bestFitAllocRegion(2600);
  p5 = bestFitAllocRegion(700);
  p6 = bestFitAllocRegion(2700);
  p7 = bestFitAllocRegion(400);
  freeRegion(p2);                     // Free region p1 and p3
  freeRegion(p4);
  freeRegion(p6);
  arenaCheck();
  printf(" :Final State \n");
  p2 = bestFitAllocRegion(2550);      // Allocate new region at p3
  arenaCheck();
  freeRegion(p1); freeRegion(p2); freeRegion(p3);
  freeRegion(p5); freeRegion(p7);
  
  printf("\nTEST CASE 3: Requested size is bigger than the arena .' bestFitAllocRegion(2M)\n");
  printf(" :Initial State \n");
  arenaCheck();
  printf(" :Final State \n");
  p1 = bestFitAllocRegion(0x200000);
  arenaCheck();
  
  {				/* measure time for 10000 mallocs */
    struct timeval t1, t2;
    int i;
    getutime(&t1);
    for(i = 0; i < 10000; i++)
      if (bestFitAllocRegion(4) == 0) 
	break;
    getutime(&t2);
    printf("\n%d bestFitAllocRegion(4) required %f seconds\n", i, diffTimeval(&t2, &t1));
  }
  
  return 0;
}



