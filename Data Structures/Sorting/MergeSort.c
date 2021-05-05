#include <stdio.h>
void merge(int arr[], int low, int mid, int high) {
    int n = high - low + 1;
    int aux[n];
    int i = low, j = mid + 1, k = 0;

    for(int k = low; k <= high; k++) 
        aux[k] = arr[k];
    
     for(int k = low; k <= high; k++) {
         if (i > mid) 
            arr[k] = aux[j++];
         if (j > high)
            arr[k] = aux[i++];
         else if (aux[i] > aux[j])
            arr[k] = aux[j++];
         else 
            arr[k] = aux[i++];
     }    
}

void mergeSort(int arr[], int start, int end) {
	if(start < end) {
		int mid = (start + end) / 2;
		mergeSort(arr, start, mid);
		mergeSort(arr, mid+1, end);
		merge(arr, start, mid, end);
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
        
      mergeSort(arr,0,n-1); // Pass n-1 elements instead of n since n-1 is the last element ie) from 0 to n-1
      printf("Sorted Array in Ascending Order:\n");
      printArray(arr,n);
  }
}
