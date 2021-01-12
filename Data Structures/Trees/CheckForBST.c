#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct node {
    int data;
    struct node * left, *right;
}*root = NULL;

struct node *create(struct node * temp, int val) {
    temp = (struct node*)malloc(sizeof(struct node));
    temp->data = val;
    temp->left = temp->right = NULL;
return temp;
}

struct node *insert(struct node *temp,int element) {
	if(temp == NULL)
         return create(temp, element);
	else
	{
		if(element < temp->data)
            temp->left = insert(temp->left, element);
        else if(element > temp->data)
            temp->right = insert(temp->right, element);
     }
    return temp;
}

int validate (struct node* root, int left, int right) {
        if (root == NULL) 
            return 1;
        if ((left != NULL && root->data >= right) || (right != NULL && root->data <= left)) 
            return 0;
        return validate (root->left , left, root->data) && validate (root->right, root->data, right);
}

int  isBST(struct node* temp) { 
    return validate (temp, INT_MIN, INT_MAX);
}

int main() {
    int val, n;
    scanf("%d", &n);
    for(int i=0;i<n;i++) {
        scanf("%d", &val);
        root = insert(root, val);
    }
    isBST(root) == 1 ? printf("It is a BST") : printf("It is not a BST");
}
