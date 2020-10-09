#include <stdio.h> 
int getMin(int arr[], int low, int high) { 
    if (high < low) 
    	return arr[0]; 
    if (high == low) 
    	return arr[low]; 
    int mid = (low + high)/2;
    if (mid < high && arr[mid+1] < arr[mid]) 
       return arr[mid+1]; 
    if (mid > low && arr[mid] < arr[mid - 1]) 
       return arr[mid]; 
    if (arr[high] > arr[mid]) 
       return getMin(arr, low, mid-1); 
    return getMin(arr, mid+1, high); 
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
        
      printf("%d\n",getMin(arr,0,n-1));
    
  }
}

  