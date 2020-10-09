
#include<stdio.h>
#include<stdlib.h>
struct node
{
 int data;
 struct node*next;
}*head=NULL,*tail=NULL;

int count=0,key;

void insert(int x)
{
  	struct node*n;
	 n=(struct node*)malloc(sizeof(struct node));
 	 n->data=x;
 	 n->next=NULL;
   	  if(head==NULL)
 	  	{
 		head=tail=n;
 		}
 		else
 		{
 		tail->next=n;
 		tail=n;
		}
}
int count_node(struct node*i)
{
  if(i==NULL)
	return count;
  	else
	{
	if(i->data==key)
 		count++;
	count_node(i->next);
	}
}
int main()
{
 int x,i;
 printf("Enter the number of nodes : ");
 scanf("%d",&x);
 int a[x];
 printf("Enter the nodes : ");
 for(i=0;i<x;i++)
 {
  scanf("%d",&a[i]);

 }
  for(i=0;i<x;i++)
  {
   insert(a[i]);
  }
  printf("Enter the key : ");
 scanf("%d",&key);
  count_node(head);
  printf(" Number of occurrences of given key %d in  linked list is %d ",key,count);

}
