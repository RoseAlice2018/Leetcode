#include<iostream>
#include<vector>
#include<algorithm>
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
    ListNode* sortList(ListNode* head) 
    {
        vector<int> temp;
        ListNode* p=head;
        while (p!=NULL)
        {
            temp.push_back(p->val);
            p=p->next;
        }
        int len=temp.size();
        sort(temp.begin(),temp.begin()+len);
        ListNode* q=head;
        int i=0;
        while(q!=NULL)
        {
            q->val=temp[i++];
            q=q->next;
        }
        return head;        
    }
};