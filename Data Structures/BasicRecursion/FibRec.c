#include<stdio.h>

int FibRecurs(int n)
{
   if (n==0)
      return 0;
   else if (n==1)
      return 1;
   else
      return FibRecurs(n-1) + FibRecurs(n-2);
} 

int main()
{
	int n;
		printf("Enter the no: ");
		scanf("%d",&n);
		printf("%d",FibRecurs(n));
}
