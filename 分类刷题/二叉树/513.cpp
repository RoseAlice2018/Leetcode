#include<iostream>
#include<queue>
#include<vector>
#include<string>
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
    int findBottomLeftValue(TreeNode* root) {
        int res=0;
        queue<TreeNode*> dic;
        if(root==NULL)
            return 0;
        dic.push(root);
        while(!dic.empty())
        {
            int cur_size=dic.size();
            res=dic.front()->val;
            for(int i=0;i<cur_size;i++)
            {
                auto temp=dic.front();dic.pop();
                if(temp->left)
                    dic.push(temp->left);
                if(temp->right)
                    dic.push(temp->right);
            }
        }
        return res;
    }
};