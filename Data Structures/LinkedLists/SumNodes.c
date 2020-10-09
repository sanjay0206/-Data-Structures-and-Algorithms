
#include <stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node*next;
};
struct node*create(int x)
{
	struct node *n=(struct node*)malloc(sizeof(struct node));
	n->data=x;
	n->next=NULL;
return n;
}
struct node*insert(struct node*head,int x)
{
	struct node*n=create(x);
	if(head==NULL)
		head=n;
	else
		n->next=head;
		head=n;
	return head;
}

void display(struct node*head)
{
struct node*n=head;
	while(n)
	{
		printf("%d ",n->data);
		n=n->next;
	}
}
void sumList(struct node*head1,struct node*head2)
{
	int carry=0,oned,twod,sum;
	while(head1)
	{
		oned=head1->data;
		if(head2)
		{
			twod=head2->data;
			head2=head2->next;
		}
		else
			twod=0;
			sum=carry+oned+twod;
			if(sum>9)
				carry=sum/10;
			else
				carry=0;
			printf("%d ",sum%10);
			head1=head1->next;
	}
}
int main()
{
	int test;
	scanf("%d",&test);
	while(test--)
	{
		int n,m,i,x;
		struct node*head1=NULL,*head2=NULL;
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%d",&x);
			head1=insert(head1,x);
		}
		scanf("%d",&m);
		for(i=0;i<m;i++)
		{
			scanf("%d",&x);
			head2=insert(head2,x);
		}
		if(n>m)
		{
			sumList(head1,head2);
		}
		else
			sumList(head2,head1);
			printf("\n");
	}
	return 0;
}
