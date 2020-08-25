#include<iostream>
using namespace std;
 //* Definition for singly-linked list.
  struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
  };

class Solution {
public:
    ListNode* reverseList(ListNode* head) 
    {
        if(head==NULL)
        {
            return NULL;
        }
        if(head->next==NULL)
        {
            return head;
        }
        ListNode* temp=reverseList(head->next);
        ListNode* res=temp;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        head->next=temp->next;
        temp->next=head;
        return res;
    }
};