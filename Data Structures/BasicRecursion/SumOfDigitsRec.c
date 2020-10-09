#include<stdio.h>
long long int SodRecurs(int n)
{
	if(n==0)
		return 0;
	else
		return ( n%10+SodRecurs(n/10) );
}
int main()
{
	long long int n;
	printf("Enter the no: ");
	scanf("%d",&n);
	SodRecurs(n);
	printf("%d",SodRecurs(n));

}
