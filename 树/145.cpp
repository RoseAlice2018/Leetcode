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
    vector<int> res;
    vector<int> postorderTraversal(TreeNode* root) 
    {   
        if(root==NULL)
        {
            return res;
        }
        postorder(root);
        return res;
        
    }
    void postorder(TreeNode* root)
    {
        if(root==NULL)
            return;
        postorder(root->left);
        postorder(root->right);
        res.push_back(root->val);
    }
};