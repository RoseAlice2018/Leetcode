#include<vector>
#include<iostream>
#include<stack>
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
    vector<vector<int>> pathSum(TreeNode* root, int sum) 
    {
        int pathsum=0;// 记录每一条的路径的和
        vector<int> path;//记录每一天路径沿途的值
        vector<vector<int>> res;
        if(root==NULL)
            return res;
        preorder(pathsum,root,res,path,sum);
        return res;
    }
    void preorder(int& sum,TreeNode* root,vector<vector<int>>& res,vector<int>& path,const int target)
    {
        if(root->left==NULL&&root->right==NULL)
        {
            // 叶子结点
            sum+=root->val;
            path.push_back(root->val);
            if(sum==target)
            {
                //find it
                res.push_back(path);  
            }
            path.pop_back();
            sum-=root->val;
            return;
        }
        path.push_back(root->val);
        sum+=root->val;
        if(root->left!=NULL)
        {
            preorder(sum,root->left,res,path,target);
        }
        if(root->right!=NULL)
        {
            preorder(sum,root->right,res,path,target);
        }
        sum-=root->val;
        path.pop_back();
        return;
    }
};