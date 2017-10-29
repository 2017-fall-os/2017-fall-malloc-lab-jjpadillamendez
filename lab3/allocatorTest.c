#include "stdio.h"
#include "stdlib.h"
#include "myAllocator.h"
#include "allocatorTest.h"
#include "sys/time.h"
#include <sys/resource.h>
#include <unistd.h>
#include "nextFitTester.h"
#include "bestFitTester.h"
 
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
    printf("\n~ BEST FIT MEMORY ALLOCATOR TEST\n"); 
    runBestFitTest();
    
    cleanArena();
     
    printf("\n\n~ NEXT FIT MEMORY ALLOCATOR TEST\n");
    runNextFitTest();
    return 0;
 }
