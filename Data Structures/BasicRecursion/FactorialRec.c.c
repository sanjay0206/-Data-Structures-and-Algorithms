#include<stdio.h>
long long int FactRecurs(int n)
{

	if(n==0)
	{
		return 1;
	}
	else
	{
	return n*FactRecurs(n-1);
	}

}
int main()
{
	long long int n;
	printf("Enter the no: ");
	scanf("%d",&n);
	FactRecurs(n);
	printf("%d",FactRecurs(n));
	
}
