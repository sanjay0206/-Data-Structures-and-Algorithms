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

/*inorder traversal*/
void inorder(struct node*temp)
{
	if(temp!=NULL)
	{
		inorder(temp->left);
		printf("%d ",temp->data);
		inorder(temp->right);
	}
}
void preorder(struct node*temp)
{
	if(temp!=NULL)
	{
		printf("%d ",temp->data);
		preorder(temp->left);
		preorder(temp->right);
	}
}
void postorder(struct node*temp)
{
	if(temp!=NULL)
	{
		postorder(temp->left);
		postorder(temp->right);
		printf("%d ",temp->data);
	}
}

/*Deletion of a node in BST*/
struct node *min(struct node*temp)
{
	if(temp==NULL)
		printf("The tree is empty");
	while(temp->left!=NULL)
	{
		temp=temp->left;
	}
	return temp;
}

struct node *del(struct node*temp,int element)
{
	struct node * delnode;
		if(temp==NULL)
			return 0;
		else
		{
			if(element==temp->data)
			{
				if(temp->left!=NULL&&temp->right!=NULL)
				{
				delnode=min(temp->right);//or you can also give delnode=min(temp);
				temp->data=delnode->data;
				temp->right=del(temp->right,temp->data);
				}
				else
				{
				delnode=temp;
					if(temp->left==NULL)
						temp=temp->right;
					else if(temp->right==NULL)
						temp=temp->left;
						free(delnode);
				}
			}
		else if(element<temp->data)
           	temp->left=del(temp->left,element);
   		else if(element>temp->data){
       		temp->right=del(temp->right,element);

        	}
     	}
     		return temp;
}

/*Height of a BST*/
int heightBST(struct node*temp)
{
	if(temp==NULL)
		 return -1;
  	else
   	{
  	int rh=heightBST(temp->right);
  	int lh=heightBST(temp->left);
		if(lh>rh)
 			return (lh+1);
    	else
			return (rh+1);
	}
}

/*Depth of a BST*/
int depthBST(struct node*temp,int element)
{
	if(temp==NULL)
		return -1;
	else
	{
		if(element==temp->data)
			return 0;
		else if(element<temp->data)
			return 1+depthBST(temp->left,element);
		else if(element>temp->data)
			return 1+depthBST(temp->right,element);
	}
}

/*Parent node*/
int parent(struct node*temp,struct node*p,int element)
{
	if(temp==NULL)
		return 0;
	else if(temp->data==element)
		printf("The PARENT of element %d is %d",element,p->data);
	else if(element<temp->data)
		parent(temp->left,temp,element);
	else if(element>temp->data)
		parent(temp->right,temp,element);
}

/*Sibling node*/
int sibling(struct node*temp,struct node*p,int element)
{
	if(temp==NULL)
		return -1;
	else
	{
		if(element<temp->data)
			return	sibling(temp->left,temp,element);
		else if(element>temp->data)
			return	sibling(temp->right,temp,element);
		else
		{
			if(element<p->data)
			{
				if(p->right!=NULL)
					return p->right->data;
				else
					return 0;
			}
			else if(element>p->data)
			{
				if(p->left!=NULL)
					return p->left->data;
				else
					return 0;
			}
		}
	}
}
/*Type of BST*/
int type(struct node *temp)
{
	if(temp==NULL)
	 	return 0;
	else
	{
		if(temp->data==root->data)
			printf("Root node is %d\n",temp->data);
		else if((temp->left!=NULL||temp->right!=NULL))
			printf("INTERNAL nodes is : %d\n ",temp->data);
		else
			printf("LEAF nodes is : %d \n",temp->data);
			type(temp->left);
			type(temp->right);
	}
}
int main()
{
	int i;
	printf("\tBinary Search Tree\t\t\t\t\t\t\n");
	for(i=1;i<40;i++)
		printf("-",i);
	printf("\n1. To insert elements ");
    printf("\n2. To delete a node ");
    printf("\n3. To traverse/Display the tree");
    printf("\n4. To find the parent node");
    printf("\n5. To find the sibling node");
    printf("\n6. To find the height of the tree");
    printf("\n7.  To find the depth of the tree");
    printf("\n8. To find the type of tree\n");
		int choice;
	while(1)
	{
		printf("\nEnter your choice:\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:/*Inserting elements*/
			printf("Your choice is to insert elements !\n");
					int i,n,element;
					printf("Enter no.of elements : ");
						scanf("%d",&n);
					printf("Enter the elements : ");

						for(i=0;i<n;i++)
						{
					        scanf("%d",&element);
					        root=insert(root,element);
						}
						break;

			case 2:	/*Deleting a node*/
						 printf("Your choice is to delete a node ! \n");
						int del_ele;
						printf("\nEnter the element you want to DELETE : ");
							scanf("%d",&del_ele);
							del(root,del_ele);
						break;
			case 3:	/*Traversals of BST*/
						 printf("Your choice is to traverse/Display the tree !\n");
						printf("\n The IN-ORDER TRAVERSAL is: ");
							inorder(root);
						printf("\n The PRE-ORDER TRAVERSAL is : ");
							preorder(root);
						printf("\n The POST-ORDER TRAVERSAL is : ");
							postorder(root);
					break;
			case 4:	/*To find the parent node*/
						 printf("Your choice is to find the parent node !\n");
						int p_ele;
						printf("\nEnter the element for which the PARENT is to be found : ");
							scanf("%d",&p_ele);
						parent(root,root,p_ele);
					break;
			case 5:  /*To find the sibling node*/
					printf("Your choice is to find the sibling node !\n");
					int sib_ele;
					printf("\nEnter the element for which the SIBLING is to be found : ");
						scanf("%d",&sib_ele);
					sibling(root,root,sib_ele);

					break;
			case 6:	/*To find the height of BST*/
			 printf("Your choice is to find the height of the tree !\n");
					int height;
					height=heightBST(root);
					printf("\nThe HEIGHT of BST is : %d",height);
					break;
			case 7:	/*To find the depth of BST*/
					 printf("Your choice is to find the depth of the tree !\n");
					int depth_ele;
					printf("\nEnter an element to get the DEPTH of that element :");
						scanf("%d",&depth_ele);
					int depth;
					depth=depthBST(root,depth_ele);
					printf("\nThe depth of BST is : %d",depth);
					break;
			case 8: /*To find the type of BSR*/
					type(root);
					break;
			default : printf("\nInvalid input try again !\n");
		}
	}
}
