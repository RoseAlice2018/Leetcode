#include<iostream>
#include<vector>
#include<map>
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
    vector<int> dic;
    int getMinimumDifference(TreeNode* root) 
    {
        preorder(root);
        int min=INT_MAX;
        for(int i=1;i<dic.size();i++)
        {
            if(dic[i]-dic[i-1]<min)
            {
                min=dic[i]-dic[i-1];
            }
        }
        return min;
    }
    void preorder(TreeNode* root)
    {
        if(root==NULL)
            return ;
        preorder(root->left);
        dic.push_back(root->val);
        preorder(root->right);       
    }
};