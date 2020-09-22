#include<iostream>
using namespace std;
//  Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 
class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        int lengthOfListnode=0;
        ListNode* tempHead=head;
        while(head!=NULL)
        {
            lengthOfListnode++;
            head=head->next;
        }
        lengthOfListnode=lengthOfListnode-k;
        while(lengthOfListnode--)
        {
            tempHead=tempHead->next;
        }
        return tempHead;
    }
};