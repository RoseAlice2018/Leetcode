#include<iostream>
using namespace std;
class MyLinkedList {
private:
    struct LinkedNode{
        int val;
        LinkedNode* next;
        LinkedNode(int x):val(x),next(NULL){};
    };
    LinkedNode* head;
    LinkedNode* tail;
public:
    /** Initialize your data structure here. */
    MyLinkedList() {
        head=NULL;
        tail=NULL;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        LinkedNode* tmp=head;
        while(tmp!=NULL)
        {
            if(index==0)
                return tmp->val;
            index--;
            tmp=tmp->next;
        }
        return -1;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        LinkedNode* p =new LinkedNode(val);
        p->next=head;
        head=p;
        if(tail==NULL)
            tail=p;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        LinkedNode* p= new LinkedNode(val);
        if(tail!=NULL)
            tail->next=p;
        else 
        {
            if(head==NULL)
                head=p;
        }
        tail=p;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        LinkedNode* tmp=head;
        LinkedNode* new_val=new LinkedNode(val);
        if(index==0)
        {
            addAtHead(val);
            return;
        }
        while(tmp!=NULL&&tmp->next!=NULL)
        {
            if(index==1)
            {
                new_val->next=tmp->next;
                tmp->next=new_val;
                return;
            }
            index--;
            tmp=tmp->next;
        }
        return ;
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        LinkedNode* tmp=head;
        //LinkedNode* new_val=new LinkedNode(val);
        if(index==0)
        {
            head=head->next;
            return;
        }
        while(tmp!=NULL)
        {
            if(index==1)
            {
                LinkedNode* t=tmp->next;
                tmp->next=t->next;
                delete t;
                return;
            }
            index--;
            tmp=tmp->next;
        }
        return ;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */