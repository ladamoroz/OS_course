#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/resource.h>
int main(){
    int* data;
    int bytes = 1024*1024*10;
    for (int i = 0; i < 10; i++){
        data = (int *) malloc(bytes);
        memset(data, 0, bytes);
        struct rusage usage;
        getrusage(RUSAGE_SELF,&usage);
        printf("Max: %ld\n", usage.ru_maxrss);
        sleep(1);
    }
    return 0;
}
/*
 Output:
 Max: 11194368
 Max: 21692416
 Max: 32178176
 Max: 42663936
 Max: 53149696
 Max: 63635456
 Max: 74121216
 Max: 84606976
 Max: 95092736
 Max: 105578496
 */
