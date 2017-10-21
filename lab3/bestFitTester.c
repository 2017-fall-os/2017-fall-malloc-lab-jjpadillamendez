#include "stdio.h"
#include "stdlib.h"
#include "myAllocator.h"
#include "sys/time.h"
#include <sys/resource.h>
#include <unistd.h>

extern int algorithm;
double diffTimeval(struct timeval *t1, struct timeval *t2) {
  double d = (t1->tv_sec - t2->tv_sec) + (1.0e-6 * (t1->tv_usec - t2->tv_usec));
  return d;
}

void getutime(struct timeval *t)
{
  struct rusage usage;
  getrusage(RUSAGE_SELF, &usage);
  *t = usage.ru_utime;
}

int main() 
{
  void *p1, *p2, *p3, *p4, *p5, *p6, *p7;
  
  
  printf("\nTEST CASE 1: Best fit is the first fit free block .' bestFitAllocRegion(240)\n");
  printf(" INITIAL STATE: \n");
  p1 = bestFitAllocRegion(254);        // Allocate four different chuncks of memory 
  p2 = bestFitAllocRegion(25400);
  p3 = bestFitAllocRegion(300);
  p4 = bestFitAllocRegion(100);
  freeRegion(p1);                     // Free region p1 and p3
  freeRegion(p3);
  arenaCheck();
  printf(" FINAL STATE: \n");
  p3 = bestFitAllocRegion(240);      // Allocate new region at p3
  arenaCheck();
  freeRegion(p2); freeRegion(p3); freeRegion(p4);
  
  printf("\nTEST CASE 2: Best fit is not the first fit free block .' bestFitAllocRegion(2550)\n");
  printf(" INITIAL STATE: \n");
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
  printf(" FINAL STATE: \n");
  p2 = bestFitAllocRegion(2550);      // Allocate new region at p3
  arenaCheck();
  freeRegion(p1); freeRegion(p2); freeRegion(p3);
  freeRegion(p5); freeRegion(p7);
  
  {				/* measure time for 10000 mallocs */
    struct timeval t1, t2;
    int i;
    getutime(&t1);
    for(i = 0; i < 10000; i++)
      if (bestFitAllocRegion(4) == 0) 
	break;
    getutime(&t2);
    printf("\n%d nextFitAllocRegion(4) required %f seconds\n", i, diffTimeval(&t2, &t1));
  }
  
  return 0;
}



