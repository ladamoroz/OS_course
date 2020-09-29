#include <stdio.h>
#include <stdlib.h>
int main() {
    char **s = malloc(1);       //allocate memory for s
    char foo[] = "Hello World";
    *s = foo;
    printf("s is %p\n",s);      //change %s to %p to correct output
    s[0] = foo;
    printf("s[0] is %s\n",s[0]);
    return(0);
}

/*
 Segmenatation fault happen because initialy we don't allocate memory for s
 */
