#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
}*head1=NULL,*tail1=NULL,*head2=NULL,*tail2=NULL;
struct node *n;
void insert1(int x)
{	
	n=(struct node *)malloc(sizeof(struct node));
	n->data=x;
	n->next=NULL;
	if(head1==NULL)
		head1=tail1=n;
	else
	{
	tail1->next=n;
	tail1=n;
	}
}
void insert2(int y)
{
	n=(struct node *)malloc(sizeof(struct node));
	n->data=y;
	n->next=NULL;
	if(head2==NULL)
		head2=tail2=n;
	else
	{
	tail2->next=n;
	tail2=n;
	}
}
struct node* mergeLists(struct node * head1,struct node * head2)
{
    // handle end of list
if(head1 == NULL)
    return head2;

if(head2 == NULL)
    return head1;

// handle sorting
    if(head1->data < head2->data)
    {
      head1->next = mergeLists(head1->next, head2);
     	return head1;
    }
    else
    {
    head2->next = mergeLists(head1, head2->next);
   		return head2;
    }
}
struct node*print(struct node * head2)
{
	while(head2!=NULL)
	{
		printf("%d ",head2->data);
		head2=head2->next;
	}
}
int main()
{
	int n,m,x,y,i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
	scanf("%d",&x);
	insert1(x);
	}
	scanf("%d",&m);
	for(i=0;i<m;i++)
	{
	scanf("%d",&y);
	insert2(y);
	}
	mergeLists(head1,head2);
	print(head2);

return 0;
}
