#include <stdio.h>
#include <stdlib.h>

/* Creation of structure */
struct node {
    int data;
    struct node * left, *right;
}*root = NULL;

/* Creation of node */
struct node *create(struct node * temp, int val) {
    temp = (struct node*)malloc(sizeof(struct node));
    temp->data = val;
    temp->left = temp->right = NULL;
return temp;
}

/* Inserting the elements to BT */ 
struct node *insert(struct node *temp,int element) {
	if(temp == NULL)
         temp =  create(temp, element);
	else
	{
	    int num;
	    printf("Enter 1 for left and 2 for right : \n");
	    scanf("%d", &num);
	   if(num == 1)
            temp->left = insert(temp->left, element);
        else if(num == 2)
            temp->right = insert(temp->right, element);
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

int main() {
    int n,val;
    printf("Enter the number of elements : ");
    scanf("%d", &n);
    for(int i=0;i<n;i++) {
        printf("Enter the  data : ");
        scanf("%d", &val);
        root = insert(root , val);
    }
    inorder(root);
}