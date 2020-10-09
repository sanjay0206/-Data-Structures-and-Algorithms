#include<stdio.h>
int ternarySearch(int a[],int low,int high,int key);

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
	int key;
	printf("Enter the key : ");
		scanf("%d",&key);
	 int res = ternarySearch(a, 0, n-1, key);
	 if(res == -1)
	 	printf("Key not found !");
	 else
	 		printf("Key found at index %d\n",res);
 }

 int ternarySearch(int a[], int low, int high, int key) {
    if(low <= high) {
       int mid1 = (low + (high - low) /3); //mid of first and second block
       int mid2 = (mid1 + (high - low) /3); //mid of first and second block
       if(a[mid1] == key)
          return mid1;
       if(a[mid2] == key)
          return mid2;
       if(key < a[mid1])
          return ternarySearch(a, low, mid1-1, key);
       if(key > a[mid2])
          return ternarySearch(a, mid2+1, high, key);
       return ternarySearch(a, mid1+1, mid2-1, key);
    }
    return -1;
 }
