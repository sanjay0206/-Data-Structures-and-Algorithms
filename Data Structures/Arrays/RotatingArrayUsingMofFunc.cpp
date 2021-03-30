# include<bits/stdc++.h>

using namespace std;

void left_rotation(int arr[], int n, int k) {
	int *store =(int*)malloc(n * sizeof(int));
	for(int i = 0; i < n; i++) {
		store[i] = arr[i];
	}
	for(int i = 0; i < n; i++)
		arr[i] = store[(i+k)%n] ;
}

void right_rotation(int arr[], int n, int k) {
	int *store =(int*)malloc(n * sizeof(int));
	for(int i = 0; i < n; i++) {
		store[i] = arr[i];
	}
	for(int i = 0; i < n; i++)
		arr[i] = store[(i+n-k)%n] ;
}

int main() {
	int n, k;
	cin>>n>>k;
	
	int arr[n];
	for(int i=0; i<n; i++) {
		cin>>arr[i];
	}

	//left_rotation(arr, n, k);  
	right_rotation(arr, n, k);   
	for(int i = 0; i < n; i++) {
		cout<<arr[i]<<" ";
	}         
		
}

 
