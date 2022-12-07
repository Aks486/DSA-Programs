#include<stdio.h>
#include<stdlib.h>

typedef struct node
{ int data;
  struct node* next;
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

void display(node* head)
{  if(head==NULL)
	{ printf("\nList empty");
	  return;
	}
	do{
		printf("%d ",head->data);
		head=head->next;
	}while(head!=NULL);
	printf("\n");
}

node* split(node* head)
{ node *slow,*fast,*temp;
  slow=fast=head;
  while(fast->next!=NULL && fast->next->next!=NULL)
  {	slow=slow->next;
	fast=fast->next->next;
  }
  temp=slow->next;
  slow->next=NULL;
  return temp;
}