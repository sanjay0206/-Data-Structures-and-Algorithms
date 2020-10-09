#include<stdio.h>
int main()
{
	int m,n,i;
	int a[100],b[100],c[100]={0};
	//getting size of 1st array
	printf("Enter the no. of elements in the 1st array : ");
		scanf("%d",&m);
	//getting array elements of 1st array
	printf("Enter the elements : ");
	for(i=0;i<m;i++)
		scanf("%d",&a[i]);
	//getting size of 2nd array
	printf("Enter the no. of elements in the 2st array : ");
		scanf("%d",&n);
	//getting array elements of 2nd array
	printf("Enter the elements : ");
	for(i=0;i<n;i++)
		scanf("%d",&b[i]);
	//merging array elements of b[] to a[] (ie) adding elements of b[] to the end of a[]
	for(i=0;i<n;i++)
		a[m+i]=b[i];
	//copying a[] to 3rd array c[]
	for(i=0;i<m+n;i++)
		c[i]=a[i];

	printf("The merged array is : ");
	for(i=0;i<m+n;i++)
		printf("%d ",c[i]);
}
