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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if(nums.empty())
            return nullptr;
        TreeNode* root = constructMaximumBinaryTree2(nums,0,nums.size()-1);
        return root;
    }
    TreeNode* constructMaximumBinaryTree2(vector<int>& nums,int left,int right)
    {
        // find the index of the maxvalue
        int index=0;
        int maxvalue=0;
        for(int i=left;i<=right;i++)
        {
            if(nums[i]>=maxvalue)
            {
                index=i;
                maxvalue=nums[i];
            }
        }
        TreeNode* root = new TreeNode(maxvalue);
        if(left<=index-1)
            root->left=constructMaximumBinaryTree2(nums,left,index-1);
        if(right>=index+1)
            root->right=constructMaximumBinaryTree2(nums,index+1,right);
        return root;
    }
};