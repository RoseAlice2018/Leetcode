#include<iostream>
 #include<queue>
 #include<stack>
  using namespace std;
  
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
  class Solution {
public:
    TreeNode* invertTree(TreeNode* root) 
    {
        TreeNode* temp;
        if(root==NULL)
            return root;
        if(root->left!=NULL||root->right!=NULL)
        {
            //exchange
            temp=root->left;
            root->left=root->right;
            root->right=temp;
            invertTree(root->left);
            invertTree(root->right);
        }
        else
        {
            return root;
        }
        
        
        return root;
    }
};