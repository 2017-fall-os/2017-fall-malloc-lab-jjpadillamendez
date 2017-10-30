#include <stdio.h>
//////////////////////////////////////////////////////////////////////
// Author: Jesus Jose Padilla Mendez    Lab Assignment 3            //
// Prof: Dr. Freudenthal    TA: Adrian Veliz                        //
// Reader that allows to read a line of a file                      //
//////////////////////////////////////////////////////////////////////
static FILE *file = (FILE *)0;

// Init this reader by opening the file with the given name
int initReader(char *filename){
    if(!file && filename){
        file = fopen(filename, "r");
        return (file != NULL);
    }
    return 0;
}
// Close this reader by closing the Reader
int closeReader(){
    if(file){
        int r = fclose(file);
        if(r == 0){                       // on successful close, fclose returns 0
            file = (FILE *) 0;        
            return 1;
        }
    }
    return 0;
}
// Reads next line of the opened file
int readFile(){
    int num;
    
    num = 0;
    if(file && !feof(file)){
        if(fscanf(file, "%d", &num) != 1)
            num = 0;                        // matching failure of fscanf == 0
    }                           
    return num;

}
