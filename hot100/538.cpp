#include<iostream>
#include<vector>
using namespace std;
//  Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 
class Solution {
public:
    vector<int> res;
    TreeNode* convertBST(TreeNode* root) 
    {
        Inorder(root);
        preorder(root);
        return root;
        
    }
    void Inorder(TreeNode* root)
    {
        if(root==NULL)
            return;
        Inorder(root->left);
        res.push_back(root->val);
        Inorder(root->right);        
    }
    void preorder(TreeNode* root)
    {
        if(root==NULL)
            return ;
        int sum=root->val;
        int i;
        for( i=0;i<res.size();i++)
        {
            if(res[i]==sum)
            {
                //find it;
                break;
            }
        }
        for(int j=i+1;j<res.size();j++)
        {
            sum+=res[j];
        }
        root->val=sum;
        preorder(root->left);
        preorder(root->right);
    }
};