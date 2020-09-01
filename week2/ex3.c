#include <stdio.h>
#include <string.h>
int main(void) {
  int n;
  scanf("%d",&n);
  for (int i = n; i > 0; i--){
    char s[2*n];
    for (int j = 0; j < 2*n; j++){
      s[j] = ' ';
    }
    for (int j = i-1; j <2*n-i; j++){
      s[j] = '*';
    }
    s[2*n] = '\0';
    printf("%s\n",s);
  }
}