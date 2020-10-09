#include<stdio.h>
#include<math.h>

int ArmsRecurs(int n)
{
		int res;

	if(n==0)
	{
		return 0;
	}
	else
	{
	res= pow(n%10,3)+ArmsRecurs(n/10);
	}

}

int main()
{
	int n;
	printf("Enter the no: ");
	scanf("%d",&n);
	ArmsRecurs(n);

	printf("%d",ArmsRecurs(n));



}
