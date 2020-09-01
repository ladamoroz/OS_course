#include <stdio.h>
#include <string.h>
int main(void) {
  char s[256], r[256];
  fgets(s, sizeof(s), stdin);
  int n = strlen(s);
  int i,j;
  j = n - 1;
  for (i = 0; i < n; i++) {
    r[i] = s[j];
    j--;
  }
  r[i] = '\0';
  printf("%s",r);
}