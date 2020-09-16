#include <stdlib.h>
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#define BufferSize 10000
int count = 0;
int buffer[BufferSize];
pthread_mutex_t mutex;
pthread_cond_t c, p;
void Sleep(pthread_cond_t cond, pthread_mutex_t m){
  pthread_cond_wait(&cond, &m);
  printf("sleep");
  fflush(stdout);
}

void WakeUp(pthread_cond_t cond, pthread_mutex_t m){
  pthread_cond_signal(&cond);
  pthread_mutex_unlock(&m);
  printf("wakeup");
  fflush(stdout);
}

void* produce(void* arg){
  while (1){
    pthread_mutex_lock(&mutex);
    if (count == BufferSize){
      Sleep(p,mutex);
    }
    buffer[count] = buffer[count-1]+1;
    count++;
    printf("%d\n",count);
    fflush(stdout);
    usleep(10);
    if (count == 1){
      WakeUp(c,mutex);
    }
  }
  return NULL;
}
void* consume(void* arg){
  while(1){
    pthread_mutex_lock(&mutex);
    if (count == 0){
      Sleep(c,mutex);
    }
    buffer[count] = 0;
    count--;
    printf("%d\n",count);
    fflush(stdout);
    if (count == BufferSize-1){
      WakeUp(p,mutex);
    }
  }
  return NULL;
}

int main() {
  for (int i = 0; i<BufferSize; i++){
    buffer[i] = 0;
  }
  pthread_t pr,co;
  pthread_mutex_init(&mutex, 0);
  pthread_cond_init(&c, 0);
  pthread_cond_init(&p, 0);
  pthread_create(&co, NULL, consume, NULL);
  pthread_create(&pr, NULL, produce, NULL);
  pthread_join(pr, NULL);
  pthread_join(co, NULL);
  pthread_cond_destroy(&p);
  pthread_mutex_destroy(&mutex);
}
