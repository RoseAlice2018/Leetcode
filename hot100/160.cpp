#include<iostream>
using namespace std;
 //* Definition for singly-linked list.
  struct ListNode 
  {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
    {
        ListNode* res=NULL;
        ListNode* p;
        while(headA!=NULL)
        {
            int tag=0;
            p=headB;
            while (p!=NULL)
            {
                if(p==headA)
                {
                    res=p;
                    tag=1;
                    break;
                }
                p=p->next;
            }
            if(tag)
                break;
            headA=headA->next;            
        }
        return res;
    }
};