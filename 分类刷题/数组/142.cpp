#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
 // Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
 class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast!=NULL&&fast->next!=NULL)
        {
            fast=fast->next->next;
            slow=slow->next;
            //fast come across the slow node there is a circle in the list
            if(fast == slow)
            {
                ListNode* index=head;
                ListNode* index1=fast;
                while(index!=index1)
                {
                    index=index->next;
                    index1=index1->next;
                }
                return index;
            }
        }
        return NULL;
    }
};