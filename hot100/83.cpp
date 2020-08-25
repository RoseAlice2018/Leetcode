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
    ListNode* deleteDuplicates(ListNode* head)
     {
         ListNode* p=head;
         ListNode* res=head;
         while(p!=NULL)
         {
             ListNode* q=p->next;
             if(q==NULL)
             {
                 return res;
             }
             if(q->val==p->val)
             {
                 p->next=q->next;
             }
             else
             {
                 p=p->next;
             }
             

         }
         return res;
    }
};