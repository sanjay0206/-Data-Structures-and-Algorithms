#include <stdio.h>
int main() 
{
        int i,tc,a[100000],b[100000];
        int x,y,k,n,p;
        scanf("%d",&tc);
    while(tc--)
    {
        p=0;
        scanf("%d %d %d %d",&x,&y,&k,&n);
        for(i=0;i<n;i++)
             scanf("%d %d",&a[i],&b[i]);
        for(i=0;i<n;i++) {
            if(a[i]>=x-y && b[i]<=k)
                 p++;
        }
        if(p==0)
        printf("UnluckyChef\n");
            else
            printf("LuckyChef\n");
    }
	return 0;
}
