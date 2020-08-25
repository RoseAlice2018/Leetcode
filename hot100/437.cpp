#include<iostream>
using namespace std;
//  Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 

class Solution {
public:
    int process(TreeNode* node, int sum)
    {
        if (node == nullptr)
        {
            return 0;
        }

        sum -= node->val;

        return (sum == 0 ? 1 : 0) + process(node->left, sum) + process(node->right, sum);
    }

    int pathSum(TreeNode* root, int sum)
    {
        if (root == nullptr)
        {
            return 0;
        }

        return process(root, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
    }
};
