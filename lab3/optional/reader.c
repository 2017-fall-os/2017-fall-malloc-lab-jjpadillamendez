#include <stdio.h>
//#include <stdlib.h>

static FILE *file = (FILE *)0;

int initReader(char *filename){
    if(!file && filename){
        file = fopen(filename, "r");
        return (file != NULL);
    }
    return 0;
}
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
int readFile(){
    int num;
    
    num = 0;
    if(file && !feof(file)){
        if(fscanf(file, "%d", &num) != 1)
            num = 0;                        // matching failure of fscanf == 0
    }                           
    return num;

}
