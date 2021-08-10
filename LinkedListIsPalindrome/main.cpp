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

bool isPalindrome(ListNode *head) {
    if (head == NULL or head->next == NULL) {
        return head;
    }

    ListNode *slow = head;
    ListNode *fast = head;
    while (fast->next != NULL && fast->next->next != NULL) {
        fast = fast->next->next;
        slow= slow->next;
    }

    slow->next = reverseList(slow->next);
    slow->next = slow->next;

    while ( slow != NULL) {
        if (head->val != slow->val) {
            return false;
        }
        head = head->next;
        slow = slow->next;
    }

    return true;

}

ListNode *reverList(ListNode *head) {
    ListNode *pre = NULL;
    ListNode *next = NULL;
    while (head != NULL) {
        next = head->next;
        head->next = pre;
        pre = head;
        head=next;
    }
    return pre;
}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
