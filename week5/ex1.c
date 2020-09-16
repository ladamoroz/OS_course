#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
void * threadPrint(void * arg){
  printf("Start of the thread with ID: %d\n", *(int *)arg);
  return NULL;
}
int main() {
  int n = 5;
  pthread_t thread;
  for (int i = 0; i<n;i++){
    pthread_t threadId;
    int j = pthread_create(&threadId, NULL, &threadPrint, (void *)&i);
    printf("Thread created with ID : %d\n",i);
    j = pthread_join(threadId, NULL);
    printf("End of the thread with ID: %d\n",i);
  }
}
