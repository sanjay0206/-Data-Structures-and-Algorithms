#include <stdio.h>
int main()
{
	int tc;
	scanf("%d",&tc);
	while(tc--)
	{
	    int n,i,j;
	    scanf("%d",&n);
	    int a[n],count=0;
	    for(i=0;i<n;i++)
	         scanf("%d",&a[i]);
	    for (i=0;i<n;i++)
	    {
	        for(j=i+1;j<n;j++)
	        {
        	    if(i*a[i]>j*a[j])
	                 count++;
	        }
	    }
	printf("%d",count);
	printf("\n");
}
return 0;
}
