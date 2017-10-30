////////////////////////////////////////////////////////////
// Author: Jesus Jose Padilla Mendez    Lab Assignment 3  //
// Prof: Dr. Freudenthal    TA: Adrian Veliz              //
// Implementation of Best-fit and First-fit free-memory   //
// management, and resizeRegion                           //
////////////////////////////////////////////////////////////
#ifndef myAllocator_H
#define myAllocator_H

/* block prefix & suffix */
typedef struct BlockPrefix_s {
  struct BlockSuffix_s *suffix;
  int allocated;
} BlockPrefix_t;

typedef struct BlockSuffix_s {
  struct BlockPrefix_s *prefix;
} BlockSuffix_t;

void arenaCheck(void);
void *firstFitAllocRegion(size_t s);
void freeRegion(void *r);
void *resizeRegion(void *r, size_t newSize);
size_t computeUsableSpace(BlockPrefix_t *p);
BlockPrefix_t *regionToPrefix(void *r);

void *resizeRegion2(void *r, size_t newSize);
void *bestFitAllocRegion(size_t s);
void *nextFitAllocRegion(size_t s);
void printLastPrefix();
void cleanArena();
void *memalign2(size_t ALIGN, size_t NBYTES);

#endif // myAllocator_H
