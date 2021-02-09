#include<iostream>
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
    ListNode* reverseList(ListNode* head) {
        ListNode* preNode=NULL;
        //preNode->next=head;
        ListNode* currentNode = head;
        while(currentNode!=NULL)
        {
            ListNode* next=currentNode->next;
            currentNode->next=preNode;
            preNode=currentNode;
            currentNode=next;
        } 
        return preNode;  
    }
};