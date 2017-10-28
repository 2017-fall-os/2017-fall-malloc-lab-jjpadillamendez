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

int main(){
  void *p1, *p2, *p3, *p4, *p5, *p6, *p7;
    
  printf("\nTEST CASE 1: Next fit is the first fit free block .'\n");
  p1 = nextFitAllocRegion(254);        // Allocate four different chuncks of memory 
  printf(": p1 = nextFitAllocRegion(254)   , ");
  printLastPrefix();
  p2 = nextFitAllocRegion(25400);
  printf(": p2 = nextFitAllocRegion(25400) , ");
  printLastPrefix();
  p3 = nextFitAllocRegion(300);
  printf(": p3 = nextFitAllocRegion(25400) , ");
  printLastPrefix();
  freeRegion(p1);                     // Free region p1
  printf(": freeRegion(p1) , ");
  printLastPrefix();
  
  printf(" Initial State: \n");
  arenaCheck();
  printf(" Final State: \n");
  p4 = nextFitAllocRegion(240);      // Allocate new region at p3
  printf(": p4 = nextFitAllocRegion(240) , ");
  printLastPrefix();
  arenaCheck();
  freeRegion(p2);
  printf(": freeRegion(p2) , ");
  printLastPrefix();
  freeRegion(p3); 
  printf(": freeRegion(p3) , ");
  printLastPrefix();
  freeRegion(p4);
  printf(": freeRegion(p4) , ");
  printLastPrefix();
  
  printf("\nTEST CASE 2: Prove that it searches free space backwards.' bestFitAllocRegion(2550)\n");
  printf(" Initial State: \n");
  p1 = nextFitAllocRegion(500000);
  printf(": p1 = nextFitAllocRegion(500000) , ");
  printLastPrefix();
  p2 = nextFitAllocRegion(500000);
  printf(": p1 = nextFitAllocRegion(500000) , ");
  printLastPrefix();
  freeRegion(p1);
  printf(": freeRegion(p1) , ");
  printLastPrefix();
  arenaCheck();
  printf(" Final State: \n");
  p3 = nextFitAllocRegion(500000);
  printf(": p3 = nextFitAllocRegion(500000) , ");
  printLastPrefix();
  arenaCheck();
  freeRegion(p3);
  printf(": freeRegion(p3) , ");
  printLastPrefix();
  freeRegion(p2);
  printf(": freeRegion(p2) , ");
  printLastPrefix();
    
 {				/* measure time for 10000 mallocs */
    struct timeval t1, t2;
    int i;
    getutime(&t1);
    for(i = 0; i < 10000; i++)
      if (nextFitAllocRegion(4) == 0) 
	break;
    getutime(&t2);
    printf("\n%d nextFitAllocRegion(4) required %f seconds\n", i, diffTimeval(&t2, &t1));
  }
  
  return 0;
}



 
