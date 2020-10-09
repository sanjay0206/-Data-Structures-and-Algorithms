#include<stdio.h>
#include<math.h>
int isPrime(int n) 
{
	 	int flag=1;
       int size = (int)sqrt(n);
       for(int i=2; i<=size; i++) 
	   {
         if(n%i==0) 
         {
            flag=0;
			break;
 		 }
       } 
      return (flag==1);  			  
}
 int countPrimes(int n) 
 {
        n=n-1;
        int primeCount = 0;
        while(n>1) 
        {
            if(isPrime(n)==1) 
                primeCount++;
            n--;
        }   
        return primeCount;
    }
    
int main()
{
	int n;
	scanf("%d",&n);
	int i;
	for(i=2;i<=n;i++)
	{
		if(isPrime(i)==1)
	       printf("%d ",i);
	}
}
