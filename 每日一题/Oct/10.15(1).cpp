#include<iostream>
#include<queue>
using namespace  std;

 //Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};


class Solution 
{
public:
    Node* connect(Node* root) 
    {
        if(root==NULL)
        {
            return root;
        }
        Node* leftmost=root;
        while(leftmost->left)
        {
            Node* head=leftmost;
            while(head)
            {
                //connection 1
                head->left->next=head->right;
                //connection 2
                if(head->next)
                {
                    head->right->next=head->next->left;
                }
                else{
                     head->right->next=NULL;
                }
               
                head=head->next;
            }
            leftmost=leftmost->left;
        }
        return root;
    }
};
