#include <stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node*next;
};
struct node* create(int data)
{
	struct node*n=(struct node*)malloc(sizeof(struct node));
	n->data=data;
	n->next=NULL;
return n;
}
struct node*insert(int size)
{
	struct node*head=NULL,*tail=NULL,*n;
	int i,data;
	for(i=0;i<size;i++)
	{
		scanf("%d",&data);
		n=create(data);
		if(head==NULL)
			head=tail=n;
		else
		{
			tail->next=n;
			tail=n;
		}
	}
	return head;
}
void print(struct node*head)
{
	int flag=0;
	if(head)
		flag=1;
	while(head)
	{
		printf("%d ",head->data);
		head=head->next;
	}
	if(flag==1)
		printf("\n");
}
void  insertAfter(struct node*p1,struct node*mid,struct node *p2)
{
	p1->next=mid;
	mid->next=p2;
}

void merge(struct node *head1, struct node *head2)
{
 	 struct node*p1_next,*p2_next,*head_back=head1;
 	 while(head1 && head2)
 	 {
 	 	p1_next=head1->next;
 	 	p2_next=head2->next;
 	 	insertAfter(head1,head2,head1->next);
 	 	/*Now the head1 and head2 are still pointing the same nodes so to move futher ,
 	 	assign the head1 to p1->next  and head2 to p2->next ,repeat this process until head1 is null*/
 	 	head1=p1_next;
 	 	head2=p2_next;
	  }
	print(head_back);//to print all nodes in head1
	print(head2);//to print all remaining nodes which are left out
}


int main()
{
	int test;
	scanf("%d",&test);
	while(test--)
	{
		int n,i,m,data;
		scanf("%d",&n);
		struct node*head1=insert(n);
		scanf("%d",&m);
		struct node*head2=insert(m);
		merge(head1,head2);
	}
}
