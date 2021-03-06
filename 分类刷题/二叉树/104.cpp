#include<iostream>
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
    int maxDepth(TreeNode* root)
     {
       int depth=1,maxdepth=0;
        preorder(root,depth,maxdepth);
        return maxdepth;
    }
    void preorder(TreeNode* root,int depth,int& maxdepth)
    {
        if(root==NULL)
            return;
        if(depth>maxdepth)
            maxdepth=depth;
        preorder(root->left,depth+1,maxdepth);
        preorder(root->right,depth+1,maxdepth);
    }
};