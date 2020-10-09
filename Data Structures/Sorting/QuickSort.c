#include <stdio.h>
void swap(int arr[],int i,int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
int partition(int arr[],int low,int high) {
	int pivot = arr[low];
	int start = low;
	int end = high;
	while(start < end)
	{
		while(arr[start] <= pivot) 
			start++;
		while(arr[end] > pivot) 
			end--;
		if(start < end)
			swap(arr,start,end);
	}
	swap(arr,low,end);
return end;
} 
void quickSort(int arr[], int low,int high) {
    if(low < high) {
	int loc = partition(arr,low,high);
	quickSort(arr,low,loc-1);
	quickSort(arr,loc+1,high);
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
        
      quickSort(arr,0,n);
      printf("Sorted Array in Ascending Order:\n");
      printArray(arr,n);
  }
}
