#include<iostream>
using namespace std;
 // Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        double numa=l1->val,numb=l2->val;l1=l1->next;l2=l2->next;
        while (l1!=NULL)
        {
            numa=numa*10+l1->val;
            l1=l1->next;
        }
        while (l2!=NULL)
        {
            numb=numb*10+l2->val;
            l2=l2->next;
        }
       int sum=numa+numb;
        int c=0;
        for(int i=0;;i++)
            if(pow(10,i)>sum)
            {
                c=i-1;
                break;
            }
        ListNode* res=new ListNode(0);
        ListNode* p=res;
        if(sum==0)
        {
            return res;
        }
        while (sum>=0&&c>=0)
        {
            ListNode* tt=new ListNode(0);
            p->next=tt;
            int t=pow(10,c);
            double temp=(sum-sum%t)/t;
            tt->val=temp;
            p=p->next;
            sum=sum-temp*t;
            c--;
        }
        return res->next;     
        
        
    }
};