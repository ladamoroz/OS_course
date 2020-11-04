#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
int main(int argc, char** argv){
    char* mode;
    char temp;
    if (argc == 1){
        while(fread(&temp, 1, 1, stdin)) {
            printf("%c", temp);
        }
    }
    int num, off;
    if (strcmp(argv[1], "-a") == 0){
        mode = "a+";
        off = 2;
    } else{
        mode = "w+";
        off = 1;
    }
    num = argc - off;
    FILE **files = malloc((num+1)*sizeof(FILE*));
    for (int i = off; i<argc; i++){
        files[i - off] = fopen(argv[i], mode);
    }
    files[num] = stdout;
    while(fread(&temp, 1, 1, stdin)) {
        for (int i = 0; i < num; i++){
            fwrite(&temp,1,1,files[i]);
        }
    }
    return 0;
}
