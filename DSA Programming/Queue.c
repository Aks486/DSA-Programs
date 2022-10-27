#include<stdio.h>
#define SIZE 5
int front = -1;
int rear = -1;
int queue[SIZE];
void Enqueue(int ele){
	if(rear==SIZE-1)
		printf("Overflow\n");
	else if(front == -1 && rear== -1){
		front=rear=0;
		queue[rear]=ele;
	}else{
		queue[++rear]=ele;
	}
}
void Dequeue(){
	if(front == -1 && rear == -1)
		printf("Underflow\n");
	else if(front==rear)
		front=rear=-1;
	else{
		printf("\nRemoved %d",queue[front]);
		front++;
	}
}

void Display(){
	if(front == -1 && rear == -1)
		printf("Underflow\n");
	for(int i=front;i<rear+1;i++)
		printf("%d ",queue[i]);
}

int main(){
	Enqueue(1);
	Enqueue(2);
	Enqueue(3);
	Enqueue(4);
	Enqueue(5);
	Display();
	Dequeue();
	Dequeue();
	Dequeue();
	return 0;
}
