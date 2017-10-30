#include "stdio.h"
#include "stdlib.h"
#include "myAllocator.h"

int main(){
    void *p1 = memalign2(32, 101);
    printf("memalign2(32, 101)=> %d/32 = %.2f, \n", p1, (double)((int)p1/32));
    p1 = memalign2(32, 200);
    printf("memalign2(32, 200)=> %d/32 = %.2f, \n", p1, (double)((int)p1/32));
    p1 = memalign2(32, 380);
    printf("memalign2(32, 380)=> %d/32 = %.2f, \n\n", p1, (double)((int)p1/32));
    
    p1 = memalign2(64, 101);
    printf("memalign2(64, 101)=> %d/64 = %.2f, \n", p1, (double)((int)p1/64));
    p1 = memalign2(64, 200);
    printf("memalign2(64, 200)=> %d/64 = %.2f, \n", p1, (double)((int)p1/64));
    p1 = memalign2(64, 380);
    printf("memalign2(64, 380)=> %d/64 = %.2f, \n\n", p1, (double)((int)p1/64));
    arenaCheck();
    return 0;
    
}
