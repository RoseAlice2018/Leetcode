#include<iostream>
using namespace std;
 //* Definition for singly-linked list.
  struct ListNode
   {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) 
    {
        if(head==NULL||head->next==NULL)
            return head;
        ListNode* first=head;
        ListNode* temp=head->next;
        
        return head;
    }
};