//////////////////////////////////////////////////////////////////////
// Author: Jesus Jose Padilla Mendez    Lab Assignment 3            //
// Prof: Dr. Freudenthal    TA: Adrian Veliz                        //
// Tester that runs different test cases to check the new method    //
// resizeRegion2(); which just extends the same region if possible  //
// otherwise, it just copies the data to other free region          //
//////////////////////////////////////////////////////////////////////
#include "stdio.h"
#include "stdlib.h"
#include "myAllocator.h"

int main(){
    
    void *p1, *p2, *p3, *p4;
    
    printf("\nTEST CASE 1: Empty pointer is given \n\t   .' p1 = resizeRegion2((void *)0, 24)\n");
    printf("- Initial State \n");
    arenaCheck();
    p1 = resizeRegion2((void *)0, 24);
    printf("- Final State -- p1 at %p\n", p1-8);
    arenaCheck();
    
    printf("\nTEST CASE 2: Old size is large enough \n\t   .' p1 = resizeRegion2(p1, 15)\n");
    printf("- Initial State -- p1 at %p\n", p1-8);
    arenaCheck();
    p1 = resizeRegion2(p1, 15);
    printf("- Final State   -- p1 at %p\n", p1-8);
    arenaCheck();
    
    printf("\nTEST CASE 3: Next block is allocated, impossible to extend \n\t   .' p1 = resizeRegion2(p1, 40)\n");
    printf("- Initial State -- p1 at %p\n", p1-8);
    p2 = firstFitAllocRegion(50);
    arenaCheck();
    p1 = resizeRegion2(p1, 40);
    printf("- Final State   -- p1 at %p\n", p1-8);
    arenaCheck();

    printf("\nTEST CASE 4: Usable space of next block is large enough \n\t   .' p3 = resizeRegion2(p3, 40)\n");
    p3 = firstFitAllocRegion(24);
    printf("- Initial State -- p3 at %p\n", p3-8);
    freeRegion(p2);
    arenaCheck();
    p3 = resizeRegion2(p3, 40);
    printf("- Final State   -- p3 at %p\n", p3-8);
    arenaCheck();
    
    printf("\nTEST CASE 5: Usable space is not enough, but adding unused prefix and suffix size; it fits in\n");
    printf("             .' p3 = resizeRegion2(p3, 89)\n");
    printf("- Initial State -- p3 at %p\n", p3-8);
    arenaCheck();
    p3 = resizeRegion2(p3, 89);
    printf("- Final State   -- p3 at %p\n", p3-8);
    arenaCheck();
    
    printf("\nTEST CASE 6: Space of next block is just not large enough .'");
    printf("\n              .' p3 = resizeRegion2(p3, 200)\n");
    p2 = firstFitAllocRegion(57);
    freeRegion(p1);
    printf("- Initial State -- p3 at %p\n", p3-8);
    arenaCheck();
    p3 = resizeRegion2(p3, 200);
    printf("- Final State   -- p3 at %p\n", p3-8);
    arenaCheck();
    return 0;
    
}
