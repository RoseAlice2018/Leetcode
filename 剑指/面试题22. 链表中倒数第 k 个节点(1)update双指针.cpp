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
      ListNode* former=head;
      ListNode* latter=head;
      int t=k-1;
      while(t--)
      {
          latter=latter->next;
      }
      while(latter->next!=NULL)
      {
          latter=latter->next;
          former=former->next;
      }
      return former;
    }
};