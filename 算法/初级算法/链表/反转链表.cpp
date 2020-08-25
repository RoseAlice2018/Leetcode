class Solution {
public:
    ListNode* reverseList(ListNode* head) 
    {
        if(head==NULL)
        {
            return NULL;
        }
        if(head->next==NULL)
        {
            return head;
        }
        ListNode* temp=reverseList(head->next);
        ListNode* res=temp;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        head->next=temp->next;
        temp->next=head;
        return res;
    }
};