#include<stdio.h>
#define maxsize 1000
int queue[maxsize];
int front = -1, rear = -1;
int isEmpty() {
  if(front == -1 || front > rear)
      return 1;
   else
      return 0;
}
 
int isFull(){
	if(rear == (maxsize - 1))
		return 1;
	else
		return 0;
}
void enqueue(int x){
	if(isFull())
	{
			printf("Queue overflow !");
					return;
	}
	else if(isEmpty())
		front = rear = 0;
	else
		rear++;
		queue[rear] = x;
}
void dequeue(){
	if(isEmpty())
	{
		printf("Queue underflow !");
		return;
	}
	else if(front == rear)
			front = rear = -1;
	else
		front++;
}

void display_queue(){
	if(isEmpty()){
		printf("Queue underflow !");
		return;
	}
	for(int i=front;i<=rear;i++)
	    printf("%d ",queue[i]);
	printf("\n");
}
int main(){
	int size,x;
	printf("Enter the size of QUEUE : ");
		scanf("%d",&size);
	printf("Enter the elements in QUEUE : ");
	for(int i=0;i<size;i++){
		scanf("%d",&x);
		enqueue(x);
	}
		display_queue();
		dequeue();
		dequeue();
	    display_queue();
}
