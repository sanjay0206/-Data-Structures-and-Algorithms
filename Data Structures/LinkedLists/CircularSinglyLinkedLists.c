#include<stdio.h>
#include<stdlib.h>
struct node
{
 int data;
 struct node*next;
}*head=NULL,*tail=NULL;

struct node* temp, *store_next;
int i;
struct node* create(int val)
{
	struct node* n= (struct node*)malloc(sizeof(struct node));
	n->data = val;
	n->next = head;
	return n;
}
void insert_end(int val)
{
	struct node *n = create(val);
	if(head==NULL)
		head=tail=n;
	else
	{
		tail->next=n;
       tail=n;
	}
}
void insert_begin(int val)
{
	struct node *n = create(val);
	if(head==NULL)
		head=tail=n;
	else
	{
		n->next=head;
		tail->next=n;
		head=n;
	}
}
void insert_middle(int val,int pos)
{
	struct node *n = create(val);
	if(pos==1)
		insert_begin(val);
	else
	{
		temp = head;
		for(i=2;i<pos;i++)
			temp=temp->next;

		store_next=temp->next;
		temp->next=n;
		n->next=store_next;
	}
}
void delete_begin()
{
   if(head == NULL)
     return;

     temp = head;
   if(temp->next == head)
         temp = NULL;
      else
	  {
         head = head -> next;
         tail->next = head;
      }
  }
void delete_end()
{
	if(head==NULL)
		return;
	else
	{
		temp=head;
			while(temp->next->next!=head)
				temp=temp->next;
		temp->next=head;
		tail=temp;
	}
}
void delete_middle(int pos,int size)
{
	if(head==NULL)
		return;
	else if(pos==1)
		delete_begin();
	else if(pos<=size)
	{
		temp=head;
		for(i=2;i<pos;i++)
			temp=temp->next;
		store_next = temp->next->next;
		temp->next = store_next;
	}
	else
		printf("No element in that position can not delete any element \n");
}

int isCircular(struct node *head)
{
    if (head == NULL)
       return 1;
  	temp = head->next;
	while (temp != NULL && temp!= head)
       temp = temp->next;
   return (temp == head);
}
void check(struct node *head)
{
	if(isCircular(head))
    	printf("\nyeah");
    else
    	printf("\nno");
}
void print(struct node* head)
{
	temp=head;
	while(temp->next!=head)
	{
		printf("%d -> ",temp->data);
		temp=temp->next;
	}
		printf("%d",temp->data);
}
int main ()
{
	 int size,val,pos,i;
	 printf("Enter the number of nodes : ");
	 scanf("%d",&size);
	 printf("Enter the nodes : ");
	 for(i=0;i<size;i++)
	 {
	  scanf("%d",&val);
	  insert_end(val);
	 }
	print(head);
	 check(head);
  printf("\nEnter the value you want to insert at beginning : ");
 	scanf("%d",&val);
 	insert_begin(val);
 	print(head);
 printf("\nEnter the value and pos for inserting at middle : ");
 	scanf("%d%d",&val,&pos);
	 insert_middle(val,pos);
	 print(head);
 printf("\nEnter the pos for deleting : ");
 	 scanf("%d",&pos);
  	delete_middle(pos,size);
  	print(head);
delete_begin();
printf("\nDeleted at beginning !\n");
print(head);
delete_end();
printf("\nDeleted at end !\n");
print(head);
}
