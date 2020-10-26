#include<iostream>
#include<vector>
using namespace std;
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};

class Solution {
public:
    vector<Node*> dic;
    Node* treeToDoublyList(Node* root) 
    {
        if(root==NULL)
            return root;
        preorder(root);
        for(int i=1;i<dic.size()-1;i++)
        {
            dic[i]->left=dic[i-1];
            dic[i]->right=dic[i+1];
        }
        if(dic.size()>=2)
        {
            dic[0]->left=dic[dic.size()-1];
            dic[0]->right=dic[1];
            dic[dic.size()-1]->left=dic[dic.size()-2];
            dic[dic.size()-1]->right=dic[0];
        }
        else
        {
            dic[0]->right=dic[0];
            dic[0]->left=dic[0];
        }
        return dic[0];
    }
    void preorder(Node* root)
    {
        if(root==NULL)
            return ;
        preorder(root->left);
        dic.push_back(root);
        preorder(root->right);
    }
};