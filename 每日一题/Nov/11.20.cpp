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
        ListNode* end=head;
        ListNode* now=head->next;
        while(now!=NULL)
        {
            ListNode* q=now;
            now=now->next;
            insert(first,end,q);
        }
        return head;
    }
    void insert(ListNode* first,ListNode* end,ListNode* now)
    {
        ListNode* tempfirst=first;
        ListNode* tempend=end;
        if(now->val>end->val)
        {
            end->next=now;
            end=now;
            return;
        }
        if(now->val<first->val)
        {
            end->next=now->next;
            now->next=first;
            first=now;
            return;
        }
        while(tempfirst!=tempend)
        {
            if(tempfirst->val<=now->val&&tempfirst->next->val>=now->val)
            {
                tempend->next=now->next;
                now->next=tempfirst->next;
                tempfirst->next=now;
                //first=tempfirst;
                return;
            }
            tempfirst=tempfirst->next;
        }
    }
};