#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
}*head=NULL,*tail=NULL;
void insert(int x){
    struct node * n = (struct node *) malloc (sizeof (struct node));
    n -> data = x;
    n -> next = NULL;
   if(head==NULL)
   head=tail=n;
   else{
    tail->next=n;
    tail=n;
   }
}
void print(struct node* head)
{
	while(head!=NULL)
	{
		printf("%d ",head->data);
		head=head->next;
	}
}
int getLength(struct node* head) {
        int count = 0;
        struct node* temp=head;
        while (temp != NULL) {
            temp = temp->next;
            count++;
        }
        return count;
    }
 void delete_begin()
{
	struct node*temp=head;
	head=head->next;
	free(temp);
}
struct node* remove(struct node* head,int n)
{
	int i;
	int len = getLength(head);

    if(n==len)
      	delete_begin();

    else
    {//
    struct node*cur = head;//                    								1    2    3    4   5
	    for ( i = 1; i < len - n; i++ ) // here n=2 and len=5 -> len-n=3 -> step 1: 1<3 c=c->next so 2
		{//                                                                 step 2: 2<3 c=c->next so 3
	        cur = cur->next;//                                              step 3: 3<3 c=c->next->next so skips 4 and goes to 5
	    }
	    // After failing skip the node
	    cur->next = cur->next->next;
	}
 }
int main ()
{
 int size,x,i;
 printf("Enter the number of nodes : ");
 scanf("%d",&size);
 printf("Enter the nodes : ");
 for(i=0;i<size;i++)
 {
  scanf("%d",&x);
  insert(x);
 }
 int n;
 scanf("%d",&n);
  remove(head,n);
 print(head);
}
