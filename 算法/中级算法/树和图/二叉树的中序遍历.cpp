#include<iostream>
#include<vector>
#include<stack>
using namespace std;

// Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> Tr;
        TreeNode* now=root;
        vector<int> res;
        if(root==NULL)
            return res;
        else
        {
            while(now!=NULL||!Tr.empty())
            {
                while(now!=NULL)
                {
                    Tr.push(now);
                    now=now->left;
                }
                if(!Tr.empty())
                {
                    res.push_back(Tr.top()->val);
                    now=Tr.top()->right;
                    Tr.pop();
                }
            }            
        }
        return res;      
    }
};