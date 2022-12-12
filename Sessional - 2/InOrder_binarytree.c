#include <stdio.h>
#include <stdlib.h>
typedef struct binarytree
{
	int data;
	struct binarytree *lchild,*rchild;
}bt;

void InOrder(bt* );
bt* createBT();

int main(void)
{
	bt *root=NULL;
	root = createBT();
	InOrder(root);
	return 0;
}

bt* createBT()
{
	bt* newNode=NULL;
	int x;
	printf("Enter the data : ");
	scanf("%d", &data);
	if(data != 999)
	{
		newNode = (bt*)malloc(sizeof(bt));
		newNode ->data = x;
		printf("Enter the left child of %d : ",x) ;
		newNode ->lchild = createBT();
		printf("Enter the right child of %d : ",x) ;
		newNode ->rchild = createBT();
	}
	return newNode;
}
void InOrder(bt* root)
{
	if(root)
	{
		InOrder(root -> lchild);
		printf("%d ",root->data);
		InOrder(root -> rchild);
	}
}
