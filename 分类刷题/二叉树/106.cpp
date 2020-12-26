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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) 
    {
            if(inorder.empty())
                return nullptr;
            for(int i=0;i<inorder.size();i++)
                dic[inorder[i]]=i;
            int index=inorder.size()-1;
            TreeNode* root=buildTree2(inorder,postorder,0,inorder.size()-1,index);
            return root;
    }
    TreeNode* buildTree2(vector<int>& inorder,vector<int>& postorder,int left,int right,int& index)
    {
        TreeNode* root=new TreeNode(postorder[index]);
        index--;
        int mid=dic[root->val];
        if(mid+1<=right&&index>=0)
        root->right=buildTree2(inorder,postorder,mid+1,right,index);
        if(mid-1>=left&&index>=0)
        root->left=buildTree2(inorder,postorder,left,mid-1,index);
        return root;
    }
};