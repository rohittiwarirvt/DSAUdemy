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

ListNode* removeNthElementFromEndOfLinkedList(ListNode* head, int n) {
    ListNode *start = new ListNode();
    start->next= head;
    ListNode *slow = start;
    ListNode *fast = start;

    for (int i =1 ; i<= n; i++) {
        fast= fast->next;
    }

    while (fast->next != NULL) {
        fast= fast->next;
        slow=slow->next;
    }
    slow->next = slow->next->next;

    return start->next;
}


int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
