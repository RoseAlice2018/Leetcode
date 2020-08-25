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
    bool isBalanced(TreeNode* root) 
    {
        if(root==NULL)
        {
            return true;
        }
        if(abs(height(root->left)-height(root->right))<=1)
        {
            return isBalanced(root->left)&&isBalanced(root->right);
        }
        else
        {
            return false;
        }
        
        
    }
    int height(TreeNode* root)
    {
        if(root==NULL)
        {
            return 0;
        }
        else
        {
            return max(height(root->left),height(root->right))+1;
        }
        
    }
};