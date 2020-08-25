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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        if(root==NULL)
        {
            return NULL;
        }
        if(root->val==p->val)
            return p;
        if(root->val==q->val)
        {
            return q;
        }
        if((p->val<root->val&&q->val>root->val)||(p->val>root->val&&q->val<root->val))
        {
            return root;
        }
        if(q->val<root->val&&p->val<root->val)
        {
            return lowestCommonAncestor(root->left,p,q);
        }
        else if(q->val>root->val&&p->val>root->val)
        {
            return lowestCommonAncestor(root->right,p,q);
        } 
        
        return root;
        
    }
};