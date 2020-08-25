
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
    ListNode* swapPairs(ListNode* head)
    {
        ListNode* res;
        if(head==NULL)
        {
            return NULL;
        }
        if(head->next!=NULL)
        {
            res=head->next;
        }
        else
        {
            res=head;
            return res;
        }
              
        ListNode* temp;
        ListNode* begin=head;
        while (begin!=NULL&&begin->next!=NULL&&begin->next->next!=NULL)
        {
            temp=begin->next;
            begin->next=temp->next;
            temp->next=begin;
            begin= begin->next;
            if(begin->next!=NULL)
            {
                temp->next->next=begin->next;
            }
            else
            {
                ;
            }
                       
        }
        if(begin->next!=NULL)
        {
            temp=begin->next;
            begin->next=temp->next;
            temp->next=begin;
            begin= begin->next;
        }
        return res;
    }
};