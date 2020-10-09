#include <stdio.h>
void reverse(int a[],int start,int end) {
    int t;
    while(start<end)
    {
        t=a[start];
        a[start]=a[end];
        a[end]=t;
        start++;
        end--;
    }
}
void display(int a[],int n) { 
  for(int i=0;i<n;i++)
    printf("%d ",a[i]);
}
int main()
{
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    reverse(a,0,n-1);
    display(a,n);
}
