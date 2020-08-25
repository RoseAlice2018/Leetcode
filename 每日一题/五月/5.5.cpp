#include<iostream>
using namespace std;
 // Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 
class Solution {
    int findmin(TreeNode* root)
    {
        int res=root->val;
        while(root->left!=NULL)
        {
            root=root->left;
            res=root->val;
        }
        return res;
    }
    int findmax(TreeNode* root)
    {
        int res=root->val;
        while(root->right!=NULL)
        {
            root=root->right;
            res=root->val;
        }
        return res;
    }

public:
    bool isValidBST(TreeNode* root) {
        if(root==NULL||(root->left==NULL&&root->right==NULL))
            return true;
        else if(root->left==NULL&&root->right!=NULL&&(root->val<findmin(root->right)))
        {
            return isValidBST(root->right);
        }
        else if(root->right==NULL&&root->left!=NULL&&(root->val>findmax(root->left)))
        {
            return isValidBST(root->left);
        }
        else if((root->left!=NULL&&root->right!=NULL)&&root->val<findmin(root->right)&&root->val>findmax(root->left))
        {
            return isValidBST(root->left)&&isValidBST(root->right);
        }
        else
        {
            return false;
        }
        return false;
    }
};