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

bool hasCycle(LinkedList *head) {
    if (head == NULL || head->next == NULL) {
        return NULL;
    }

    ListNode *slow = head;
    ListNode *fast = head;
    while (fast->next && fast->next ->next) {
        fast = fast->next->next;
        slow = slow->next;

        if (fast == slow) {
            return true;
        }
    }
    return false;

}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
