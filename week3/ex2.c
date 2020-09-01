#include <stdio.h> 
  
void swap(int *x, int *y){ 
    int temp = *x; 
    *x = *y; 
    *y = temp; 
} 
void bubble_sort(int arr[], int n) { 
  for (int i = 0; i < n-1; i++) {
    for (int j = 0; j < n-i-1; j++){ 
      if (arr[j] > arr[j+1]){ 
        swap(&arr[j], &arr[j+1]);
      } 
    } 
   } 
} 
int main(){
  int list[100];
  int n;
  scanf("%d", &n);

  for (int i = 0; i < n; i++){
    scanf("%d", &list[i]);
  }
  bubble_sort(list, n);
  for (int i = 0; i < n; i++){
     printf("%d ", list[i]);
  }
  return 0;
}