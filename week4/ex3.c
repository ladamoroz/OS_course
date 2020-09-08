#include <stdio.h>
#include <string.h>
int main () {
  char command[100];
  scanf("%s",command);
  while(1){
    system(command);
    scanf("%s",command);
  }
  return(0);
}
