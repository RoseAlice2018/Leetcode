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
    map<int,int> dic;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.empty())
            return nullptr;
        for(int i=0;i<preorder.size();i++)
            dic[inorder[i]]=i;
        int index=0;
        TreeNode* root = buildTree2(preorder,inorder,0,inorder.size()-1,index);
        return root;
    }
    TreeNode* buildTree2(vector<int>& preorder,vector<int>& inorder,int left,int right,int& index)
    {
        TreeNode* root = new TreeNode(preorder[index]);
        index++;
        int mid=dic[root->val];
        if(left<=mid-1&&index<=inorder.size()-1)
            root->left=buildTree2(preorder,inorder,left,mid-1,index);
        if(mid+1<=right&&index<=inorder.size()-1)
            root->right=buildTree2(preorder,inorder,mid+1,right,index);
        return root;
    }
};