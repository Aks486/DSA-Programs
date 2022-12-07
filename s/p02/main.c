/*2. Consider two liked list A and B in sorted order. Write a program to merge the linked list
A and B such that the final list C is in sorted order.*/

#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int data;
	struct Node* next;
};

void printList(struct Node* head)
{
	struct Node* ptr = head;
	while (ptr!=NULL)
	{
		printf("%d —> ",ptr->data);
		ptr = ptr->next;
	}
	printf("NULL\n");
}

void push(struct Node** head, int data)
{
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->next = *head;
	*head = newNode;
}

void moveNode(struct Node** destRef, struct Node** sourceRef)
{
	if (*sourceRef == NULL)
		return;
	struct Node* newNode = *sourceRef;
	*sourceRef = (*sourceRef)->next;
	newNode->next = *destRef;
	*destRef = newNode;
}

struct Node* sortedMerge(struct Node* a, struct Node* b)
{
	struct Node dummy;
	dummy.next = NULL;
	struct Node* tail = &dummy;
	while (1)
	{
		if (a == NULL)
		{
			tail->next = b;
			break;
		}
		else if (b == NULL)
		{
			tail->next = a;
 			break;
		}	
		if (a->data <= b->data)
		{
			moveNode(&(tail->next), &a);
		}
		else
		{
			moveNode(&(tail->next), &b);
		}
		tail = tail->next;
	}
	return dummy.next;
}

int main(void)
{
	int keys[] = {1,2,3,4,5,6,7};
	int n = sizeof(keys)/sizeof(keys[0]);
	struct Node *a = NULL, *b = NULL;
	for (int i=n-1;i>=0;i=i-2) 
		push(&a, keys[i]);
	for (int i=n-2;i>=0;i=i-2) 
		push(&b, keys[i]);
	printf("First List: ");
	printList(a);
	printf("Second List: ");
	printList(b);
	struct Node* head = sortedMerge(a,b);
	printf("After Merge: ");
	printList(head);
	return 0;
}