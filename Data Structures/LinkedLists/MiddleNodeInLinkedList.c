#include<stdio.h>
#include<stdlib.h>
struct node
{
 int data;
 struct node*next;
}*head=NULL,*tail=NULL;

struct node* create(int x) {
  struct node*n=(struct node*)malloc(sizeof(struct node));
   n->data=x;
   n->next=NULL;  
return n;
}

void insert(int x) {
  struct node*n = create(x);
    if(head==NULL)
    head=tail=n;
  else
  {
    tail->next=n;
    tail=n;
  }
}

int getMiddleNode(struct node *head)
{
    struct node  *slow_p = head, *fast_p = head;

    while (slow_p && fast_p && fast_p->next)
    {
        slow_p = slow_p->next;
        fast_p  = fast_p->next->next;
    }
    return slow_p->data;
}

int main()
{
 int n,x,i;
 printf("Enter the number of nodes: ");
 scanf("%d",&n);
 printf("Enter the nodes: ");
 for(i=0;i<n;i++)
 {
  scanf("%d",&x);
  insert(x);
 }
  printf("%d\n", getMiddleNode(head));
}
