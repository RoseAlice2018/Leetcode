#include<iostream>
#include<queue>
using namespace std;

// Definition for a Node.
class Node 
{
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


class Solution {
public:
    Node* connect(Node* root)
     {
        Node* res;
        Node* t=NULL;
        if(root==NULL)
            return res;
        queue<Node*> temp;
        temp.push(root);
        temp.push(t);
        while(!temp.empty()&&temp.front()!=NULL)
        {
            Node* tt=temp.front();
            
            if(tt!=NULL)
            {
                if(tt->left!=NULL)
                  {
                      temp.push(tt->left);
                    }
                if(tt->right!=NULL)
                 {
                    temp.push(tt->right);
                    }
                    temp.pop();
                    tt->next=temp.front(); 
            }
            if(temp.front()==t)
            {
                temp.push(t);
                temp.pop();
            }
        }
        return root;
    }
};