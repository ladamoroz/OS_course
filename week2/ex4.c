#include <stdio.h>
#include <string.h>
void swap(int* x, int* y){
  int temp = *x; 
  *x = *y; 
  *y = temp; 
}
int main(void) {
  int a,b;
  scanf("%d",&a);
  scanf("%d",&b);
  swap(&a,&b);
  printf("%d\n", a);
  printf("%d\n",b);
}
 