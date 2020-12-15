#include<iostream>
#include<queue>
#include<vector>
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
    bool isSymmetric(TreeNode* root) 
    {
        if(root==NULL||(!root->right && ! root->left))
            return true;
        queue<TreeNode*> dic;
        dic.push(root->left);
        dic.push(root->right);
        while(!dic.empty())
        {
            TreeNode* left = dic.front();dic.pop();
            TreeNode* right = dic.front();dic.pop();
            if(!left && !right)
            {
                continue;
            }
            else if(left&&right)
            {
                if(left->val==right->val)
                {
                    dic.push(left->left);
                    dic.push(right->right);
                    dic.push(left->right);
                    dic.push(right->left);
                }
                else 
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};