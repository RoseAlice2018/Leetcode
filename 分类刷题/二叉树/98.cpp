#include<iostream>
#include<vector>
#include<stack>
using namespace std;
 //* Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if(root==NULL)
            return true;
        stack<TreeNode*> T_pre;
        vector<int> dic;
        //T_pre.push(root);
        do
        {
            while (root!=NULL)
            {
                T_pre.push(root);
                root=root->left;
            }
            if(!T_pre.empty())
            {
                TreeNode* t=T_pre.top();
                T_pre.pop();
                if(!dic.empty())
                {
                    auto iter=dic[dic.size()-1];
                    if(t->val<iter)
                        return false;
                }
                dic.push_back(t->val);
                root=t->right;
            }
            
        } while (!T_pre.empty()||root!=NULL);
        return true;
    }
};