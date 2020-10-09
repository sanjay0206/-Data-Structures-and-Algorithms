#include<stdio.h>
#include<stdlib.h>
struct AVL {
int data;
int height;
struct AVL* left;
struct AVL * right;
}* root = NULL,*k1,*k2;

int height( struct AVL * T)
{
    if (T == NULL)
	    return -1;
    else
		return T->height;
}
int max(int a, int b) {
  return (a > b) ? a : b;
}

struct AVL *right_rotation(struct AVL *k1)
{
    k2 = k1->left;
    k1->left = k2->right;
    k2->right = k1;
    k1->height = max(height(k1->left),height(k1->right))+1;
    k2->height = max(height(k2->left),height(k2->right))+1;
return k2;
}

struct AVL *left_rotation(struct AVL *k1)
{
    k2 = k1->right;
    k1->right = k2->left;
    k2->left = k1;
    k1->height = max(height(k1->left),height(k1->right))+1;
    k2->height = max(height(k2->left),height(k2->right))+1;
return k2;
}

struct AVL *left_right_rotation(struct AVL *k1)
{
    k1->left = left_rotation(k1->left);
return right_rotation(k1);
}

struct AVL *right_left_rotation(struct AVL *k1)
{
    k1->right = right_rotation(k1->right);
return left_rotation(k1);
}

int balanceFactor(struct AVL*T) {
  if (T == NULL)
    return 0;
  return height(T->left) - height(T->right);
}
struct AVL *create(int ele){
    struct AVL*n = (struct AVL*)malloc(sizeof(struct AVL));
    n->data = ele;
    n->height = 0;
    n->left =n->right = NULL;
return n;
}
struct AVL * insert(struct AVL *T,int ele){
    if(T == NULL)
        return create(ele);
    	    else if(ele < T->data)
			{
				T->left = insert(T->left,ele);
				if(balanceFactor(T) == 2)
				{
					if(ele < T->left->data)
						T = right_rotation(T);
					else
						T = left_right_rotation(T);
				}
			}
		    else if(ele > T->data)
			{
				T->right = insert(T->right,ele);
				if(balanceFactor(T)==-2)
				{
					if(ele > T->right->data)
						T = left_rotation(T);
					else
						T = right_left_rotation(T);
				}
			}
			else
				printf("Duplicate occurred \n");
	T->height = max(height(T->left),height(T->right))+1;
return T;
}
void inorder(struct AVL *T) {
  if (T)
  {
    inorder(T->left);
    printf("%d ",T->data);
    inorder(T->right);
  }
}
int main(){
	int n,i,ele;
	printf("Enter the number elements in AVL tree : ");
	scanf("%d",&n);
	printf("Enter the elements to be inserted in AVL tree : ");
	for(i=0;i<n;i++)
	{
		scanf("%d",&ele);
		root = insert(root,ele);
	}
	inorder(root);
}
