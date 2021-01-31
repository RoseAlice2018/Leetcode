
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
 // Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL)
        {
            return head;
        }
        if(head->next!=NULL)
        {
            ListNode* new_head = reverseList(head->next);
            ListNode* p =new_head;
        while(p->next!=NULL)
        {
            p=p->next;
        }
        p->next=head;
        head->next=NULL;
        return new_head;
        }
        return head; 
        
    }
};