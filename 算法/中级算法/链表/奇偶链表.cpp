#include<iostream>
using namespace std;
 //* Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL)
            return head;
        ListNode* p=head->next;
        if(p==NULL)
            return head;
        ListNode* res=head;
        ListNode* res2=p;
        while(head!=NULL&&p!=NULL)
        {
            head->next=p->next;
            if(p->next!=NULL)
            {
                p->next=p->next->next;
                 head=head->next;
                    p=p->next;
            }
            else
            {
                head->next=res2;
                return res;
            }
            
            
        }
        if(p==NULL)
        {
            head->next=res2;
        }
        return res;      

    }
};