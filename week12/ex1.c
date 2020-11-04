#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
int main(){
    int rf = open("/dev/random", O_RDONLY);
    FILE *fp;
    fp = fopen("ex1.txt", "w");
    if (rf < 0){
        printf("Error");
    } else{
        char data[20];
        ssize_t size = read(rf, data, sizeof data);
        if (size < 0){
            printf("Error");
        } else {
            fprintf(fp, "%s", data);
        }
    }
    return 0;
}
