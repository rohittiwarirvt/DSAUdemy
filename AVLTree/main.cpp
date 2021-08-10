#include <iostream>

using namespace std;

class Node {

public:
  Node* lchild;
  int data;
  Node* rchild;
  int height;

};


class AVL {

public:
  Node* root;
  AVL() {
    root = nullptr;
  }

  // Helper method for inserting/deleting
  int NodeHeight(Node* p);
  int BalanceFactor(Node* p);
  Node* LLRotation(Node* p);
  Node* RRRotation(Node* p);
  Node* LRRotation(Node* p);
  Node* RLRotation(Node* p);
  Node* InPre(Node *p);
  Node* InSucc(Node *p);


  //Traversal
  void Inorder(Node *p);
  void Inorder(){ Inorder(root); }
  Node *getRoot() { return root;}

  // Insert
  Node* rInsert(Node* p, int key);

  // Delete

  Node* Delete(Node *p,int key);
};

void AVL::Inorder(Node *p) {
    if (p){
        Inorder(p->lchild);
        cout << p->data << ", " << flush;
        Inorder(p->rchild);
    }
}

Node* AVL::Delete(Node *p, int key) {
  if (p == nullptr) {
    return nullptr;
  }

  if (p->lchild == nullptr && p->rchild == nullptr) {
    if (p == root) {
      root == nullptr;
    }
    delete p;
    return nullptr;
  }

  if ( key < p->data) {
    p->lchild = Delete(p->lchild, key);
  } else if(key > p->data){
    p->rchild = Delete(p->rchild, key);
  } else {
     Node *q;

     if ( NodeHeight(p->lchild) > NodeHeight(p->rchild)) {
        q = InPre(p->lchild);
        p->data = q->data;
        p->lchild = Delete(p->lchild, q->data);

     } else {
        q = InSucc(p->rchild);
        p->data = q->data;
        p->rchild = Delete(p->rchild, q->data);
     }

  }

  // Update Height
  p->height = NodeHeight(p);


  // Balance Factor and Rotation;

  if ( BalanceFactor(p)  == 2 && BalanceFactor(p->lchild) ==1) {
     return LLRotation(p);

  } else if (BalanceFactor(p)  == 2 && BalanceFactor(p->lchild) ==-1) {
     return LRRotation(p);
  }else if (BalanceFactor(p)  == -2 && BalanceFactor(p->rchild) ==1){

    return RLRotation(p);
  }else if (BalanceFactor(p)  == -2 && BalanceFactor(p->rchild) == -1){
    return RRRotation(p);
  }else if (BalanceFactor(p)  == 2 && BalanceFactor(p->lchild) ==0) {
    LLRotation(p);
 } else if (BalanceFactor(p)  == -2 && BalanceFactor(p->rchild) ==0) {
    RRRotation(p);
 }

 return p;

}
Node* AVL::rInsert(Node* p, int key) {
 Node* temp;
 if ( p == nullptr) {
  temp = new Node();
  temp->lchild = nullptr;
  temp->rchild = nullptr;
  temp->data = key;
  temp->height =1;
  return temp;
 }

 if ( key < p->data) {
    p->lchild = rInsert(p->lchild, key);
 } else if (key> p->data){
    p->rchild = rInsert(p->rchild, key);
 }

 // update Height;
 p->height = NodeHeight(p);

 if ( BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == -1) {
     return LRRotation(p);
 } else if( BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == 1) {
     return LLRotation(p);
 } else if (BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == -1) {
     return RRRotation(p);
 } else if (BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == 1) {
     return RLRotation(p);
 }

 return p;
}

int AVL::NodeHeight(Node* p) {
  int hl, hr;

  hl = (p && p->lchild) ? p->lchild->height: 0;
  hr = (p && p->rchild) ? p->rchild->height: 0;

  return hl > hr ? hl +1: hr +1;
}

int AVL::BalanceFactor(Node* p) {
  int hl, hr;

  hl = (p && p->lchild) ? p->lchild->height: 0;
  hr = (p && p->rchild) ? p->rchild->height: 0;

  return hl - hr;
}

Node* AVL::LLRotation(Node* p) {
  Node *pl = p->lchild;
  Node *plr = pl->rchild;

  pl->rchild = p;
  p->lchild = plr;

  //Update height
  p->height = NodeHeight(p);
  pl->height = NodeHeight(pl);

  //Update root

  if (root==p) {
    root = pl;
  }

  return pl;
}


Node* AVL::RRRotation(Node *p) {
  Node *pr = p->rchild;
  Node  *prl = pr->lchild;


  pr->lchild = p;
  p->rchild = prl;

  // Update height;
  p->height = NodeHeight(p);
  pr->height = NodeHeight(pr);

  if (root == p) {
    root = pr;
  }

  return pr;
}

Node* AVL::LRRotation(Node *p) {
  Node *pl = p->lchild;
  Node *plr = pl->rchild;

  pl->rchild = plr ->lchild;
  p->lchild = plr->rchild;

  plr ->lchild = pl;
  plr ->rchild = p;

  p->height = NodeHeight(p);
  plr->height = NodeHeight(plr);
  pl->height = NodeHeight(pl);

  if ( root == p ) {
    root = plr;
  }

  return plr;

}

Node *AVL::RLRotation(Node *p) {
 Node *pr = p->rchild;
 Node *prl = pr->lchild;

 p->rchild = prl->lchild;
 pr->lchild = prl->rchild;

 prl->lchild = p;
 prl->rchild = pr;

  p->height = NodeHeight(p);
  prl->height = NodeHeight(prl);
  pr->height = NodeHeight(pr);

 if (root == p) {
  root = prl;
 }

 return prl;
}

Node* AVL::InSucc(Node *p) {
  while(p && p->lchild != nullptr) {
    p = p->lchild;
  }
  return p;
}

Node* AVL::InPre(Node *p) {
  while( p && p->rchild != nullptr) {
    p= p->rchild;
  }

  return p;
}

int main()
{
    AVL tree;
    int A[] = {10,20,30,25,28,27,5};
    for (int i=0; i<sizeof(A)/sizeof(A[0]); i++){
        tree.root = tree.rInsert(tree.root, A[i]);
    }

    tree.Inorder();
    cout << endl;

    tree.Delete(tree.root, 28);

    tree.Inorder();
    cout << endl;

    return 0;
}
