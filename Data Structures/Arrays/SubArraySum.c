#include<stdio.h>
int sub(int a[],int n,int k)
{
     int i,sum=0,c=0;
        for(i=0;i<n;i++)
        {
            if(sum+a[i]<=k)
                sum=sum+a[i];
            else
            {
                sum=sum+a[i];
                while(sum>k)
                {
                  sum=sum-a[c];
                    c++;
                }
            }
            if(sum==k)
            {
               printf("%d %d",c+1,i+1);
               break;
            }
               
        }
    return 0;
}

int main()
{
       int t;
       printf("Enter the test cases\n");
       scanf("%d",&t);
        while(t--)
        {
            int i,n,k;
            scanf("%d%d",&n,&k);
            int a[n];
            for(i=0;i<n;i++)
            {
               scanf("%d",&a[i]);
            }
           sub(a,n,k);
            
        }
	
}
