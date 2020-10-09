#include <stdio.h>
void swap(int arr[],int i,int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
void selectionSort(int arr[], int n) {

    for(int i=0;i<n-1;i++){
	int min = i;
        for(int j=i+1;j<n;j++){
            if(arr[j] < arr[min])
               min = j;
        }
	swap(arr,i,min);
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
        
      selectionSort(arr,n);
      printf("Sorted Array in Ascending Order:\n");
      printArray(arr,n);
  }
}
