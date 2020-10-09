#include <stdio.h>
int main()
{
	int tc;
	scanf("%d",&tc);
	while(tc--)
	{
	    int workers,min;
		scanf("%d",&workers);
		int salary,a[workers];
		for(salary=0;salary<workers;salary++)
		{
			scanf("%d",&a[salary]);
		}
		min=a[0];
		for(salary=0;salary<workers;salary++)
			{
				if(a[salary]<min)
					min=a[salary];
			}
		int sum=0;
		for(salary=0;salary<workers;salary++)
		{
			sum=sum+(a[salary]-min);
		}
		printf("%d\n",sum);
	}
return 0;
}


