#include<iostream>
#include<vector>
#include<queue>
using namespace std;
 // Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) 
    {
        vector<int> res;
        if (!root) {
            return res;
        }
        queue <TreeNode*> q;
        q.push(root);
        while (!q.empty()) 
        {
            int currentLevelSize = q.size();
            for (int i = 1; i <= currentLevelSize; ++i) 
            {
                auto node = q.front(); q.pop();
                if(i==currentLevelSize)
                    res.push_back(node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }
        return res;
    }
};