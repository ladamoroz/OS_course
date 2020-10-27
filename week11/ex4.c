#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
int main(){
    int source = open("ex1.txt", O_RDWR);
    int destination = open("ex1_memcpy.txt", O_RDWR);
    if(source < 0 || destination < 0){
        printf("open error\n");
    }
    struct stat buff = {};
    if (fstat(source, &buff)){
        printf("fstat error\n");
    }
    char *str;
    char* s;
    off_t size = buff.st_size;
    truncate("ex1_memcpy.txt", size);
    s = mmap(NULL, size, PROT_READ|PROT_WRITE, MAP_SHARED, source, 0);
    str = mmap(NULL, size, PROT_READ|PROT_WRITE, MAP_SHARED, destination, 0);
    if (str == MAP_FAILED){
        printf("mmap error\n");
    }
    strcpy(str, s);
    return 0;
   }
