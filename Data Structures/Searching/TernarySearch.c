
#include<stdio.h>
int ternarySearch(int a[],int low,int high,int key);

int main() {
	printf("Enter the no. of elements : ");
	int n;
	scanf("%d",&n);
	int a[n];
	printf("Enter the elements : ");
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);

	int key;
	printf("Enter the key : ");
		scanf("%d",&key);
	 int res = ternarySearch(a, 0, n-1, key);
	 if(res == -1)
	 	printf("Key not found !");
	 else
	 	printf("Key found at index %d\n",res);
 }
int ternarySearch(int arr[], int low, int high, int key) {
	if (low <= high)
	{
		int left_mid = low + (high - low) / 3;
		int right_mid = high - (high - low) / 3;

		// int left_mid = (2*low + high)/3;
		// int right_mid = (low + 2*high)/3;

		if (arr[left_mid] == key)
			return left_mid;

		if (arr[right_mid] == key)
			return right_mid;

		if (arr[left_mid] > key)
			return ternarySearch(arr, low, left_mid-1, key);

		if (arr[right_mid] < key)
		    return ternarySearch(arr, right_mid+1, high, key);

	    return ternarySearch(arr, left_mid+1, right_mid-1, key);
	}
	return -1;
}
