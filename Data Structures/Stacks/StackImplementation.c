#include <stdio.h>
#define maxsize 1000
int stack[maxsize], top = -1;

int isEmpty(){
    return top == -1;
}
int isFull(){
    return top == maxsize-1;
}
void push(int x){
    top++;
    stack[top] = x;
}
int pop(){
    int pop_ele = stack[top];
    top--;
return pop_ele;
}
void display_stack(){
    while(!isEmpty()){
        printf("%d\n",pop());
    }
}
int main(){
    int size,x;
    scanf("%d",&size);
    for(int i=0;i<size;i++){
        scanf("%d",&x);
        push(x);
    }
    display_stack();
}