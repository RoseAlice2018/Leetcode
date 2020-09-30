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
    void insert(TreeNode* root,int val,TreeNode* father,int Node)
    {
          if(root==NULL)
        {
            root = new TreeNode(val);
            if(Node==1)
                father->left=root;
            else 
                father->right=root;
            return;
        }
        else if(root->val>val)
        {
            insert(root->left,val,root,1);
        }
        else if(root->val<val)
        {
            insert(root->right,val,root,0);
        }
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) 
    {
        if(root==NULL)
        {
            TreeNode* r=new TreeNode(val);
            return r;
        }
      insert(root,val,root,1);
        return root;
    }
};