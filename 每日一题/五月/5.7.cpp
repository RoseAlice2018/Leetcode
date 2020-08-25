#include<iostream>
#include<vector>
using namespace std;
 // Definition for a binary tree node.
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
    bool Isequal(TreeNode* s,TreeNode* t)
    {
        if(s==NULL&&t==NULL) return true;
        return s&&t&&t->val==s->val&&Isequal(s->left,t->left)&&Isequal(s->right,t->right);
    }
    bool isSubtree(TreeNode* s, TreeNode* t) 
    {
        if(s==NULL&&t==NULL)    return true;
        if(s==NULL&&t!=NULL)    return false;
        return Isequal(s,t)||isSubtree(s->left,t)||isSubtree(s->right,t);
    }
};