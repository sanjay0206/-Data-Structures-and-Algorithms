/*Considering that one of the problem constrians is -9 <= arr[i][j] <= 9

You can consider that the lowest Hourglass value will be the one where all the 7 values are -9.

Considering this, you only need to initialize max_value to -63 should be enough.*/

//possible hourglasses = (row-2)*(column-2)
#include<stdio.h>
int MaxhourglassSum=-63;
const int m=6,n=6;
int hourglass(int a[m][n],int i,int j)
{
	int row,col;
    int sum=0;
            for(row=i;row<i+3;row++){
                for(col=j;col<j+3;col++){
                    if(! ((row==i+1 && col==j) || (row==i+1 && col==j+2)) )
                        sum=sum+a[row][col];
          			  else
	     				continue;
                }
        }
        if(sum>MaxhourglassSum)
            MaxhourglassSum =sum;
}
int main()
{
	int i,j;
        int a[m][n];
        printf("Enter the (6x6) Martix : \n\n");
        for(i=0;i<m;i++){
        	for(j=0;j<n;j++){
            	scanf("%d",&a[i][j]);
			}
		}
   	 for(int i=0;i<m-2;i++){
        for(int j=0;j<n-2;j++){
			hourglass(a,i,j);
			}
		}
		printf("Maximum sum of an hourglass = %d",MaxhourglassSum);
	return 0;
}
