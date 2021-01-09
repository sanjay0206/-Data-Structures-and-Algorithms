#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node {
 int data;
 struct node*next;
}*head=NULL,*tail=NULL;

struct node* temp, *store_next;
int i;
struct node* create(int x) {
	struct node*n=(struct node*)malloc(sizeof(struct node));
 	 n->data=x;
 	 n->next=NULL;	
return n;
}

void insert_end(int x) {
	struct node*n = create(x);
   	if(head==NULL)
 		head=tail=n;
 	else
 	{
 		tail->next=n;
 		tail=n;
	}
}

bool isPalindrome(struct node* head) {
    int len = 0, k = 0;
    struct node* p = head;
    while(p != NULL)
    {
        len++;
        p = p->next;
    }
    int *list = (int*)malloc(sizeof(int)*len);
    p = head;
    while(p != NULL){
        list[k++] = p->data;
        p = p->next;
    }
    for(i=0; i<len/2; i++)
    {
        if(list[i] != list[len - i - 1])
            return false;
    }
    return true;
}

int main() {
     int n,x;
     printf("Enter the number of nodes : ");
     scanf("%d",&n);
     printf("Enter the nodes : ");
     for(i=0;i<n;i++) {
      scanf("%d",&x);
      insert_end(x);
     }
     printf("%d", isPalindrome(head));
}
