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
    int sumEvenGrandparent(TreeNode* root)
     {
        if(root==NULL)
            return 0;
        int res=0;
        if(root->left!=NULL)
        {
            if(root->left->left!=NULL)
            {
                if(root->val%2==0)
                    res+=root->left->left->val;
            }
            if(root->left->right!=NULL)
            {
                if(root->val%2==0)
                    res+=root->left->right->val;
            }
        }
        if(root->right!=NULL)
        {
            if(root->val%2==0)
            {
                if(root->right->left!=NULL)
                    res+=root->right->left->val;
                if(root->right->right!=NULL)
                    res+=root->right->right->val;
            }
        }
        return res+sumEvenGrandparent(root->left)+sumEvenGrandparent(root->right);
    }
};