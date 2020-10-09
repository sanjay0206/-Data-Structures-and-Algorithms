#include<stdio.h>
#include<stdlib.h>
struct node
{
 int data;
 struct node*next;
}*head=NULL,*tail=NULL;
	int count=0;
struct node*i;
void insert(int x)
{
  	struct node*n;
	 n=(struct node*)malloc(sizeof(struct node));
 	 n->data=x;
 	 n->next=NULL;
   	if(head==NULL)
 		head=tail=n;
 	else
 	{
 		tail->next=n;
 		tail=n;
	}
}
int countNodesInLoop(struct node *head)
{
   int res = 1;
   struct node *temp = head; //head of slow_p
   while(temp->next != head) //LIKE CHECKING FOR CIRCULAR LINKED LIST
   {
      res++;
      temp=temp->next;
   }
   return res;
}
int identifyingLoop(struct node *head)
{
    struct node  *slow_p = head, *fast_p = head;

    while (slow_p && fast_p && fast_p->next)
    {
        slow_p = slow_p->next;
        fast_p  = fast_p->next->next;
        if (slow_p == fast_p)
            return countNodesInLoop(slow_p);
    }
}
void makeloop(struct node*head, int loop_pos)
{
    struct node* temp = head;
    int start_pos = 1;
    //To stop in the joining point
    while (start_pos < loop_pos)
	 {
        temp = temp->next;
        start_pos++;
    }
    //Set the stopping position as the joining point which is temp
    struct node* joint_point = temp;
    //Move until it reaches the last nose
    while (temp->next != NULL)
    {
    	 temp = temp->next;
	}
	//Set the next node of last node to the joining point
    temp->next = joint_point;
}
struct node* removeDuplicates(struct node* head)
 {

	for(i=head;i->next!=NULL;i=i->next)
	{
	    if(i->data==i->next->data)
	        i->next = i->next->next;
	}
return head;
}
struct node* removeDuplicatesRec(struct node* head)
{
	if(head==NULL)
	    return NULL;
	while(head->next!=NULL && head->data==head->next->data)
	{
	    head->next=head->next->next;
	}
	head->next=removeDuplicates(head->next);
return head;
}
void print()
{
	for(i=head;i!=NULL;i=i->next)
			printf("%d ",i->data);
}
int main()
{
 int n,x,i;
 printf("Enter the number of nodes : ");
 scanf("%d",&n);
 printf("Enter the nodes : ");
 for(i=0;i<n;i++)
 {
  scanf("%d",&x);
  insert(x);
 }
  /* Create a loop for testing
  int loop_pos;
  printf("Enter the loop position : ");
   scanf("%d",&loop_pos);
  makeloop(head,loop_pos);
   printf("Loop count = %d ", identifyingLoop(head)); */
   removeDuplicatesRec(head);
   print();
return 0;
}
