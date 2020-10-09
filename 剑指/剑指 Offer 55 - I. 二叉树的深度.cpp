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
    int res=0;
    int maxDepth(TreeNode* root) 
    {
        BFS(root,1);
        return res;
    }
    void BFS(TreeNode* root,int layer)
    {
        if(root==NULL)
        {
            return;
        }
        if(root->left)
        {
            BFS(root->left,layer+1);
        }
        if(root->right)
        {
            BFS(root->right,layer+1);
        }
        if(layer>res)
        {
            res=layer;
        }
        return ;
    }
};