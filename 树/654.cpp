#include<iostream>
 #include<queue>
 #include<stack>
  using namespace std;
  
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
  class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) 
    {
        TreeNode* root;
        root->val=maxx(0,nums.size(),nums);
        root->left
        
    }
    int maxx(int left,int right,vector<int>& nums)
    {
        int max=nums[left];
        for(int i=left;i<=right;i++)
        {
            if(nums[i]>max)
                max=nums[i];
        }
        return max;
    }
};
