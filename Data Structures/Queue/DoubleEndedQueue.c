#include<stdio.h>
#define maxsize 1000
int queue[maxsize];
int front = -1, rear = -1;

int isEmpty(){
	if(front==-1 && rear==-1)
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

void enqueue_rear(int x){
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
void dequeue_front(){
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
void dequeue_rear(){
	if(rear == -1)
	{
	printf("Queue underflow !");
	return;
	}
	else
		rear=rear-1;
}
void enqueue_front(int x){
	if(isFull())
	{
			printf("Queue overflow !");
					return;
	}
	else if(isEmpty())
		front = rear = 0;
	else if(front == 0)
		printf("Can not insert element in front ");
	else
	{
    	front--;
    	queue[front] = x;
	}
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
		enqueue_rear(x);
	}
		display_queue();
		dequeue_rear();
		display_queue();
		dequeue_front();
	    display_queue();
}
