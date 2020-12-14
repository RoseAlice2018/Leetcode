 #include<iostream>
 #include<queue>
 #include<vector>
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
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        vector<vector<int>> res;
        if(root == NULL)
            return res;
        queue<TreeNode*> t;
        vector<int> temp;
        t.push(root);
        while(!t.empty())
        {
            queue<TreeNode*> tt;
            while(!t.empty())
            {
                TreeNode* node=t.front();
                temp.push_back(node->val);
                if(node->left)
                    tt.push(node->left);
                if(node->right)
                    tt.push(node->right);
                t.pop();
            }
            res.push_back(temp);
            temp.clear();
            t=tt;
        }
        return res;
    }
};