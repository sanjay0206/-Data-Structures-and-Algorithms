#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node *left,*right;
}*root=NULL;

struct node *insert(struct node *temp,int element) {
	if(temp==NULL)
	{
		temp=(struct node *)malloc(sizeof(struct node));
		temp->data=element;
		temp->left=temp->right=NULL;
	}
	else
	{
	   if(element < temp->data)
              temp->left = insert(temp->left, element);
           else if(element > temp->data)
              temp->right = insert(temp->right, element);
     }
        return temp;
}
void inorder(struct node*temp) {
	if(temp != NULL)
	{
		inorder(temp->left);
		printf("%d ", temp->data);
		inorder(temp->right);
	}
}
int addnodes(struct node* temp) {
	int sum;
	if(temp == NULL)
	    return 0;
	else
	    sum = temp->data + addnodes(temp->left) + addnodes(temp->right);
	return sum;
}

int main() {
	int n,i,element;
	scanf("%d",&n);
	for(i=0;i<n;i++) {
	    scanf("%d", &element);
		root = insert(root,element);
	}
	printf("Sum of all nodes in BST =  %d\n", addnodes(root));
}

