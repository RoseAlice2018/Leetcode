class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
      // 增加一个哑结点
      ListNode* t=new ListNode(0);
      t->next=head;
      ListNode* p=head;
      ListNode* temp=t;
      ListNode* q=head;
      for(int i=1;i<=n;i++)
      {
          q=q->next;
      }
      while(q!=NULL)
      {
          temp=p;
          p=p->next;
          q=q->next;
      }
      // 删除p结点
        temp->next=p->next;
        return t->next;
    }
};