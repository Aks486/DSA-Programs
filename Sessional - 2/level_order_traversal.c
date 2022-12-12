#include<stdio.h>
#include<stdlib.h>
#define MAX 10 

struct binarytree
{
        int info;
        struct binarytree *lchild;
        struct binarytree *rchild;
};
 
struct binarytree*  queue[MAX];
int front = -1,rear = -1;
void insert_queue(struct binarytree * vertex);
struct binarytree * delete_queue();
int isEmpty_queue();
 

struct binarytree * createBT();
void levelOrder(struct binarytree *);
int main()
{
        struct binarytree *root;
        root = NULL;
        root = createBT();
	levelOrder(root);
        return 0;
}

struct binarytree * createBT()
{
        struct binarytree *newNode;
        newNode = NULL;
        int data;

        printf("Enter the data : ");
        scanf("%d", &data);

        if(data != 999)
        {
                newNode = (struct binarytree *)malloc(sizeof(struct binarytree));
                newNode ->info = data;

                printf("Enter the left child of %d : ",data) ;
                newNode ->lchild = createBT();

                printf("Enter the right child of %d : ",data) ;
                newNode ->rchild = createBT();
        }
        return newNode;
}

void levelOrder(struct binarytree *root)
{
	if(root == NULL)
		return;
	insert_queue(root);

	for(;;)
	{
		if(!isEmpty_queue())
		{
			root=delete_queue();
			if(root)
			{
				printf("%d ",root->info);
				if(root->lchild)
					insert_queue(root->lchild);
				if(root->rchild)
					insert_queue(root->rchild);
			}
			else
				break;
		}
		else
			return;
	}
}

 
void insert_queue(struct binarytree * vertex)
{
	if(rear == MAX-1)
		printf("Queue Overflow\n");
	else
	{
		if(front == -1) 
			front = 0;
		rear = rear+1;
		queue[rear] = vertex ;
	}
}
 
int isEmpty_queue()
{
	if(front == -1 || front > rear)
		return 1;
	else
		return 0;
}
 
struct binarytree * delete_queue()
{
	struct binarytree * delete_item;
	if(front == -1 || front > rear)
	{
		printf("Queue Underflow\n");
		exit(1);
	}
	
	delete_item = queue[front];
	front = front+1;
	return delete_item;
}
