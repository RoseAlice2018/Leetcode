#include<iostream>
#include<vector>
#include<map>
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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if(t1==NULL)
            return t2;
        if(t2==NULL)
            return t1;
        preorder(t1,t2);
        return t1;
    }
    void preorder(TreeNode* t1,TreeNode* t2)
    {
        t1->val+=t2->val;
        if(t1->left&&t2->left)
        {
            preorder(t1->left,t2->left);
        }
        else
        {
            if(t2->left)
                t1->left=t2->left;
        }
        if(t1->right&&t2->right)
        {
            preorder(t1->right,t2->right);
        }
        else
        {
            if(t2->right)
                t1->right=t2->right;
        }
        return;
    }
};
