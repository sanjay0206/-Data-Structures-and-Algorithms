#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node * next;
}*head = NULL, *tail = NULL;

struct node * n;

struct node * create(int val) {
    n = (struct node*)malloc(sizeof(struct node));
    n->data = val;
    n->next = NULL;
return n;
}

struct node * insert(int val) {
    n = create(val);
    if(head == NULL) 
        head = tail = n;
    else {
        tail->next = n;
        tail = n;
    }
    return head;
}

struct node* reverseList(struct node *head) {
     if (head == NULL) 
        return NULL;
     struct node *p, *q;
     p = head;
     q = p->next;
     if(q == NULL)
	       return p;
     q = reverseList(q);
        p->next->next = p;
        p->next = NULL;
    return q;
}

void printList(struct node *head) {
    while(head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main() {
    int n, val;
    scanf("%d", &n);
    for(int i=0;i<n;i++) {
        scanf("%d", &val);
        insert(val);
    }
    head = reverseList(head);
    printList(head);
}
