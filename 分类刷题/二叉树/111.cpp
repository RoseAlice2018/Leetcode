#include<iostream>
#include<queue>
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
    int minDepth(TreeNode* root)
     {
         if(root==NULL)
            return 0;
         int depth=1;
         queue<TreeNode*> temp;
         temp.push(root);
         while(!temp.empty())
         {
             int size_=temp.size();
             for(int i=0;i<size_;i++)
             {
                 auto first = temp.front();
                 temp.pop();
                 if(first->left==NULL && first->right==NULL)
                    // find it
                    return depth;
                if(first->left)
                    temp.push(first->left);
                if(first->right)
                    temp.push(first->right);
             }
             depth++;
         }
         return depth;
    }
};