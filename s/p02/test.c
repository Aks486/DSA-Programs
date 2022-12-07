#include <stdio.h>
#include <stdlib.h>


typedef struct node{
	int data;
	struct node *next;
}node;

node* insert(int arr[],int size)
{ node *head=NULL,*newnode,*temp;
  for(int i=0;i<size;i++)
  	{  if(head==NULL) 
  		{
  		 temp=head=(node*)malloc(sizeof(node));
  		 temp->data=arr[i];
  		}
  	    else
  	    { newnode=(node*)malloc(sizeof(node));
  		  newnode->data=arr[i];
  		  temp->next=newnode;
  		  temp=newnode;
  	    }
  	}
	temp->next=NULL;
	return head;
}


node* split(node *head)
{
	node *slow,*fast,*temp;
	slow=fast=head;
	while(fast->next!=NULL && fast->next->next!=NULL)
	{
		slow=slow->next;
		fast=fast->next->next;
	}
	temp=slow->next;
    slow->next=NULL;
    return temp;
}
void display(node *n)
{	if(n==NULL)
		return;
	while(n!=NULL){
	printf("%d ",n->data);
	n=n->next;
	}
	printf("\n");

}

void swap(int *a,int *b)
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}

node* merge(int a[],int n)
{
	node *temp;
	for(int i=0;i<n;i++){
		for(int j=0;j<n-i-1;j++){
			if(a[j]>a[j+1])
				swap(&a[j],&a[j+1]);
		}
	}
	temp=insert(a,n);
	return temp;
}
//Driver Code
int main(void)
{	int a[]={1,2,3,4,5,6,7,8,9};
	int n=sizeof(a)/sizeof(int);
	node *head=insert(a,n);
	node *sechalf=split(head);
	printf("Before Sorting: \n");
	display(head);
	display(sechalf);
	node *mergedList = merge(a,n);
	printf("After Sorting: \n");
	display(mergedList);
	return 0;
}
