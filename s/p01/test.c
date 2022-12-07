#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct emp{
	char name[30];
	char des[1];
	float salary;
	int id;
	struct emp *next;
}emp;

emp *head = NULL;

emp* insert()
{ emp *new;
  new=(emp*)malloc(sizeof(emp));
  printf("Enter the name: ");
  scanf("%s",new->name);
  printf("Enter the ID: ");
  scanf("%d",&new->id);
  printf("Enter the Designation: ");
  scanf("%s",new->des);
  printf("Enter Salary: ");
  scanf("%f",&new->salary);
  if(head==NULL)
  { new->next=NULL;
	head=new;
  }else{
  	new->next=head;
  	head=new;
  }
  return head;
}

void search(emp *head,int id)
{	int flag=0;
	while(head!=NULL){ 
		if(head->id==id){
			printf("NAME: %s\tID: %d\tDesignation: %s\tSalary: %.2f",head->name,head->id,head->des,head->salary);
			flag=1;
			return;
		}
		head=head->next;
	}
	if(!flag)
		printf("Employee not found");
}


float display(emp *head)
{ int sum=0,count=0;
	char des[1];
	while(head!=NULL)
	{ strcpy(des,head->des);
		if(strcmp(des,"m")==0){
		sum+=head->salary;
		count++;
	}
	head=head->next;
	}
	return sum/count;
}


int main(void)
{
	int ch=0,id;
	do{
		printf("\n1>Insert\n2>Search\n3>Display average salary\n");
		printf("Enter your choice: ");
		scanf("%d",&ch);
		switch(ch){
		case 1:
			head=insert();
			break;
		case 2:

			printf("Enter the ID: ");
			scanf("%d",&id);
			search(head,id);
			break;
		case 3:
			//display();
			printf("Average Salary: %.2f",display(head));
			break;
		}
	}while(ch<4);
	return 0;
}