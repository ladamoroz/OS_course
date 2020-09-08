#include <stdio.h>
#include <stdlib.h>
int main () {
  char s[100];
  while(1){
    fgets(s, sizeof(s), stdin);
    char*args[100];
    for(int i=0;i<100;i++){
        args[i]=NULL;
    }
    args[0]=(char*)malloc(100);
    int i = 0, j = 0, k = 0;
    while (s[i]!='\n' && s[i]!='\0'){
      if (s[i] == ' '){
          k++;
          j = 0;
          args[k]=(char*)malloc(100);
      } else if (s[i]!=' '){
          args[k][j] = s[i];
          j++;
      }
        i++;
    }
    int p = fork();
    if (p == 0){
      execvp(args[0], args, NULL);
    }
  }
  
  return 0;
}
