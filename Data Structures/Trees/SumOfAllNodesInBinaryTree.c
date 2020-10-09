#include<stdio.h>
#include<stdlib.h>

/*Creation of a structure*/
struct node
{
	int data;
	struct node *left,*right;
}*root=NULL;

/*Insertion of elements in a BST*/
struct node *insert(struct node *temp,int element)
{
	if(temp==NULL)
	{
        temp=(struct node *)malloc(sizeof(struct node));
        temp->data=element;
        temp->left=temp->right=NULL;
	}
	else
	{
		if(element<temp->data)
            temp->left=insert(temp->left,element);
        else if(element>temp->data)
            temp->right=insert(temp->right,element);
     }
        return temp;
}
void inorder(struct node*temp)
{
	if(temp!=NULL)
	{
		inorder(temp->left);
		printf("%d ",temp->data);
		inorder(temp->right);
	}
}
int addnodes(struct node* temp)
{
	int sum;
	if(temp==NULL)
		return 0;
	else
		 sum=temp->data+addnodes(temp->left)+addnodes(temp->right);
	return sum;
}
void lca(struct node*temp,int n1,int n2)
{
	int ans;
	if(temp->data<n1 && temp->data<n2)
					 lca(temp->right,n1,n2);
 else if(temp->data>n1 && temp->data>n2)
 	 lca(temp->left,n1,n2);
 	 else
 	 {
 	 	if(temp->right->data==NULL || temp->left->data==NULL)
 	 	temp->right->data=temp->left->data=0;
 	 	ans=temp->right->data+temp->left->data;
 	 		 printf("%d",ans-temp->data);
	  }

}


int main()
{
	int n,i,element,test,n1,n2;
	scanf("%d",&test);
	while(test--)
	{
				scanf("%d",&n);
			for(i=0;i<n;i++)
			{
			scanf("%d",&element);
			root=insert(root,element);
			}
			inorder(root);
			scanf("%d%d",&n1,&n2);
			lca(root,n1,n2);
			//int ans=trace(root,k,element);
			//printf("%d\n",ans);

	}
}
