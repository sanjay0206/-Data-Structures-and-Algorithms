#include<stdio.h>
int i;
main()
{

	int size,pos,ele;
	int a[100];
		printf("enter size of array : ");
	scanf("%d",&size);
	printf("enter the elements : ");
		for(i=0;i<size;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("enter pos and ele : ");
	scanf("%d%d",&pos,&ele);
	int last=size-1;
	int index=pos-1;
	for(i=last;i>=index;i--)/*position/location=index+1 or index=position/location-1*/
	{
		a[i+1]=a[i];
	}
	a[index]=ele;
	for(i=0;i<size;i++)
	{
		printf("%d\n",a[i]);
	}
}
