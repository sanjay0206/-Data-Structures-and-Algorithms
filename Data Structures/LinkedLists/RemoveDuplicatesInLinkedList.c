#include<stdio.h>
#include<stdlib.h>
struct node
{
 int data;
 struct node*next;
}*head=NULL,*tail=NULL;

void insert(int x) {
  	struct node*n;
	 n=(struct node*)malloc(sizeof(struct node));
 	 n->data=x;
 	 n->next=NULL;
   	if(head==NULL)
 		head=tail=n;
 	else
 	{
 		tail->next=n;
 		tail=n;
	}
}
//Using iterative
struct node* removeDuplicates(struct node* head) {
   if (head == NULL || head->next == NULL)
        return head;
    
   struct ListNode * i;
   for(i=head;i!= NULL && i->next!=NULL;) {
	if(i->val == i->next->val)
	        i->next = i->next->next;
        else
            i = i->next;
   }
return head;
}
//Using recursion
struct node* removeDuplicatesRec(struct node* head)
{
	if(head==NULL)
	    return NULL;
	while(head->next!=NULL && head->data==head->next->data)
	{
	    head->next=head->next->next;
	}
	head->next=removeDuplicates(head->next);
return head;
}
void print()
{
	for(i=head;i!=NULL;i=i->next)
			printf("%d ",i->data);
}
int main()
{
 int n,x,i;
 printf("Enter the number of nodes : ");
 scanf("%d",&n);
 printf("Enter the nodes : ");
 for(i=0;i<n;i++)
 {
  scanf("%d",&x);
  insert(x);
 }

   removeDuplicates(head);
   print();
return 0;
}
