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

ListNode * reverseList(ListNode* head) {
    ListNode *newHead = NULL;
    while (head != NULL) {
        ListNode *next = head->next;
        head->next = newHead;
        newHead = head;
        head = next;
    }
    return newHead;
}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
