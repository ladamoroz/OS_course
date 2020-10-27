#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
int main(){
    int FILE = open("ex1.txt", O_RDWR);
    if(FILE < 0){
        printf("open error\n");
    }
    struct stat buff = {};
    if (fstat(FILE, &buff)){
        printf("fstat error\n");
    }
    char *str;
    char s[] = "This is a nice day";
    int size = strlen(s);
    truncate("ex1.txt", size);
    str = mmap(NULL, size, PROT_READ|PROT_WRITE, MAP_SHARED, FILE, 0);
    if (str == MAP_FAILED){
        printf("mmap error\n");
    }
    strcpy(str, s);
    return 0;
   }
