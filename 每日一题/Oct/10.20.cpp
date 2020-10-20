#include<iostream>
using namespace std;

// Definition for singly-linked list.
  struct ListNode 
  {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
class Solution {
public:
    void reorderList(ListNode* head)
     {
        if(head==NULL||head->next==NULL||head->next->next==NULL)
            return ;
        ListNode* end;
        ListNode* p;
        ListNode* q=head;
        p=head->next;
        while(p->next!=NULL)
         {   
             q=p;
             p=p->next;
         }
        end=p;
        end->next=head->next;
        q->next=NULL;
        head->next=end;
        if(end->next!=NULL)
            reorderList(end->next);
    }
};