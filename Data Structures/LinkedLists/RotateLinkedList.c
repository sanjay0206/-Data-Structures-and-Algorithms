#include<stdio.h>
#include<stdlib.h>
struct node
{
 int data;
 struct node*next;
}*head=NULL,*tail=NULL;

struct node* create(int x) {
  struct node*n=(struct node*)malloc(sizeof(struct node));
   n->data=x;
   n->next=NULL;  
return n;
}

void insert(int x) {
  struct node*n = create(x);
    if(head==NULL)
    head=tail=n;
  else
  {
    tail->next=n;
    tail=n;
  }
}
struct node* rotateRight(struct node* head, int k) {
    struct node* p, *q;
    p = head;
    if(p==NULL || k == 0) 
      return head;
    int n = 1;
    while(p->next){
        p=p->next;
        n++;
    }
    int off = n - k % n;
    if(off == n) 
      return head; 
    q = head;
    for(int i=1;i<off;i++)
        q = q->next;

    p->next = head;
    head = q->next;
    q->next = NULL;
 return head;
}

struct node* rotateLeft(struct node* head, int k) {
    struct node* p=head;
    if(p==NULL || k == 0) 
      return head;
    int n = 1;
    while(p->next){
        p=p->next;
        n++;
    }
    int off = k % n;
    if(off == n) 
      return head;
    struct node* q = head;
    for(int i=0;i<off-1;i++)
        q = q->next;

    p->next = head;
    head = q->next;
    q->next = NULL;
 return head;
}

void print(struct node* head)
{
  while(head != NULL) {
    printf("%d ", head->data);
    head = head->next;
  }
}

int main()
{
 int n,x,i,k;
 printf("Enter the number of nodes: ");
 scanf("%d",&n);
 printf("Enter the nodes: ");
 for(i=0;i<n;i++)
 {
  scanf("%d",&x);
  insert(x);
 }
 printf("Enter k: ");
 scanf("%d", &k);
  head = rotateRight(head,k);
  print(head);
}
