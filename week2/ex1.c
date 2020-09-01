#include <stdio.h>
#include <limits.h>
#include <float.h>
int main(void) {
  int i = INT_MAX;
  float f = FLT_MAX;
  double d = DBL_MAX;
  printf("%d\n", i);
  printf("%lu\n", sizeof(i));
  printf("%f\n",f);
  printf("%lu\n", sizeof(f));
  printf("%lf\n", d);
  printf("%lu\n", sizeof(d));
  return 0;
}