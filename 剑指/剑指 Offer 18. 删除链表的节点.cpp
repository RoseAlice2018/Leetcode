#include<iostream>
using namespace std;

 // Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 
class Solution {
public:
    ListNode* deleteNode(ListNode* head, int val) {
        ListNode* p=head;
        if(p->val==val)
            return head->next;
        while(p->next->val!=val)
            p=p->next;
        p->next=p->next->next;
        return head;
    }
};