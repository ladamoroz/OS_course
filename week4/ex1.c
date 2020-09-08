#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
int  main(void){
  pid_t  n;
  n = fork();
  if (n == 0){
    printf("Hello from child [%d - %d]\n", getpid(), n);
  } else {
    printf("Hello from parent [%d - %d]\n", getpid(), n);
  }
}
/* Execute 10 times:
Hello from parent [28148 - 28149]
Hello from child [28149 - 0]
Hello from parent [28150 - 28151]
Hello from child [28151 - 0]
Hello from parent [28152 - 28153]
Hello from child [28153 - 0]
Hello from parent [28154 - 28155]
Hello from child [28155 - 0]
Hello from parent [28156 - 28157]
Hello from child [28157 - 0]
Hello from parent [28158 - 28159]
Hello from child [28159 - 0]
Hello from parent [28160 - 28161]
Hello from child [28161 - 0]
Hello from parent [28162 - 28163]
Hello from child [28163 - 0]
Hello from parent [28164 - 28165]
Hello from child [28165 - 0]
Hello from parent [28166 - 28167]
Hello from child [28167 - 0]

For every execution of program we have 
*/
