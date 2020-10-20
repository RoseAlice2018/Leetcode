#include<iostream>
#include<vector>
#include<queue>
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
    vector<int> levelOrder(TreeNode* root)
     {
         queue<TreeNode*> temp;
         vector<int> res;
         if(!root)
            return res;
        temp.push(root);
        while(!temp.empty())
        {
            res.push_back(temp.front()->val);
            if(temp.front()->left)
                temp.push(temp.front()->left);
            if(temp.front()->right)
                temp.push(temp.front()->right);
            temp.pop();
        }
        return res;
    }
};