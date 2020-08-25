#include<iostream>
#include<vector>
using namespace std;
 // Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 
class Solution {
public:
    ListNode* mergesort(ListNode* p,ListNode* q)
    {
        ListNode* res=new ListNode(0);
        ListNode* head=res;
        while (p!=NULL&&q!=NULL)
        {
            if(p->val<=q->val)
            {
                res->next=p;
                p=p->next;
                res=res->next;
            }
            else 
            {
                res->next=q;
                q=q->next;
                res=res->next;
            }
        }
        // have not done
        while (p!=NULL)
        {
           res->next=p;
           p=p->next;
            res=res->next;
        }
        while (q!=NULL)
        {
           res->next=q;
           q=q->next;
        res=res->next;
        }
        return head->next;    
        
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        if(lists.size()==NULL)
            return NULL;
        ListNode* res=lists[0];
        for(int i=1;i<lists.size();i++)
        {
            res=mergesort(res,lists[i]);
        }
        return res;
    }
};