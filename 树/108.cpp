#include<iostream>
 #include<queue>
 #include<stack>
 #include<malloc>
  using namespace std;
  
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
  class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums)
    {
      return sortedArrayToBS(nums,0,nums.size());  
    }
    TreeNode* sortedArrayToBS(vector<int>& nums,int start,int end)
    {
        int mid=(start+end)>>1;
        TreeNode* root=(TreeNode*)malloc(sizeof(TreeNode));
        root->val=nums[mid];
        root->left=sortedArrayToBS(nums,0,mid);
        root->right=sortedArrayToBS(nums,mid+1,end);
        return root;


    }
};