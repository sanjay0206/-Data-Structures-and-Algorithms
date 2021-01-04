#include<stdio.h>
int arr[100];

void init(int size) {   
    for(int i = 0; i < size; i++) 
        arr[i] = -1;
}

void insert(int value, int size) {   
    int key = value % size;
    if(arr[key] == -1) {   
        arr[key] = value;
        printf("%d inserted at arr[%d]\n", value,key);
    }
    else {   
        printf("Collision : arr[%d] has element %d already!\n",key,arr[key]);
        printf("Unable to insert %d\n",value);
    }
}

void del(int value, int size) {
    int key = value % size;
    if(arr[key] == value)
        arr[key] = -1;
    else
        printf("%d not present in the hash table\n",value);
}

void search(int value, int size) {
    int key = value % size;
    if(arr[key] == value)
        printf("Search Found\n");
    else
        printf("Search Not Found\n");
}

void print(int size) {
    for(int i = 0; i < size; i++)
        printf("arr[%d] = %d\n",i,arr[i]);
    
    printf("\n");
}

void showMenu() {
    printf("MENU -: \n1.Insert \n2.Delete\n3.Search\n4.Display Hash Table\nPlease enter your choice -: ");
}

int main() {
    int n, val, choice, quit;
    printf("Enter the size of the hash table : ");
    scanf("%d", &n);
    init(n);
    do {  
        showMenu();
		scanf("%d", &choice);
		switch(choice) {
    		case 1:  scanf("%d", &val); insert(val, n); break;
    		case 2:  scanf("%d", &val); del(val, n); break;
    	        case 3:  scanf("%d", &val); search(val, n); break;
    		case 4:  print(n);  break;
    		default: printf("Wrong Input\n");
		}
		printf("\n Do you want to continue-:(press 1 for yes) \t");
		scanf("%d", &quit);
    } while(quit == 1);
}
