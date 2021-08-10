#include <iostream>
#include "Queue.h"

using namespace std;


struct Node* root = NULL;

void tree_create() {
  struct Queue q;
  struct Node* parent, *temp;
  int x;
  create_queue(&q, 100);
  cout << "Enter the root value";
  scanf("%d", &x);
  root = (struct Node *)malloc(sizeof(struct Node));
  root->data = x;
  root->lchild = root->rchild = NULL;
  enqueue(&q, root);
  while(!isEmpty(q)) {
    parent = dequeue(&q);
    printf("Enter left child of %d", parent->data);
    scanf("%d", &x);
    if ( x != -1) {
      temp = (struct Node*)malloc(sizeof(struct Node));
      temp->data = x;
      temp->lchild = temp->rchild = NULL;
      parent->lchild = temp;
      enqueue(&q, temp);
    }
    printf("Enter right child of %d", parent->data);
    scanf("%d", &x);
    if ( x != -1) {
      temp = (struct Node*)malloc(sizeof(struct Node));
      temp->data = x;
      temp->lchild = temp->rchild = NULL;
      parent->rchild = temp;
      enqueue(&q, temp);
    }
  }
}

void preorder(struct Node * node) {
  if ( node != NULL) {
    printf("%d ", node->data);
    preorder(node->lchild);
    preorder(node->rchild);
  }
}

void inorder(struct Node * node) {
  if ( node != NULL) {
    inorder(node->lchild);
    printf("%d ", node->data);
    inorder(node->rchild);
  }
}

void postorder(struct Node * node) {
  if ( node != NULL) {
    postorder(node->lchild);
    postorder(node->rchild);
    printf("%d ", node->data);
  }
}

int main()
{
    tree_create();
    cout<<"PreOrder\n";
    preorder(root);
    cout<<"\nPost Order";
    postorder(root);
    cout<<"\nInorder";
    inorder(root);
    return 0;
}
