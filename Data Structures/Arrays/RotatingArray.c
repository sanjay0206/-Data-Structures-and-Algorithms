#include <stdio.h>
int i;
void leftRotation(int a[],int n,int d)
{
	while(d--)
	{
        int first=a[0];
        for(i=0;i<n-1;i++)
        {
            a[i]=a[i+1];
        }
         a[i]=first;
    }
}
void rightRotation(int a[],int n,int d)
{
	while(d--)
	{
        int last=a[n-1];
        for(i=n-1;i>0;i--)
        {
            a[i]=a[i-1];
        }
         a[i]=last;
    }
}
void display(int a[],int n)
{
	for(i=0;i<n;i++)
        printf("%d ",a[i]);
}

int main()
{
  int n;
  printf("Enter the size of array : ");
  scanf("%d",&n);
  int a[n],d;
  printf("Enter the number of rotations : ");
    scanf("%d",&d);
    printf("Enter the array elements : ");
  for(i=0;i<n;i++)
  {
        scanf("%d",&a[i]);
    }
    int choice;

    while(1)
    {

    	printf("\nPress 1 for Left Rotation and Press 2 for Right Rotation \n");
	    printf("Enter the choice : ");
	    scanf("%d",&choice);
	    switch(choice)
	    {
	    	case 1: leftRotation(a,n,d);
	   					printf("Left Rotation : ");
	   				 display(a,n);
						break;
			case 2:  rightRotation(a,n,d);
	  				  printf("Right Rotation : ");
	    			display(a,n);
	    			break;
		}

	}
    return 0;
}
