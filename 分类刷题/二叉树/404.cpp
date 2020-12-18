#include<iostream>
#include<queue>
#include<vector>
#include<string>
using namespace std;
 //* Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) 
    {
        int res=0;
        //TreeNode* father=new TreeNode(0,root,root);
        preorder(root,res,root);
        return res;
    }
    void preorder(TreeNode* root,int& res,TreeNode* father)
    {
        if(root==NULL)
            return;
        if(!root->left&&!root->right&&father->left==root)
         {   
             res+=root->val;
             return;
         }
        preorder(root->left,res,root);
        preorder(root->right,res,root);
    }
};