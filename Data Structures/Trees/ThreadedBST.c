#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *lc,*rc;
	int lf,rf;
}*root=NULL;
struct node *temp,*n;
struct node*create(int ele)
{
	n=(struct node*)malloc(sizeof(struct node));
	n->data=ele;
	n->lc=n->rc=NULL;
	n->lf=n->rf=1;
return n;
}
struct node* insert(struct node*root,int ele)
{
	if(root==NULL)
	{
	n=create(ele);
	root=n;
	}
	else
	{
	temp=root;
	while(temp!=NULL)
	{
		if(ele<temp->data)
		{
			if(temp->lf==0)
			temp=temp->lc;
				else
				{
				n=create(ele);
				n->rc=temp;
				temp->lc=n;
				temp->lf=0;
				}
		}
		else if(ele>temp->data)
		{
			if(temp->rf==0)
			temp=temp->rc;
				else
				{
				n=create(ele);
				n->rc=temp->rc;
				temp->rc=n;
				temp->rf=0;
				return root;
				}
		}
		else
			printf("Duplicates");
		}
	}
}
void inorder(struct node *root)
{
	temp=root;
	while(temp->lf==0)
		temp=temp->lc;
	while(temp!=NULL)
	{
		printf("%d ",temp->data);
		if(temp->rf==0)
		{
			temp=temp->rc;
			while(temp->lf==0)
				temp=temp->lc;
		}
		else
			temp=temp->rc;
	}
}
int main()
{
	int n;
	printf("Enter the no of elements : ");
	scanf("%d",&n);
	int element;
	int i;
	printf("Enter the elements : ");
	for(i=0;i<n;i++)
	{
	scanf("%d",&element);
	root=insert(root,element);
	}
	inorder(root);
}
