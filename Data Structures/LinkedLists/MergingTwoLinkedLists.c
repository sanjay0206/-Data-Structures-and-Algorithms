#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *create(int x)
{
    struct node *n = (struct node *)malloc(sizeof(struct node));
    n->data = x;
    n->next = NULL;
    return n;
}

struct node *getLinkedList(int size)
{
    struct node *head = NULL,*tail = NULL,*n;
    int i,x;
    for(i = 0;i<size;i++)
	{
        scanf("%d",&x);
        n = create(x);
        if(head == NULL)
            head = tail = n;
        else
		{
            tail->next = n;
            tail = n;
        }
    }
    return head;
}


void print(struct node* head)
{
	struct node *i;
	for(i=head;i!=NULL;i=i->next)
			printf("%d ",i->data);
}
void merge(struct node * head1, struct node * head2)
 {
    if(head1!=NULL)
    {
        if(head1->next==NULL)
            head1->next=head2;
        else
      		merge(head1->next,head2);
    }
}

int main()
{
        int n,m,i;
        scanf("%d",&n);
        struct node *head1 = getLinkedList(n);
        scanf("%d",&m);
        struct node *head2 = getLinkedList(m);
        merge(head1,head2);
        print(head1);
    }
