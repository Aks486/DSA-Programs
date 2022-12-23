#include <stdio.h>
#include <stdlib.h>

typedef struct  bstt
{ int data;
  struct bstt *lch,*rch;
}bstt;


bstt* create_bt();
void Inorder(bstt *);
void preorder(bstt *);
void postorder(bstt *);
void levelorder(bstt *);
int height(bstt *);
void levelorder(bstt *);
void printcurrentlevel(bstt *,int );

int main(void)
{
	bstt *root;
	root=create_bt();
	Inorder(root);
	printf("\n");
	preorder(root);
	printf("\n");
	postorder(root);
	printf("\n");
	levelorder(root);
	printf("\n");
	return 0;
}

bstt* create_bt()
{
	bstt *newnode=NULL;
	int d;
	printf("Enter data: ");
	scanf("%d",&d);
	if(d!=999)
	{   
		newnode=(bstt*)malloc(sizeof(bstt));
		newnode->data=d;
		printf("\nEnter the left child of %d\n",d);
		newnode->lch = create_bt();
		printf("\nEnter the right child of %d\n",d);
		newnode->rch = create_bt();
	}
	return newnode;
}

void Inorder(bstt *root)
{
  if(root)
  {
  	Inorder(root->lch);
  	printf("%d ",root->data);
  	Inorder(root->rch);
  }
}
void preorder(bstt *root)
{
  if(root)
  {
  	printf("%d ",root->data);
  	preorder(root->lch);
  	preorder(root->rch);
  }
}
void postorder(bstt *root)
{
  if(root)
  {
  	postorder(root->lch);
  	postorder(root->rch);
  	printf("%d ",root->data);
  }
}

int height(bstt *root)
{
	if(root==NULL)
		return 0;
	else{
		int lheight=height(root->lch);
		int rheight=height(root->rch);
		if(lheight>rheight)
			return lheight+1;
		else
			return rheight+1;
	}
}

void levelorder(bstt *root)
{
	int h=height(root);
	for(int i=1;i<=h;i++)
		printcurrentlevel(root,i);
}

void printcurrentlevel(bstt *root,int level)
{
	if(root==NULL)
		return;
	else if(level==1)
		printf("%d ",root->data);
	else if(level>1){
		printcurrentlevel(root->lch,level-1);
		printcurrentlevel(root->rch,level-1);
	}
}