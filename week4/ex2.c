#include  <stdio.h>
#include  <sys/types.h>
#include <unistd.h>
int main(){
  for (int i = 0; i < 5; i++){
    fork();
  }
  sleep(5);
}
/*
 for 3: 2^3 = 8 processes
 for 5: 2^5 = 32 processes
 */
