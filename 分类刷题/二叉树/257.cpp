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
    vector<string> binaryTreePaths(TreeNode* root) 
    {
        vector<string> res;
        if(root==NULL)
            return res;
        string path=to_string(root->val);
        preorder(root->left,path,res);
        preorder(root->right,path,res);
        if(!root->right&&!root->left)
            res.push_back(path);
        return res;
    }
    void preorder(TreeNode* root,string path,vector<string>& res)
    {
        if(root==NULL)
            return;
        string add="->"+to_string(root->val);
        path.append(add);
        if(root->left==NULL&&root->right==NULL)
        {
            res.push_back(path);
            return;
        }
        preorder(root->left,path,res);
        preorder(root->right,path,res);
        return;
    }
};

