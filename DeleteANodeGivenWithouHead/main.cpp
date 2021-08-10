#include <iostream>

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

void deleteNode(ListNode* node) {
    node->val = node->next->val;
    node->next = node->next->next;
}
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
