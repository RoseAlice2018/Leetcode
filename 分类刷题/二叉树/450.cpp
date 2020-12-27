

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
    TreeNode* deleteNode(TreeNode* root, int key) {
        return deleteNode2(root,root,key);       
    }
    TreeNode* deleteNode2(TreeNode* root,TreeNode* father,int key)
    {
        if(root==NULL)
            return root;
        if(root->val==key)
        {
            //step alreay find the node,delete it and still fulfill the principal of bst
            //if right_child exist
            if(root->right)
            {
                TreeNode* temp=root->right;
                while(temp->left!=NULL)
                    temp=temp->left;
                temp->left=root->left;
                root->left=NULL;
                root=root->right;
                if(key>father->val)
                {
                    father->right=root;
                }
                else if(key<father->val)
                {
                    father->left=root;
                }
            } 
            else
            {
                root=root->left;
                if(key>father->val)
                {
                    father->right=root;
                }
                else if(key<father->val)
                {
                    father->left=root;
                }
                //whether left_child exists doesn't matter
            }
            
        }
        else if(root->val<key)
        {
            deleteNode2(root->right,root,key);
        }
        else if(root->val>key)
        {
            deleteNode2(root->left,root,key);
        }
        return root;
    }
};