#include <stdio.h>
#include <stdlib.h>

typedef struct binarytree
{
	int data;
	struct binarytree *lchild;
	struct binarytree *rchild;
}bt;

bt *createBT();

int main(void)
{
	bt *root=NULL;
	root = createBT();
	return 0;
}

bt* createBT()
{
	bt *newNode=NULL;
	int data;
	printf("Enter the data: ");
	scanf("%d",&data);
	if(data!=999)
	{
		newNode = (bt*)malloc(sizeof(bt));
		newNode ->info = data;
		printf("Enter the left child of %d: ",data) ;
		newNode ->lchild = createBT();
		printf("Enter the right child of %d: ",data) ;
		newNode ->rchild = createBT();
	}
	return newNode;
}
