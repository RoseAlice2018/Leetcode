#include<iostream>
using namespace std;
 //* Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 
class Solution {
public:
    int max_sum=INT32_MIN;
    int maxpath(TreeNode* root)
    {
        if(root==NULL)
            return 0;
        int leftvalue=max(0,maxpath(root->left));
        int rightvalue=max(0,maxpath(root->right));
        int pathvalue=root->val+leftvalue+rightvalue;
        if(pathvalue>max_sum)
            max_sum=pathvalue;
        return root->val+max(leftvalue,rightvalue);
    }
    int maxPathSum(TreeNode* root) 
    {
        maxpath(root);
        return max_sum;
    }
};