#include  <stdio.h>
#include  <sys/types.h>
#include <unistd.h>
int main(){
  for (int i = 0; i < 3; i++){
    fork();
  }
  sleep(5);
}

/*
 for 3 we have 2^3 = 8 processes
 for 5 we have 2^5 = 32 processes
 */
