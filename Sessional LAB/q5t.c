#include <stdio.h>

int n,top1=-1,top2;
int a[100];

void push1(int );
void push2(int );
void displaystack();

int main(void)
{
	int ch,ele;
	printf("Enter the size of the array: ");
	scanf("%d",&n);
	top2=n;
	do{
		printf("\n1> Push to stack 1\n2> Push to stack 2\n3> Display\n4> Exit : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: printf("Enter the element: ");
					scanf("%d",&ele);
					push1(ele);
					break;
			case 2: printf("Enter the element: ");
					scanf("%d",&ele);
					push2(ele);
					break;
			case 3:displaystack();
					break;
		}
	}while(ch!=4);
	return 0;
}


void push1(int ele)
{
	if((top1+1)==top2)
	{ printf("\nStack Overflow\n");
	  return;
	}else
		a[++top1]=ele;
}
void push2(int ele)
{
	if((top1+1)==top2)
	{ printf("\nStack Overflow\n");
	  return;
	}else
		a[--top2]=ele;
}
void displaystack()
{
	printf("\nStack - 1\n");
	for(int i=0;i<=top1;i++)
		printf("%d ",a[i]);
	printf("\nStack - 2\n");
	for(int i=n-1;i>=top2;i--)
		printf("%d ",a[i]);
}