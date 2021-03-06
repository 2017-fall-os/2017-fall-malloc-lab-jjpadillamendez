 # Malloc - Project 3 - Jesus Padilla #
 
 This directory contains:
<br /> myAllocator.c: implements best-fit allocator and next-fit allocator. Additionally, it re-implements the resizeRegion function
   <br />    - bestFitAllocRegion(size_t): implements best-fit algorithm
 <br />      - nextFitAllocRegion(size_t): implements next-fit algorithm
 <br />      - resizeRegion2(void *, size_t): re-implements the method resizeRegion(void *, size_t)
<br /> allocatorTest.c: implements test cases to check the methods of next-fit and best-fit
<br /> mallocTest.c: runs the same test cases as allocatorTest.c ; but, it calls malloc instead of calling directly the methods of <br />.___ myAllocator.c
<br /> resizeTest.c: implements test cases to check the re-implemented method resizeRegion2()
<br /> reallocTest.c: runs the same test as resizeTest.c; but, it calls realloc instead of directly calling the method resizeRegion2()
<br />optional: this directory contains a program that reports the comparison between first-fit, best-fit, and next-fit algorithm. To   <br />.___  run this report, it is needed to enter the directory, make all, and run the command ./report. This directory contains <br />.___               an example of the report (in report.txt).
 
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
 
 2. Prove that if a free region is not found searching forward, it returns to the beginning and searches until the last checked prefix or stops if it finds a free block that is large enough
 ![Alt text](https://github.com/2017-fall-os/2017-fall-malloc-lab-jjpadillamendez/blob/master/lab3/testImage/nextc2.jpg?raw=true)
 
 3. Requested size is bigger than the available free space
 ![Alt text](https://github.com/2017-fall-os/2017-fall-malloc-lab-jjpadillamendez/blob/master/lab3/testImage/nextc3.jpg?raw=true)
 
<b>TEST CASES FOR RE-SIZE REGION ALGORITHM</b>
 1. Empty pointer is given (void *) '. Returns a new allocated region of the requested size
 ![Alt text](https://github.com/2017-fall-os/2017-fall-malloc-lab-jjpadillamendez/blob/master/lab3/testImage/resizec1.jpg?raw=true)
 
 2. Old size is large enough '. Remains the same
 ![Alt text](https://github.com/2017-fall-os/2017-fall-malloc-lab-jjpadillamendez/blob/master/lab3/testImage/resizec2.jpg?raw=true)
 
 3. Next block is allocated, impossible to extend
 ![Alt text](https://github.com/2017-fall-os/2017-fall-malloc-lab-jjpadillamendez/blob/master/lab3/testImage/resizec3.jpg?raw=true)
 
 4. Usable space of next block is large enough to satisfy the request
 ![Alt text](https://github.com/2017-fall-os/2017-fall-malloc-lab-jjpadillamendez/blob/master/lab3/testImage/resizec4.jpg?raw=true)
 
 5. Usable space is not enough, but adding unused prefix and suffix size, it fits in
 ![Alt text](https://github.com/2017-fall-os/2017-fall-malloc-lab-jjpadillamendez/blob/master/lab3/testImage/resizec5.jpg?raw=true)
 
 6. Space of next block is just not large enough
 ![Alt text](https://github.com/2017-fall-os/2017-fall-malloc-lab-jjpadillamendez/blob/master/lab3/testImage/resizec6.jpg?raw=true)
 
<b>IMPORTANT NOTES</b>
- The extra credit task of adding for each fragment and each allocated region: count, maximum, and minimum sizes was done
- The extra credit of the memalign was added
- The file assert2.c was borrowed from Dr. Freudenthal, which adds the feature of adding an error message to the traditional assert method. 
