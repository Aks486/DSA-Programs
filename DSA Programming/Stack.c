#include<stdio.h>
#define SIZE 5
int top = -1;
void Pop(){
	if(top==-1)
		printf("Underflow!\n");
	else
		top--;
}

void Push(int arr[]){
	int ele;
	if(top==SIZE-1)	
		printf("Overflow\n");
	else{
		printf("Enter value to insert in stack: ");
		scanf("%d",&ele);
		top++;
		arr[top]=ele;	
	}
}
void Display(int arr[]){
	printf("The elements in stack are\n");
	for(int i=top;i>=0;i--){
		printf("%d\n",arr[i]);
	}	
}
int main(){
	int arr[SIZE];
	int choice=0;
	while(1){
		printf("Enter ur option:\n1>PUSH\n2>POP\n3>Display\n");
		scanf("%d",&choice);
		switch(choice){
			case 1: Push(arr);
					break;
			case 2: Pop();
					break;
			case 3: Display(arr);
					break;
			default:
					return 0;
		}
	}
	return 0;
}