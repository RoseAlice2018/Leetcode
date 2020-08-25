#include<iostream>
using namespace std;

//  Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 
class Solution {
public:
    bool helper(TreeNode* root,long min,long max)
    {
        if(root==NULL)
            return true;
        if(root->val<=min||root->val>=max)
            return false;
        return helper(root->left,min,root->val)&&helper(root->right,root->val,max);        
    }
    bool isValidBST(TreeNode* root) 
    {
        return helper(root,INT64_MIN,INT64_MAX);
    }
};