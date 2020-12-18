#include<iostream>
#include<queue>
#include<vector>
#include<string>
#include<set>
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
    bool hasPathSum(TreeNode* root, int sum) 
    {
         set<int> dic;
         if(root==NULL)
            return false;
        preorder(root,dic,0);
        if(dic.count(sum))
            return true;
        
            return false;
    }
    void preorder(TreeNode* root,set<int>& res,int sum)
    {
        if(root==NULL)
            return;
        if(root->left==NULL&&root->right==NULL)
        {
            sum+=root->val;
            res.insert(sum);
            return;
        }
        preorder(root->left,res,sum+root->val);
        preorder(root->right,res,sum+root->val);
    }
};