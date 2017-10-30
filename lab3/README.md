 # Malloc - Project 3 - Jesus Padilla #
 
 This directory contains:
<br /> myAllocator.c: implements best-fit allocator and next-fit allocator. Additionally, it re-implements the resizeRegion function
   <br />    - bestFitAllocRegion(size_t): implements best-fit algorithm
 <br />      - nextFitAllocRegion(size_t): implements next-fit algorithm
 <br />      - resizeRegion2(void *, size_t): re-implements the method resizeRegion(void *, size_t)
<br /> allocatorTest.c: implements test cases to check the methods of next-fit and best-fit
<br /> mallocTest.c: runs the same test cases as allocatorTest.c ; but, it calls malloc instead of calling directly the methods of myAllocator.c
<br /> resizeTest.c: implements test cases to check the re-implemented method resizeRegion2()
<br /> reallocTest.c: runs the same test as resizeTest.c; but, it calls realloc instead of directly calling the method resizeRegion2()
<br />optional: this directory contains a program that reports the comparison between first-fit, best-fit, and next-fit algorithm.
 
 To compile:
 ~~~
 $ make all
 ~~~
 
 To run it, try:
 ~~~
 $ ./allocatorTest
 ~~~
 ~~~
 $ ./mallocTest
 ~~~
 ~~~
 $ ./resizeTest
 ~~~
 ~~~
 $ ./reallocTest
 ~~~
 
 To delete generated files:
 ~~~
 $ make clean
 ~~~
 
<b>TEST CASES FOR BEST-FIT ALGORITHM</b>
 1. The best fit is the first fit free block 
 ![Alt text](https://github.com/2017-fall-os/2017-fall-malloc-lab-jjpadillamendez/blob/master/lab3/testImage/bestc1.jpg?raw=true)
 
 2. The best fit is not the first fit free block
 ![Alt text](https://github.com/2017-fall-os/2017-fall-malloc-lab-jjpadillamendez/blob/master/lab3/testImage/bestc2.jpg?raw=true)
 
 3. Requested size is bigger than the available free space
 ![Alt text](https://github.com/2017-fall-os/2017-fall-malloc-lab-jjpadillamendez/blob/master/lab3/testImage/bestc3.jpg?raw=true)
 
<b>TEST CASES FOR NEXT-FIT ALGORITHM</b>
 1. Next fit region is the first fit it finds but last checked prefix is not at the beginning of the arena
 ![Alt text](https://github.com/2017-fall-os/2017-fall-malloc-lab-jjpadillamendez/blob/master/lab3/testImage/nextc1.jpg?raw=true)
 
 2. Prove that if a free region is not found searching forward, it returns to the beginning and searches until the last checked prefix
 ![Alt text](https://github.com/2017-fall-os/2017-fall-malloc-lab-jjpadillamendez/blob/master/lab3/testImage/nextc2.jpg?raw=true)
 
 3. Requested size is bigger than the available free space
 ![Alt text](https://github.com/2017-fall-os/2017-fall-malloc-lab-jjpadillamendez/blob/master/lab3/testImage/nextc3.jpg?raw=true)
 
<b>TEST CASES FOR RE-SIZE REGION ALGORITHM</b>
 1. Empty pointer is given (void *)
 2. Old size is large enough
 3. Next block is allocated, impossible to extend
 4. Usable space of next block is large enough to satisfy the request
 5. Usable space is not enough, but adding unused prefix and suffix size, it fits in
 6. Space of next block is just not large enough
 
<b>IMPORTANT NOTES</b>
- The extra credit task of adding for each gragment and each allocated region: count, maximum, and minimum sizes was done
- The file assert2.c was borrowed from Dr. Freudenthal, which adds the feature of adding an error message to the traditional assert method. 
