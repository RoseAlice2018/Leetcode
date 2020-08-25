#include<iostream>
#include<queue>
using namespace std;
//  Definition for a binary tree node.
  struct TreeNode 
  {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 
class Solution {
public:
    int rob(TreeNode* root)
     {
         TreeNode* p=new TreeNode(0);
         queue<TreeNode*> res;
         int res1=0,res2=0;
         if(root==NULL)
            return 0;
        res.push(root);
        res.push(p);
        int count=1;
        while(!res.empty())
        {
            TreeNode* temp=res.front();res.pop();
            if(count%2==0)
                res2+=temp->val;
            else 
                res1+=temp->val;
            if(temp->left!=NULL)
                res.push(temp->left);
             if(temp->right!=NULL)
                res.push(temp->right);
            if(res.front()==p)
            {
                res.pop();
                res.push(p);
                count++;
            }
            if((res.front()==p||res.empty())&&temp==p)
                break;
        }
        return max(res1,res2);
    }
};