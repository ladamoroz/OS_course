#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void isosceles(int n){
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
void right(int n){
  for (int i = 0; i < n; i++){
    char s[n];
    for (int j = 0; j < n; j++){
      s[j] = ' ';
    }
    for (int j = 0; j <= i; j++){
      s[j] = '*';
    }
    s[n] = '\0';
    printf("%s\n",s);
  }
}
void square(int n){
  char s[n];
  for (int i = 0; i <n;i++){
    s[i] = '*';
  }
  s[n] = '\0';
  for (int i = 0 ; i < n; i++){
    printf("%s\n",s);
  }
}
void obtuse(int n){
  for (int i = 0; i<2*n;i++){
    char s[n];
    for (int j = 0; j < n; j++){
      s[j]= ' ';
    }
    int m = n-1 - abs(n-1 - i);
    for (int j = 0; j<=m; j++){
      s[j]='*';
    }
    s[n] = '\0';
    printf("%s\n",s);
  }
}
int main(void) {
  printf("Please, write the number of function:\n" );
  int t;
  scanf("%d", &t);
  if (t == 1){
    printf("Height of isosceles acute-angle triangle:\n");
    int n;
    scanf("%d",&n);
    isosceles(n);
  }

  if (t==2){
    printf("Height of the right triangle:\n");
    int n;
    scanf("%d",&n);
    right(n);
  }
  
  if (t == 3){
    printf("Side of square:\n");
    int n;
    scanf("%d",&n);
    square(n);
  }
  if (t==4){
    printf("Height of the isosceles obtuse triangle:\n");
    int n;
    scanf("%d",&n);
    obtuse(n);
  }

}