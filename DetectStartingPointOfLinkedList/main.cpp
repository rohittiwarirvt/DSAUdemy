#include <iostream>
//https://leetcode.com/problems/linked-list-cycle-ii/submissions/
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

ListNode* detectStartingPointOfLinkedList(ListNode *head) {
  if (head == NULL || head->next == NULL) {
    return NULL;
  }

  ListNode* fast = head;
  ListNode* slow = head;
  ListNode* entry = head;

  while ( fast->next && fast->next->next) {
      slow= slow->next;
      fast = fast->next->next;
      if (slow == fast ) {
          while (slow != entry) {
              slow= slow->next;
              entry= entry->next;
          }
          return entry;
      }
  }

  return NULL;
}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
