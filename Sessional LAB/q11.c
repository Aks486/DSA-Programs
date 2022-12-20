# include <stdio.h>
# include <conio.h>
# include <stdlib.h>
 
typedef struct BST
{
    int data;
    struct BST *lchild,*rchild;
}node;
 
char name;
char position;
int id;
int salary;
 
void insert(node *,node *);
void inorder(node *);
node *search(node *,int,node **);
 
void main()
{
 int choice;
 char ans='N';
 int key;
 node *new_node,*root,*tmp,*parent;
 node *get_node();
 root=NULL;
 printf("\nEmployees list \n");
 do
 {
   printf("\n1.Create");
   printf("\n2.Search");
   printf("\n3.Recursive Traversals");
   printf("\n4.Exit");
   printf("\n\nEnter your choice: ");
   scanf("%d",&choice);
 
   switch(choice)
   {
    case 1:
           do
             {
             new_node=get_node();
 
             printf("\nInformation about employe with number: ");
             scanf("%d",&new_node->data);
             printf("\nName: ");
             scanf("%s",&name);
             printf("\nRank: ");
             scanf("%s",&position);
             printf("\nId. Number: ");
             scanf("%d",&id);
             printf("\nMonthly salary: ");
             scanf("%d",&salary);
             if(root==NULL)   /* Tree is not Created */
                 root=new_node;
             else
                insert(root,new_node);
             printf("\nDo you wish to enter a new employe?(y/n)");
             ans=getch();
             }while(ans=='y');
             break;
     case 2:
             printf("\nInsert the employe number you're looking for: ");
             scanf("%s",&key);
             tmp = search(root,key,&parent);
             printf("\nParent of node %d is %d",tmp->data,parent->data);
             break;
 
    case 3:
            if(root==NULL)
                printf("Tree Is Not Created");
            else
               {
                    printf("\nThe Inorder display: ");
                    inorder(root);
               }
 
            break;
    }
 }while(choice!=4);
}
/*
  Get new Node
*/
node *get_node()
 {
 node *temp;
 temp=(node *)malloc(sizeof(node));
 temp->lchild=NULL;
 temp->rchild=NULL;
 return temp;
 }
/*
  This function is for creating a binary search tree
*/
void insert(node *root,node *new_node)
{
  if(new_node->data < root->data)
     {
     if(root->lchild==NULL)
         root->lchild = new_node;
     else
         insert(root->lchild,new_node);
     }
 
  if(new_node->data > root->data)
     {
     if(root->rchild==NULL)
         root->rchild=new_node;
     else
         insert(root->rchild,new_node);
     }
}
/*
This function is for searching the node from
      binary Search Tree
*/
node *search(node *root,int key,node **parent)
{
 node *temp;
 temp=root;
    while(temp!=NULL)
    {
      if(temp->data==key)
         {
         printf("\n Employe with number %d is present",temp->data);
         return temp;
         }
      *parent=temp;
 
      if(temp->data>key)
         temp=temp->lchild;
      else
         temp=temp->rchild;
    }
 return NULL;
}
/*
This function displays the tree in inorder fashion
*/
void inorder(node *temp)
{
   if(temp!=NULL)
    {
    inorder(temp->lchild);
    printf("%d",temp->data);
    inorder(temp->rchild);
    }
}
