#include<stdio.h>
 int main()
{
	int n;
	printf("Enter the no. of elements : ");
	scanf("%d",&n);
	int a[n];
	int i,key;
	printf("Enter the elements : ");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("Enter the key : ");
	scanf("%d",&key);
	for(i=0;i<n;i++)
	{
		if(a[i]==key)
		{
		printf("Element %d is found at position %d",a[i],i);
		break;
		}
	}
}
