#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int key;
  struct node *left, *right;
}node;

node *newNode(int item) {
  node *temp = (node*)malloc(sizeof(node));
  temp->key = item;
  temp->left = temp->right = NULL;
  return temp;
}

void inorder(node *root) {
  if (root != NULL) {
    // Traverse left
    inorder(root->left);
    // Traverse root
    printf("%d -> ", root->key);
    // Traverse right
    inorder(root->right);
  }
}

node* insert(node* node, int key) {
  // Return a new node if the tree is empty
  if (node == NULL) return newNode(key);
  // Traverse to the right place and insert the node
  if (key < node->key)
    node->left = insert(node->left, key);
  else
    node->right = insert(node->right, key);
  return node;
}

node* minValueNode(node* root) {
  node *current = root;
  // Find the leftmost leaf
  while (current && current->left != NULL)
    current = current->left;
  return current;
}

// Deleting a node
node* deleteNode(node *root, int key) {
  if (root == NULL) 
    return root;
  if (key < root->key)
    root->left = deleteNode(root->left, key);
  else if (key > root->key)
    root->right = deleteNode(root->right, key);
  else {
    if (root->left == NULL) {
      node *temp = root->right;
      free(root);
      return temp;
    } else if (root->right == NULL) {
      node *temp = root->left;
      free(root);
      return temp;
    }
    // If the node has two children
    node *temp = minValueNode(root->right);
    // Place the inorder successor in position of the node to be deleted
    root->key = temp->key;
    // Delete the inorder successor
    root->right = deleteNode(root->right, temp->key);
  }
  return root;
}


void search(node* root,int key)
{int flag=0;
  if(root==NULL)
    return;
  else if(key<root->key){
    root->left = search(root->left,key);
    if(key==root->key)
      flag=1;
  }
  else{
      root->right = search(root->right,key);
      if(key==root->key)
        flag=1;
  }
  if(flag==1)
    printf("Key -> %d is found",key);
}
int main(void) {
  node *root = NULL;
  root = insert(root, 8);
  root = insert(root, 3);
  root = insert(root, 1);
  root = insert(root, 6);
  root = insert(root, 7);
  root = insert(root, 10);
  root = insert(root, 14);
  root = insert(root, 4);
  printf("Inorder traversal: ");
  inorder(root);
  printf("\nAfter deleting 10\n");
  root = deleteNode(root, 10);
  printf("Inorder traversal: ");
  inorder(root);
  search(root,8);
}