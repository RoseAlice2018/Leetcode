#include<iostream>
#include<queue>
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
    queue<int> res;
    void preorder(TreeNode* root)
    {
        if(root==NULL)
            return ;
        res.push(root->val);
        preorder(root->left);
        preorder(root->right);        
    }
    void flatten(TreeNode* root)
     {
         if(root==NULL)
            return;
         preorder(root);
         res.pop();
         TreeNode* q=root;
         while(!res.empty())
         {
             int temp=res.front();
             res.pop();
             TreeNode* p=new TreeNode(0);
             p->val=temp;
             q->right=p;
             q->left=NULL;
             q=p;
         }
    }
};