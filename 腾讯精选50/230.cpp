#include<iostream>
using namespace std;
  //Definition for a binary tree node.
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
    int kthSmallest(TreeNode* root, int k) {
        int res;
        int count=0;
        preorder(root,count,res,k);
        return res;
    }
    void preorder(TreeNode* root,int& count,int& res,int& target)
    {
        if(root==NULL)
            return;
        preorder(root->left,count,res,target);
        preorder(root->right,count,res,target);
        count++;
        if(count>target)
            return;
        if(target==count)
        {
            res=root->val;
            return;
        }
    }
};