#include <stdlib.h>
#include <pthread.h>
#include <stdio.h>
#define BufferSize 1000000
int count = 0;
void* produce(void* arg){
    while(1){
        while(count == BufferSize);
        printf("Producer %d",count);
        fflush(stdout);
        if (count < BufferSize){
            count++;
        }
    }
    return NULL;
}
void* consume(void* arg){
  while(1){
      while (count == 0);
      printf("Consumer %d",count);
      fflush(stdout);
      if (count > 0){
          count--;
      }
  }
  return NULL;
}

int main() {
  pthread_t pr,co;
  pthread_create(&co, NULL, consume, NULL);
  pthread_create(&pr, NULL, produce, NULL);
  pthread_join(pr, NULL);
  pthread_join(co, NULL);
}
