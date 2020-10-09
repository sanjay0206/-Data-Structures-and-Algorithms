#include<stdio.h>
/*int checkForPrime(int);
int i;

int main()
{

    int n1,primeNo;

	printf("\n\n Recursion : Check a number is prime number or not :\n");
	printf("--------------------------------------------------------\n");

    printf(" Input any positive number : ");
    scanf("%d",&n1);

    i = n1/2;

    primeNo = checkForPrime(n1);//call the function checkForPrime

   if(primeNo==1)
        printf(" The number %d is a prime number. \n\n",n1);
   else
      printf(" The number %d is not a prime number. \nn",n1);
   return 0;
}

int checkForPrime(int n1)
{
    if(i==1)
    {
        return 1;
    }
    else if(n1 %i==0)
    {
         return 0;
    }
    else
       {
         i = i -1;
         checkForPrime(n1);//calling the function checkForPrime itself recursively
      }
}*/

/* Function declarations */
int isPrime(int num);
void printPrimes(int lowerLimit, int upperLimit);

int main()
{
    int lowerLimit, upperLimit;

    printf("Enter the lower and upper limit to list primes: ");
    scanf("%d%d", &lowerLimit, &upperLimit);

    // Call function to print all primes between the given range.
    printPrimes(lowerLimit, upperLimit);

    return 0;
}

/**
 * Print all prime numbers between lower limit and upper limit.
 */
void printPrimes(int lowerLimit, int upperLimit)
{
    printf("All prime number between %d to %d are: ", lowerLimit, upperLimit);

    while(lowerLimit <= upperLimit)
    {
        // Print if current number is prime.
        if(isPrime(lowerLimit))
        {
            printf("%d, ", lowerLimit);
        }

        lowerLimit++;
          }
}

/**
 * Check whether a number is prime or not.
 * Returns 1 if the number is prime otherwise 0.
 */
int isPrime(int num)
{
    int i;

    for(i=2; i<=num/2; i++)
    {
        /*
         * If the number is divisible by any number
         * other than 1 and self then it is not prime
         */
        if(num % i == 0)
        {
            return 0;
        }
    }

    return 1;
}
