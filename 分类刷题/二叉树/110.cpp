#include<iostream>
#include<queue>
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
    int count=1;
    bool isBalanced(TreeNode* root)
     {
        return countheight(root)==-1?false:true;
    }
    int countheight(TreeNode* root)
    {
        if(root == NULL)
            return 0;
        int left_val=countheight(root->left);
        int right_val=countheight(root->right);
        if(left_val==-1||right_val==-1)
            return -1;
        if(abs(left_val-right_val)>1)
            return -1;
        root->val = max(left_val,right_val)+1;
        return root->val;
    }
};