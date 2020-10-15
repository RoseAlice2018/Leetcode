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
            return NULL;
        queue<Node*> line;
        line.push(root);
        while(!line.empty())
        {
            queue<Node*> temp;
            while(!line.empty())
            {
                Node* t=line.front();
                temp.push(t);
                line.pop();
            }
            while(!temp.empty())
            {
                Node* t=temp.front();
                temp.pop();
                if(temp.empty())
                {
                    t->next=NULL;
                }
                else
                {
                    t->next=temp.front();
                }
                if(t->left)
                    line.push(t->left);
                if(t->right)
                    line.push(t->right);                
            }
        }
        return root;
    }
};
