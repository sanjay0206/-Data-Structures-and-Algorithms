#include<stdio.h>
int binarySearch(int a[],int low,int high,int key);
int main()
{
	printf("Enter the no. of elements : ");
	int n;
		scanf("%d",&n);
	int a[n];
	printf("Enter the elements : ");
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("Enter the key : ");
	int key;
		scanf("%d",&key);
	 int res= binarySearch(a, 0, n-1, key);
	 if(res== -1)
	 	printf("Key not found !");
	 else
	 	 printf("Key found at index  %d\n",res);
 }

int binarySearch(int a[], int low, int high, int key)
{
    if (low <= high)
    {
      int mid = (low + high) / 2;
    	if (a[mid] == key)
           return mid;
  	    else if (a[mid] > key)
       		 binarySearch(a, low, mid - 1, key);
	    	else if (a[mid] < key)
        	 binarySearch(a, mid + 1, high, key);
    	}
  	else
	  	return -1;
}
