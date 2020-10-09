#include <stdio.h>
void insertionSort(int arr[], int n) {
    int i,j;
    for(i=1;i<n;i++){
	int key = arr[i];
	j = i-1;
        while(j >= 0 && arr[j] > key) {
		arr[j+1] = arr[j];
		j = j-1;
	}
	arr[j+1] = key;
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
        
      insertionSort(arr,n);
      printf("Sorted Array in Ascending Order:\n");
      printArray(arr,n);
  }
}
