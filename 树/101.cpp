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
    bool isSymmetric(TreeNode* root) 
    {
        return ismirror(root->left,root->right);
    }
    bool ismirror(TreeNode* p,TreeNode* q)
    {
        if(p==NULL&&q==NULL)
            return true;
        else if(p==NULL||q==NULL)
            return false;
        else if(p->val==q->val)
        {
            return ismirror(p->left,q->right)&&ismirror(p->right,q->left);
        }
        return false;
    }
};