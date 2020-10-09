#include <stdio.h>
int main()
{
    int tc;
	scanf("%d",&tc);
	while(tc--){
int n,i;
	     scanf("%d",&n);
	    int arr[n];
	    for(i=0;i<n;i++){
	        scanf("%d",&arr[i]);
	    }
	    for(i=0;i<n;i++){
	        printf("%d ", arr[arr[i]]);
	    }
	    printf("\n");
	}
	return 0;
}
