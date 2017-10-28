#ifndef myAllocator2_H
#define myAllocator2_H

/* block prefix & suffix */
typedef struct BlockPrefix_s {
  struct BlockSuffix_s *suffix;
  int actualRequested;
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

void *bestFitAllocRegion(size_t s);
void *nextFitAllocRegion(size_t s);
void displayMemoryReport();
#endif // myAllocator2_H
