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

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    if (headA == NULL || headB == NULL) return NULL;

    ListNode *a = headA;
    ListNode *b = headB;

    while (a!=b) {
        a == NULL ? headB : a->next;
        b == NULL ? headA : b->next;
    }

    return a;

}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
