#include<iostream>
#include<vector>
using namespace std;
 //* Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 
class Solution {
public:
    bool isSymmetric(TreeNode* root) 
    {
        if(root==NULL||((!root->left)&&(!root->right)))
            return true;
        else 
            return compare(root->left,root->right);
        return false;
    }
    bool compare(TreeNode* p,TreeNode* q)
    {
        if(p&&q)
        {
            if(p->val!=q->val)
                return false;
            return compare(p->left,q->right)&&compare(p->right,q->left);
        }
        else if((!p)&&(!q))
        {
           return true;
        }
        return false;
    }
};