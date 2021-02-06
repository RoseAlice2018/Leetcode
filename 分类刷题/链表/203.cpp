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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* front = new ListNode();
        front->next=head;
        ListNode* p=front;
        while(p->next!=NULL)
        {
            if(p->next->val==val)
            {
                //find it
                p->next=p->next->next;
                //p=p->next;
            }
            else 
            {
                p=p->next;
            }
            if(p==NULL)
                break;
            
            if(p->next!=NULL&&p->next->next==NULL&&p->next->val==val)
            {
                p->next==NULL;
            }
        }
         return front->next;        
    }
};