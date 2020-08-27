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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int CF=0;
        ListNode* res=l1;
        ListNode* p;
        while (l1!=NULL)
        {
            p=l1;
            if(l2!=NULL)
            {
                int temp=l1->val+l2->val+CF;
                CF=0;
                if(temp<10)
                l1->val=temp;
                 else 
                {
                    l1->val=temp-10;
                     CF=1;
                }
                l1=l1->next;
                l2=l2->next;
            }
            else 
            {
                if(CF==1)
                {
                    int temp=l1->val+CF;
                    CF=0;
                    if(temp>=10)
                    {
                        l1->val=temp-10;
                        CF=1;
                    }
                    else
                    {
                        l1->val=temp;
                    }
                    l1=l1->next;                    
                }
                else
                {
                    break;
                }
                
            }
        }
        while(l2!=NULL)
        {
            if(CF==1)
            {
                
                int temp=l2->val+CF;
                CF=0;
                if(temp<10)
                {
                    l2->val=temp;
                    p->next=l2;
                    l2=l2->next;
                    p=p->next;
                }
                else
                {
                    l2->val=temp-10;
                    p->next=l2;
                    l2=l2->next;
                    p=p->next;
                    CF=1;
                }
                
            }
            else
            {
                p->next=l2;
                l2=l2->next;
                p=p->next;
            }
        }
        if(CF==1)
        {
            CF=0;
            ListNode* q=new ListNode(1);
            p->next=q;
        }
        return res;   
    }
};