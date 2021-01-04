#include<stdio.h>
#include<stdlib.h>
#define size 7

typedef struct node {
    int data;
    struct node *next;
}node;

node *chain[size],*head = NULL, *tail = NULL;

void init() {
    for(int i = 0; i < size; i++)
        chain[i] = NULL;
}

void insert(int value) {
    //create a newnode with value
    node *n = (struct node *)malloc(sizeof(struct node));
    n->data = value;
    n->next = NULL;

    //calculate hash key
    int key = value % size;

    //check if chain[key] is empty
    if(chain[key] == NULL)
        chain[key] = head = tail = n;

    //collision
    else {
        //add the node at the end of chain[key].
        tail->next = n;
        tail = n;
    }
}

// return 1 if search found, Otherwise return 0
int search(int value) {
    int key = value % size;
    struct node *temp = chain[key];
    while(temp) {
        if(temp->data == value)
            return 1;
        else
            temp = temp->next;
    }
    return 0;
}

//  return 1 for successful delete and  return 0 if value not found
int del(int value) {
    int key = value % size;
    struct node *temp = chain[key], *dealloc;
    if(temp != NULL) 
    {
        if(temp->data == value) { // if the value is found in the first node
            dealloc = temp;
            temp = temp->next;
            free(dealloc);
            return 1;
        }
        else {
                while(temp->next) // if we have last node 
                {
                    if(temp->next->data == value) // check for value of next node == value
                    {
                        dealloc = temp->next;
                        temp->next = temp->next->next;
                        free(dealloc);
                        return 1;
                    }
                    temp = temp->next; // if not the same then move 
                }
        }
    }
    return 0;
}

void print() {
    for(int i= 0; i < size; i++) {
        node *temp = chain[i];
        printf("chain[%d]-->",i);
        while(temp)
        {
            printf("%d -->",temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main() {
    //init array of list to NULL
    init();
    insert(7);
    insert(0);
    insert(3);
    insert(10);
    insert(4);
    insert(5);
    print();
    printf("\nSearching element 10\n");
    if(search(10))
        printf("Search Found\n\n");
    else
        printf("Search Not Found\n\n");
    if(del(10)) {
        printf("After Deletion of 10\n");
        print();
    }
    else
        printf("Value Not Present\n");
}