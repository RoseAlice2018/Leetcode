#include<iostream>
using namespace std;

//  Definition for singly-linked list.
  struct ListNode {
     int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
     {
         ListNode* head=new ListNode(0);
         ListNode* p=head;
         while(l1!=NULL&&l2!=NULL)
         {
             if(l1->val>l2->val)
             {
                 p->next=l2;
                
                 p=p->next; 
                 l2=l2->next;
             }
             else
             {
                 p->next=l1;
               
                 p=p->next;  
                 l1=l1->next;
             }
         }
         while(l1)
         {
             p->next=l1;
             l1=l1->next;
             p=p->next;
         }
         while(l2)
         {
             p->next=l2;
             l2=l2->next;
             p=p->next;
         }
         return head->next;
    }
};