
#include<iostream>
using namespace std;
 // Definition for singly-linked list.
  struct ListNode
   {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 
class Solution {
public:
    ListNode* reversenode(ListNode* head)
    {
        if(head==NULL)
            return NULL;
        if(head->next==NULL)
            return head;
        ListNode* temp=reversenode(head->next);
        ListNode* res=temp;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        head->next=temp->next;
        temp->next=head;
        return res;
    }
    bool comparenode(ListNode* p,ListNode* q)
    {
        while(p!=NULL&&q!=NULL)
        {
            if(p->val!=q->val)
            {
                return false;
            }
            p=p->next;
            q=q->next;
        }
        return true;
    }
    bool isPalindrome(ListNode* head)
     {
         if(head==NULL)
            return true;
         if(head->next==NULL)
            return true;
        int size=0;
        ListNode* temp=head;
        while(head!=NULL)
        {
            size++;
            head=head->next;
        }
       
            int mid=(size+1)/2;
            ListNode* p=temp;
            int count=0;
            while(p!=NULL)
            {
                count++;
                p=p->next;
                if(count==mid)
                {
                    break;
                }
            }
            ListNode* q=reversenode(p);
            return comparenode(temp,q);
    }
};