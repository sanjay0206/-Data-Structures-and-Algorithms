/*Considering that one of the problem constriants is -9 <= arr[i][j] <= 9

You can consider that the lowest Hourglass value will be the one where all the 7 values are -9.

Considering this, you only need to initialize max_value to -63(ie 6 * -9 = -63) should be enough.*/

//possible hourglasses = (row-2)*(column-2)
/*Considering that one of the problem constriants is -9 <= arr[i][j] <= 9

You can consider that the lowest Hourglass value will be the one where all the 7 values are -9.

Considering this, you only need to initialize max_value to -63(ie 7 * -9 = -63) hould be enough.*/

//possible hourglasses = (row-2)*(column-2)
#include<stdio.h>
#include<math.h>

int maxHourGlassSum = -63;
int hourglass(int arr[6][6]) {
        for(int i = 0; i < 4; i++) {
            for(int j = 0; j < 4; j++) {
                int currentHourGlassSum =
                // first row
                        arr[i][j] +
                        arr[i][j+1] +
                        arr[i][j+2] +
                // middle element
                        arr[i+1][j+1] +
                // last row
                        arr[i+2][j] +
                        arr[i+2][j+1] +
                        arr[i+2][j+2];

                maxHourGlassSum = fmax(maxHourGlassSum, currentHourGlassSum);
            }
        }
        return maxHourGlassSum;
}
int main() {
    const int m = 6, n = 6;
    int a[m][n];
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            scanf("%d",&a[i][j]);
		
   	 for(int i=0;i<m-2;i++)
        for(int j=0;j<n-2;j++)
			hourglass(a);
	
		printf("%d",maxHourGlassSum);
}

/* ################################################################################################################# */
// Method 2

#include<stdio.h>
int MaxhourglassSum = -63;
int hourglass(int a[6][6],int i,int j) {
    int sum=0;
    for(int row=i;row<i+3;row++){
        for(int col=j;col<j+3;col++){
            if(! ((row == i+1 && col == j) || (row == i+1 && col == j+2)) )
                sum = sum + a[row][col];
            else
	     	continue;
        }
    }
        if(sum > MaxhourglassSum)
            MaxhourglassSum = sum;

    return sum;
}

int main() {
    const int m = 6, n = 6;
    int a[m][n];
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            scanf("%d",&a[i][j]);
		
    for(int i=0;i<m-2;i++)
        for(int j=0;j<n-2;j++)
	     hourglass(a,i,j);
	
    printf("%d",MaxhourglassSum);
}
