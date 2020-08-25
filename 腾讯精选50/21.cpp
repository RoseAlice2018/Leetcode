#include<iostream>
using namespace std;
// * Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
    {
        ListNode* left=l1;
        ListNode* right=l2;
        ListNode* head=new ListNode(0);
        ListNode* p=head;
        while (left!=NULL&&right!=NULL)
        {
            if(left->val>right->val)
            {
                // p->val=right->val;
                // ListNode* q=new ListNode(0);                
                // right=right->next;
                p->next=right;
                p=p->next;
                right=right->next;
            }
            else if(left->val<right->val)
            {
                // p->val=left->val;
                p->next=left;
                p=p->next;
                left=left->next;
            }
            else
            {
                p->next=right;
                p=p->next;
                p->next=left;
                left=left->next;
                right=right->next;
                p=p->next;
                // p->val=left->val;
                // ListNode* q=new ListNode(0);
                // left=left->next;
                // right=right->next;
                // p->next=q;
                // q->val=p->val;
                // p=q;
            }
        }
        while (left!=NULL)
        {
            p->next=left;
            p=p->next;
            left=left->next;
        }
        while (right!=NULL)
        {
            p->next=right;
            right=right->next;
            p=p->next;
        }
        
        
        return head->next;
    }
};