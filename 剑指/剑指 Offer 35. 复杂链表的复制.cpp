#include<iostream>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL)
            return NULL;
        Node* p=new Node(head->val);
        Node* res=p;
        p->next=head->next;
        p->random=head->random;
        while(head->next!=NULL)
        {
            head=head->next;
            Node* q=new Node(head->val);
            q->next=head->next;
            q->random=head->random;
            p->next=q;
            p=p->next;
        }
        return res;
    }
};