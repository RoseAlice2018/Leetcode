#include<iostream>
#include<vector>
using namespace std;
 //Definition for a binary tree node.
 struct TreeNode {
     int val;
    TreeNode *left;
    TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 int findroot(vector<int> inorder,int rootvalue,int left,int right)
 {
     for(int i=left;i<=right;i++)
     {
         if(inorder[i]==rootvalue)
            return i;
     }
     return 0;
 }
TreeNode* createTree(vector<int>& preorder,vector<int>& inorder,int& middleroot,int leftsize,int rightsize)
{
    if(middleroot>preorder.size()-1)
        return NULL;
    TreeNode* root=new TreeNode(0);
    root->val=preorder[middleroot];
    int middle=findroot(inorder,root->val,leftsize,rightsize);
   if(leftsize<=middle-1) root->left=createTree(preorder,inorder,++middleroot,leftsize,middle-1);
    if(rightsize>=middle+1)root->right=createTree(preorder,inorder,++middleroot,middle+1,rightsize);
    return root;
}
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {
        if(inorder.size()==0)
            return NULL;
        int pos=0;
        TreeNode* res=createTree(preorder,inorder,pos,0,inorder.size()-1);
        return res;        
    }
};