#include <stdio.h>
#define SIZE 5

int queue[SIZE],front = -1, rear = -1;
int isFull() {
  if ((front == rear + 1) || (front == 0 && rear == SIZE - 1)) 
     return 1;
  return 0;
}
int isEmpty() {
  if (front == -1) 
    return 1;
  else
    return 0;
}
void enqueue(int x) {
  if (isFull())
    printf("\n Queue is full!! \n");
  else {
    if (front == -1) front++;
    rear = (rear + 1) % SIZE;
    queue[rear] = x;
    printf("\n Inserted -> %d", x);
  }
}

int dequeue() {
  if (isEmpty()) {
    printf("\n Can not deQueue the Queue is empty !! \n");
    return -1;
  } 
  else {
    int deq = queue[front];
    if (front == rear) {
      front = rear = -1;
    } 
    // Q has only one element, so we reset the 
    // queue after dequeing it. ?
    else 
      front = (front + 1) % SIZE;

    printf("\n Deleted element -> %d \n", deq);
    return deq; 
  }
}

void display_queue() {
  if (isEmpty())
    printf(" \n Empty Queue\n");
  else {
    printf("\n Front -> %d ", front);
    printf("\n Queue -> ");
    int i;
    for ( i = front; i != rear; i = (i + 1) % SIZE) {
      printf("%d ", queue[i]);
    }
    printf("%d ", queue[i]);
    printf("\n Rear -> %d \n", rear);
  }
}

int main() {
 dequeue();

 enqueue(1);
 enqueue(2);
 enqueue(3);
 enqueue(4);
 enqueue(5);

  enqueue(6);

   display_queue();
  dequeue();

   display_queue();

  enqueue(7);
   display_queue();

  enqueue(8);
}