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
    ListNode* swapPairs(ListNode* head) 
    {
        if(head==NULL)
            return head;
        ListNode* res;
        ListNode* prepre;
        ListNode* pre=head;
        ListNode* now=head->next;
        
        if(now==NULL)
            return head;
        ListNode* nextt=now->next;
        if(nextt==NULL)
        {
            //ListNode* temp=pre;
            now->next=pre;
            pre->next=NULL;
            return now;
        }
        //此时前三个结点完好
        //进行交换
        now->next=pre;
        pre->next=nextt;
        ListNode* temp=pre;
        pre=now;
        now=temp;
        prepre=pre;
        pre=pre->next;
        now=now->next;
        nextt=nextt->next;
        res=prepre;
        while(nextt!=NULL)
        {
            pre->next=nextt;
            now->next=nextt->next;
            nextt->next=now;
            temp=now;
            now=nextt;
            nextt=temp;
            if(nextt->next==NULL)
            {
                return res;
            }            
            else
            {
                now=nextt->next;
            }
            if(nextt->next->next==NULL)
            {
                return res;
            }
            else
            {
                nextt=nextt->next->next;
            }
            pre=pre->next->next;            
            
        }
         return res;
    }
};