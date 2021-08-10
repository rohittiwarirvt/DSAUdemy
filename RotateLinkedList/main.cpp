#include <iostream>
//https://leetcode.com/problems/rotate-list/description/
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

ListNode * rotateRightByK(ListNode* head, int k) {
    if (head == NULL || head->next == NULL || k =0) {
        return head;
    }

    ListNode *cur = head;
    int cnt =1;
    while (cur->next != NULL) {
        cnt++;
        cur = cur->next;
    }

    // go to that node
    cur->next = head;
    k = k % cnt;
    k = cnt -k;
    while (k--) {
        cur= cur->next;
    }

    // make the node head and break condition
    head = cur->next;
    cur->next = NULL;
    return head;
}


int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
