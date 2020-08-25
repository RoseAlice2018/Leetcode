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
    int deepestLeavesSum(TreeNode* root) 
    {
        if(root==NULL)
        {
            return 0;
        }
        queue<TreeNode*> leave;
        leave.push(root);
        TreeNode* p=NULL;
        leave.push(p);
        int sum=0;//result
        while(!leave.empty()&&leave.front()!=NULL)
        {
            TreeNode* temp=leave.front();
            sum+=leave.front()->val;
            leave.pop();
            if(temp->left!=NULL)
            {
                leave.push(temp->left);
            }
            if(temp->right!=NULL)
            {
                leave.push(temp->right);
            }
            if(leave.front()==NULL)
            {
                leave.pop();
                leave.push(p);
                if(leave.front()!=NULL)
                {
                   sum=0; 
                } 
            }
        }
        return sum;
    }
};