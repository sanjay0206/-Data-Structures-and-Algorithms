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
  
void swap(struct node *a, struct node *b) { 
    int t = a->data; a->data = b->data; b->data = t; 
} 

struct node *bubbleSort(struct node *head)  { 
    bool swapped;
    struct node *p, *lptr = NULL; 
    if (head == NULL) 
        return NULL; 
    do
    { 
        swapped = false; 
        p = head; 
        while (p->next != lptr) 
        { 
            if (p->data > p->next->data) 
            {  
                swap(p, p->next); 
                swapped = true; 
            } 
            p = p->next; 
        } 
        lptr = p;  
    } 
    while (swapped); 
    return head;
} 

void print(struct node* head) {
	struct node *i;
	for(i=head;i!=NULL;i=i->next)
			printf("%d ",i->data);
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
     bubbleSort(head);
     print(head);
}