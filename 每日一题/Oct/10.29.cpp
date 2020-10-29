#include<iostream>
#include<vector>
#include<math.h>
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
    vector<int> des;
    int res=0;
    int sumNumbers(TreeNode* root) 
    {
        if(root==NULL)
            return res;
        preorder(root);
        return res;
    }
    void preorder(TreeNode* root)
    {
        if(root->left==NULL&&root->right==NULL)
        {
            //leave node
            des.push_back(root->val);
            res+=changetonum(des);
            des.pop_back();
            return;
        }
        if(root!=NULL)
            des.push_back(root->val);
        if(root->left!=NULL)
            preorder(root->left);
        if(root->right!=NULL)
            preorder(root->right);
        return ;        
    }
    int changetonum(vector<int> des)
    {
        int res_=0;
        for(int i=des.size()-1;i>=0;i--)
        {
            res_+=des[i]*pow(10,des.size()-1-i);
        }
        return res_;
    }
};