#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
int main(){
    char s[] = "Hello";
    setvbuf(stdout, NULL,_IOFBF, 0);
    for (int i = 0; i < strlen(s); i++){
        printf("%c\n", s[i]);
        sleep(1);
    }
    return 0;
}
