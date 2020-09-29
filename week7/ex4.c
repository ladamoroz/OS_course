#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <malloc/malloc.h>
void *my_realloc(void* ptr, size_t size){
    void* temp;
    if (!ptr){
        temp = malloc(size);
        if (!temp){return NULL;}
    } else {
        if (malloc_size(ptr)<size){
            temp = malloc(size);
            if (!temp){return NULL;}
            memcpy(temp, ptr, malloc_size(ptr));
            free(ptr);
        } else {
            temp = ptr;
        }
    }
    return temp;
}
int main(){
    printf("Size of array: ");
    int n1;
    scanf("%d",&n1);
    int* array = malloc(sizeof(int)*n1);
    for (int i = 0;i <n1; i++){
        array[i] = 100;
        printf("%d ", array[i]);
    }
    int n2;
    printf("\nNew size: ");
    scanf("%d",&n2);
    array = my_realloc(array, sizeof(int) * n2);
    if (n2 > n1){
        for (int i = n1; i<n2;i++){
            array[i] = 0;
        }
    }
    for (int i = 0; i <n2; i++){
        printf("%d ",array[i]);
    }
    free(array);
    return 0;
}
