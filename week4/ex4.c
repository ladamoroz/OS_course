#include <stdio.h>
#include <string.h>
#include <unistd.h>
int main () {
  char s[100];
  fgets(s, sizeof(s), stdin);
  while(1){
    char*args[100];
    for (int i =0;i < 100; i++){
      args[i] = (char*)malloc(100);
    }
    
    int i = 0, j = 0, k = 0;
    while (s[i]!='\0'){
      if (s[i]!=' '){
        args[k][j] = s[i];
        j = j+1;
      } else {
        args[k][j] = '\0';
        k = k+1;
        j = 0;
      }
      i = i+1;
    }
    int p = fork();
    if (p == 0){
      execve(args[0], args, NULL);
    }
    fgets(s, sizeof(s), stdin);
  }
  
  return(0);
}
