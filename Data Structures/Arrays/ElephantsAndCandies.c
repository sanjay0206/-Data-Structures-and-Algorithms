#include <stdio.h>
int main()
{
	int tc;
	scanf("%d",&tc);
	while(tc--)
	{
	    int candies,elephants,availableCandies;
	    scanf("%d%d",&elephants,&availableCandies);
	    int a[elephants],totalCandies=0;
	    for(candies=0;candies<elephants;candies++)
	    {
	         scanf("%d",&a[candies]);
	        totalCandies=totalCandies+a[candies];
	    }
	   if(totalCandies<=availableCandies)
	        printf("Yes\n");
	   else
	        printf("No\n");
    }
return 0;
}

