#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node *left,*right;
}*root1=NULL,*root2 = NULL;

struct node *insert(struct node *temp,int element)
{
	if(temp==NULL)
	{
        struct node *n=(struct node *)malloc(sizeof(struct node));
        n->data=element;
        n->left=n->right=NULL;
        temp=n;
    }
	else
	{
        int num;
        printf("Enter 1 for left and 2 for right : \n");
        scanf("%d",&num);
        if(num==1)
        {
            temp->left=insert(temp->left,element);
            printf("%d Inserted in left\n",element);
        }
        else if(num==2)
        {
            temp->right=insert(temp->right,element);
            printf("%d Inserted in right\n",element);
        }
    }
	return temp;
}

int mirror(struct node *root1,struct node * root2)
{
	if(root1->data != root2->data)
		return 0;
	else
		return 1;
mirror(root1->left,root2->right);
mirror(root1->right,root2->left);
}

int main()
{
	int n,i,element;
	printf("Enter the number of elements in binary tree 1 : ");
		scanf("%d",&n);
	for(i=0;i<n;i++)
	{
			printf("Enter the element : ");
	scanf("%d",&element);
	root1=insert(root1,element);
	}
	printf("Enter the number of elements in binary tree 2 : ");
		scanf("%d",&n);
	for(i=0;i<n;i++)
	{
			printf("Enter the element : ");
	scanf("%d",&element);
	root2=insert(root2,element);
	}
	int res = mirror(root1,root2);
	if(res == 1)
		printf("Mirror Tree !");
	else
		printf("Not a Mirror Tree !");
}
