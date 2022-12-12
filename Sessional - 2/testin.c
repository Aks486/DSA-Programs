#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node *lch;
	struct node *rch;
}node;


node* createBt()
{
	node *newnode=NULL;
	int val=0;
	printf("Enter the data(Enter -1 for creating no child node): ");
	scanf("%d",&val);
	if(val==-1)
		return 0;
	else{
		newnode=(node*)malloc(sizeof(node));
		newnode->data=val;
		printf("Enter the value for left-child of %d: ",val);
		newnode->lch=createBt();
		printf("Enter the value for right-child of %d: ",val);
		newnode->rch=createBt();
	}
	return newnode;
}


void InOrder(node *root)
{
	if(root){
		InOrder(root->lch);
		printf("%d ",root->data);
		InOrder(root->rch);
	}
}

int maxDepth(node* node)
{
    if (node == NULL)
        return 0;
    else {
        /* compute the depth of each subtree */
        int lDepth = maxDepth(node->lch);
        int rDepth = maxDepth(node->rch);
  
        /* use the larger one */
        if (lDepth > rDepth)
            return (lDepth + 1);
        else
            return (rDepth + 1);
    }
}

int main(void)
{
	printf("\n*****IN-ORDER BINARY TREE*****\n");
	node *root=NULL;
	root=createBt();
	printf("\nOutput from In-order Binary tree\n");
	InOrder(root);
	printf("\nMax Depth: %d\n",maxDepth(root));
	printf("\n*********************************\n");
	return 0;
}