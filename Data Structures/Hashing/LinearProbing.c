
#include <stdio.h>
#include<stdlib.h>
#define TABLE_SIZE 10

int h[TABLE_SIZE] = {NULL};

void insert(int key) {
   int loc,i;
   for(i=0;i<TABLE_SIZE;i++)
   {
       loc = (key + i) % TABLE_SIZE;
       if(h[loc] == NULL) {
          h[loc] = key;
           break;
       }
   }
   if(i == TABLE_SIZE) 
      printf("\nelement cannot be inserted\n");
}

void search(int key) {
 int i,loc;
 for(i=0;i<TABLE_SIZE; i++)
 {
    loc = (key + i) % TABLE_SIZE;
    if(h[loc] == key) {
      printf("value is found at index %d\n", loc);
      break;
    }
  }
  if(i == TABLE_SIZE)
    printf("\n value is not found\n");
}

void del(int key) {
 int i,loc;
 for(i=0;i<TABLE_SIZE; i++)
 {
    loc = (key + i) % TABLE_SIZE;
    if(h[loc] == key) {
       h[loc] = -1;
      break;
    }
  }
  if(i == TABLE_SIZE)
    printf("\n value is not found\n");
}

void display() {
  printf("\n Hash Table : \n");
  for(int i=0;i< TABLE_SIZE; i++)
      printf("h[%d] = %d\n",i, h[i]);
}

void showMenu() {
    printf("MENU -: \n1.Insert \n2.Display Hash Table\n3.Search\n4.Delete\n5.Exit\nPlease enter your choice -: ");
}

int main() {
    int opt, val;
    while(1) {
        showMenu();
        scanf("%d",&opt);
        switch(opt) {
            case 1: scanf("%d", &val); insert(val); break;
            case 2: display(); break;
            case 3: scanf("%d", &val); search(val); break;
            case 4: scanf("%d", &val); del(val); break;
            case 5: exit(0);
        }
    }
}