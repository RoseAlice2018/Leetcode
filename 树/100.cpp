
  #include<iostream>
  using namespace std;
  
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q)
     {
       //递归
       if(p==NULL&&q==NULL)
       {
           return true;
       }
        else if(p==NULL||q==NULL||q->val!=p->val)
        {
            return false;
        }
        else
        {
            bool left=isSameTree(q->left,p->left);
            bool right=isSameTree(q->right,p->right);
            return left&&right;
        }
        
        
    }
};