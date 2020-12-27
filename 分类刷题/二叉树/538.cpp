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
    int temp=0;
    TreeNode* convertBST(TreeNode* root) {
        vector<int> dic;
        if(root==NULL)
            return NULL;
        inorder(root,dic);
        return root;        
    }
    void inorder(TreeNode* root,vector<int>& dic)
    {
        if(root==NULL)
            return;
        inorder(root->right,dic);
        temp+=root->val;
        root->val=temp;
        inorder(root->left,dic);
    }
    
};