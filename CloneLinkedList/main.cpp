#include <iostream>
//https://leetcode.com/problems/copy-list-with-random-pointer/
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

using namespace std;
class Node {
  public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

Node* cloneLinkedListWithRandomPointer(Node* head) {
    Node *iter = head;
    Node *front = head;

    // First rount is to make copy of each node.
    // and link them together side-by-side in a single list.
    while (iter != NULL) {
        front = iter->next;

        Node *copy = new Node(iter->val);
        iter->next = copy;
        copy->next = front;

        iter = front ;
    }

    // Second round: Assign random pointer to the cloned nodes.
    iter = head;
    while (iter != NULL) {
        if (iter ->random!= NULL) {
            iter->next->random = iter->random->next;
        }
        iter = iter->next->next;
    }

    // Third round:restore the origin list, and extract the copy list.
    iter = head;
    Node *pseudoHead = new Node(0);
    Node *copy  = pseudoHead;

    while (iter != NULL) {
        front = iter->next->next;

        // extract the copy
        copy->next = iter->next;

        // restore the original list
        iter->next = front;

        copy = copy->next;
        iter = front;
    }

    return pseudoHead->next;

}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
