#include <stdio.h>
#include <stdlib.h>
struct binarytree
{
	int info;
	struct binarytree * lchild;
	struct binarytree * rchild;
};
void PreOrder(struct binarytree *);
void PostOrder(struct binarytree *);
struct binarytree * createBT();
int main()
{
	struct binarytree *root;
	root = NULL;
	root = createBT();
	printf("\nPre order traversal :") ;
	PreOrder(root);
	printf("\nPost order traversal :") ;
	PostOrder(root);
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
void PreOrder(struct binarytree *root)
{
	if(root)
	{
		printf("%d",root->info);
		PreOrder(root -> lchild);
		PreOrder(root -> rchild);
	}
}
void PostOrder(struct binarytree *root)
{
	if(root)
	{
		PostOrder(root -> lchild);
		PostOrder(root -> rchild);
		printf("%d",root->info);
	}
}
