#include<iostream>
#include<queue>
#include<vector>
#include<string>
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
    vector<vector<int>> pathSum(TreeNode* root, int sum)
     {
        vector<vector<int>> res;
        if(root==NULL)
            return res;
        vector<int> path;
        preorder(root,sum,0,path,res);
        return res;
    }
    void preorder(TreeNode* root,int target,int sum,vector<int> path,vector<vector<int>>& res)
    {
        if(root==NULL)
            return;
        if(root->left==NULL&&root->right==NULL)
        {
            sum+=root->val;
            if(sum==target)
            {
                path.push_back(root->val);
                res.push_back(path);
                return;
            }
            return;
        }
        path.push_back(root->val);
        preorder(root->left,target,sum+root->val,path,res);
        preorder(root->right,target,sum+root->val,path,res);
    }
};