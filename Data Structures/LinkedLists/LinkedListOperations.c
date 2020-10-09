#include<stdio.h>
#include<stdlib.h>
struct node
{
 int data;
 struct node*next;
}*head=NULL,*tail=NULL;

struct node* temp, *store_next;
int i;
struct node* create(int x)
{
	struct node*n=(struct node*)malloc(sizeof(struct node));
 	 n->data=x;
 	 n->next=NULL;	
return n;
}
void insert_end(int x)
{
	struct node*n = create(x);
   	if(head==NULL)
 		head=tail=n;
 	else
 	{
 		tail->next=n;
 		tail=n;

	}
}
void insert_begin(int x)
{
	struct node*n = create(x);
	if(head==NULL)
		head=tail=n;
	else
	{
		n->next = head;
		head = n;
	}
}
void insert_middle(int x,int pos)
{
	struct node*n = create(x);
	if(head==NULL)
		return;
	else if(pos==1)
		insert_begin(x);
	else
	{
		temp = head;
		for(i=2;i<pos;i++)
			temp=temp->next;
		store_next = temp->next;
		temp->next = n;
		n->next = store_next;
	}
}
void delete_begin()
{
	if(head==NULL)
		return;
	else
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}
void delete_end()
{
	if(head->next==NULL)
		head = NULL;
	else
	{
		temp = head;
		while(temp->next->next!=NULL)
			temp = temp->next;
		temp->next = NULL;
		free(temp->next);
	}
}
void delete_middle(int pos)
{
	if(head==NULL)
		return;
	else if(pos==1)
		delete_begin();
	else
	{
		temp = head;
		for(i=2;i<pos;i++)
			temp =temp->next;

		store_next = temp->next->next;
		free(temp->next);
		temp->next =  store_next;

	}
}
void reverse(struct node*head)
{
	struct node*prev=NULL,*temp=head;

	while(temp!=NULL)
	{
		store_next = temp->next;
		temp->next = prev;
		prev = temp;
		temp = store_next;
		temp = temp->next;
	}
	temp=prev;
}
void print(struct node* head)
{
	if(head==NULL)
		return;
	printf("Linked list : ");
	while(head!=NULL)
	{
		if(head->next!=NULL)
			printf("%d -> ",head->data);
		else
			printf("%d",head->data);
		head = head->next;
	}
}

int main()
{
 int n,x,pos;
 printf("Enter the number of nodes : ");
 scanf("%d",&n);
 printf("Enter the nodes : ");
 for(i=0;i<n;i++)
 {
  scanf("%d",&x);
  insert_end(x);
 }
 reverse(head);
  printf("\nEnter the value you want to insert at beginning : ");
 	scanf("%d",&x);
 	insert_begin(x);
 	print(head);
 printf("\nEnter the value and pos for inserting at middle : ");
 	scanf("%d%d",&x,&pos);
	 insert_middle(x,pos);
	 print(head);
 printf("\nEnter the pos for deleting : ");
 	 scanf("%d",&pos);
  	delete_middle(pos);
  	print(head);
delete_begin();
printf("\nDeleted at beginning !\n");
print(head);
delete_end();
printf("\nDeleted at end !\n");
print(head);
}
