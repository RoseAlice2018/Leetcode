
 #include<iostream>
 #include<unordered_set>
 using namespace std;
 struct ListNode
  {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 
class Solution {
public:
    ListNode* removeDuplicateNodes(ListNode* head)
     {
         unordered_set<int> sample;
         if(head==NULL||head->next==NULL)
            return head;
         ListNode* p=head;
         sample.insert(head->val);
        while(p->next!=NULL)
        {
            int temp=p->next->val;
            if(sample.count(temp))
            {
                //have already appeared
                //skip the node;
                p->next=p->next->next;                
            }
            else
            {
                //first occur
                sample.insert(p->next->val);
                p=p->next;
            }
            
        }
        return head;
    }
};