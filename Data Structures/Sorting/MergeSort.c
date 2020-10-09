#include <stdio.h>
void merge(int arr[], int low, int mid, int high) {
        int n = high - low + 1;
	// create a temp array
	int temp[n];
	
	// crawlers for both intervals and for temp
	int i = low, j = mid+1, k = 0;

	// traverse both arrays and in each iteration add smaller of both elements in temp 
	while(i <= mid && j <= high)
	{
		if(arr[i] <= arr[j]) 
			temp[k++] = arr[i++];
		else 
			temp[k++] = arr[j++];
	}

	// add elements left in the first interval 
	while(i <= mid) 
		temp[k++] = arr[i++];

	// add elements left in the second interval 
	while(j <= high) 
		temp[k++] = arr[j++];
	
	// copy temp to original interval
	for(i = low; i <= high; i++) 
		arr[i] = temp[i-low];
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
