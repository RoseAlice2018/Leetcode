#include<vector>
#include<queue>
#include<iostream>
using namespace std;
 // Definition for a binary tree node.
  struct TreeNode 
  {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        vector<vector<int>> res;
        int layer=1;
        if(root==NULL)
            return res;
        queue<TreeNode*> layer_num;
        layer_num.push(root);
        while (!layer_num.empty())
        {
            queue<TreeNode*> temp;
            vector<int> layer_;
            while (!layer_num.empty())
            {
                TreeNode* t=layer_num.front();
                layer_num.pop();
                layer_.push_back(t->val);
                if(t->left)
                    temp.push(t->left);
                if(t->right)
                    temp.push(t->right);                   
            }
            layer_num=temp;
            if(layer==1)
            {
                layer=2;
                res.push_back(layer_);
            }
            else 
            {
                layer=1;
                reverse(layer_.rbegin(),layer_.rend());
                res.push_back(layer_);
            } 
        }
        return res;
    }
};