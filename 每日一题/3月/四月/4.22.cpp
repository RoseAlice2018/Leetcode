#include<vector>
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
    vector<int> res1;
    vector<int> res2;
    void findright(TreeNode* root,vector<int>& res)
    {
        if(root==NULL)
            return;
        else
            res.push_back(root->val);
        if(root->right!=NULL)
            findright(root->right,res);
        else if(root->left!=NULL)
            findright(root->left,res);
        else 
            return;        
    }
    vector<int> rightSideView(TreeNode* root)
     {
         if(root==NULL)
            return res1;
         findright(root,res1);
         if(root->left!=NULL)
            findright(root->left,res2);
        if(res2.size()+1<=res1.size())
            return res1;
        else 
        {
            for(int i=res1.size()-1;i<res2.size();i++)
                res1.push_back(res2[i]);
        }
        return res1;
    }
};