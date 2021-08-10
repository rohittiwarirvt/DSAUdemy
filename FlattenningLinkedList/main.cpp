#include <iostream>
//https://practice.geeksforgeeks.org/problems/flattening-a-linked-list/1
/**
*   struct ListNode {
*       int val;
*       ListNode *next;
*       ListNode() : val(0), next(nullptr) {}
*       ListNode(int x): val(x), next(nullptr) {}
*       ListNode(int x, ListNode *next): val(x), next(next) {}
*    };
**/

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x): val(x), next(nullptr) {}
    ListNode(int x, ListNode *next): val(x), next(next) {}
}


ListNode * mergeList(ListNode * l1, ListNode *l2) {
    ListNode *temp = new ListNode(0);
    ListNode *res = temp;

    while (l1!=NULL || l2 !=NULL) {
        if (l1->val < l2->val) {
            temp->bottom=li;
            temp= temp->bottom;
            l1=l1->bottom;
        } else {
            temp->bottom=l2;
            temp = temp->bottom;
            l2=l2->next;
        }
    }

    if (l1) {
        temp->bottom=l1;
    }
    if (l2) {
        temp->bottom=l2;
    }

    return res->bottom;
}

ListNode* flatten(ListNode *root) {
    if (root == NULL || root->next =NULL) {
        return root;
    }

    // recur for list on right
    root->next = flatten(root->next);

    //now merge
    root = mergeTwo(root, root->next);

    // return the root
    // it will be in turn merged with it left.
    return root;
}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
