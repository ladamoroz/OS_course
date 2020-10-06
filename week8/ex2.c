#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
int main(){
    int* data;
    int bytes = 1024*1024*10;
    for (int i = 0; i < 10; i++){
        data = (int *) malloc(bytes);
        memset(data, 0, bytes);
        sleep(1);
    }
    return 0;
}
/*
 Exercise 2:
 number of swapouts stay the same, number of swapins increases
 
 Exercise 3:
 The virtual memory is increasing from approximatly 4150M to approximatly 4250M, physical memory is
 increased from 0 to 100M.
 */
