#include <stdio.h>
void swap(int arr[],int i,int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
void bubbleSort(int arr[], int n) {
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j] > arr[j+1])
                swap(arr,j,j+1);
        }
    }
}
void printArray(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    printf("%d  ", arr[i]);
  }
  printf("\n");
}
int main() {
   int tc;
   scanf("%d",&tc);
  while(tc--) {
      int n;
      scanf("%d",&n);
      int arr[n];
      for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
        
      bubbleSort(arr,n);
      printf("Sorted Array in Ascending Order:\n");
      printArray(arr,n);
  }
}
