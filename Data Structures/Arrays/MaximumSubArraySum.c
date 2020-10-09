#include <stdio.h>
#include <limits.h> 
int max(int a,int b,int c){
    return (a > b && a > c ? a : b > c ? b : c);
}
int maxCrossingSum(int a[],int l,int m,int h){
    int leftSum = INT_MIN, sum; 
    sum = 0;
    for(int i=m;i>=l;i--)
    {
        sum = sum + a[i];
        if(sum > leftSum)
            leftSum = sum;
    }
    int rightSum = INT_MIN ;
    sum = 0;
     for(int i=m+1;i<=h;i++)
      {
          sum = sum + a[i];
          if(sum > rightSum)
            rightSum = sum;
      }
  return max(leftSum+rightSum,leftSum,rightSum);
}
int maxSubArraySum(int a[],int l,int h){
    if(l == h)
        return a[l];
    int m = (l + h)/2;
    return max(maxSubArraySum(a,l,m),
               maxSubArraySum(a,m+1,h),
               maxCrossingSum(a,l,m,h));
}
int main()
{
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    printf("%d",maxSubArraySum(a,0,n-1));
    
}
