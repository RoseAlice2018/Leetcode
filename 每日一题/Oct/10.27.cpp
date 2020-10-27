#include<iostream>
using namespace std;
class Solution {
public:
    vector<int> res;
    vector<int> preorderTraversal(TreeNode* root) 
    {
        if(root==NULL)
        {
            return res;
        }
        preorder(root);
        return res;
    }
    void preorder(TreeNode* root)
    {
        if(root==NULL)
        {
            return ;
        }
        res.push_back(root->val);
        preorder(root->left);
        preorder(root->right);
    }
};