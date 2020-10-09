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
public:
    int res,count=0;
    int kthLargest(TreeNode* root, int k)
     {
         dfs(root,k);
         return res;
    }
    void dfs(TreeNode* root,int k)
    {
        if(root==NULL)
            return;
        dfs(root->right,k);
        if(++count==k)
        {
            res=root->val;
            return;
        }
        if(root->left!=NULL)
            dfs(root->left,k);        
    }
};