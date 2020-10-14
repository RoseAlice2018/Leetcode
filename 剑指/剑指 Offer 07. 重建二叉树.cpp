#include<iostream>
#include<vector>
using namespace std;
 // Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {
        TreeNode* res=bTree(preorder,inorder,0,0,0,inorder.size()-1);
        return res;
    }
    TreeNode* bTree(vector<int>& preorder,vector<int>& inorder,int preleft,int preright,int inleft,int inright)
    {
        if(preleft>preright||inleft>inright)
        {
            return NULL;
        }
        TreeNode* root=new TreeNode(preorder[preleft]);
        int leftsize=0,rightsize=0;
        int mid;
        for(int i=inleft;i<=inright;i++)
        {
            if(inorder[i]==root->val)
            {
                mid=i;
                leftsize=i-inleft;
                rightsize=inright-i;
                break;
            }
        }
        root->left=bTree(preorder,inorder,preleft+1,preleft+leftsize,inleft,mid-1);
        preright=preleft+leftsize+1;
        root->right=bTree(preorder,inorder,preright,preright+rightsize-1,mid+1,mid+rightsize);
        return root;
    }
};