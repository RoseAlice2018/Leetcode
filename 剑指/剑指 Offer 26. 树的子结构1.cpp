#include<iostream>
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
    bool isSubStructure(TreeNode* A, TreeNode* B) 
    {
        if(B==NULL||A==NULL)//空树不是任意一个树的子结构
            return false;
        return recur(A,B)||isSubStructure(A->left,B)||isSubStructure(A->right,B);
    }
    bool recur(TreeNode* A,TreeNode* B)
    {
        if(B==NULL) return true;
        if(A==NULL||A->val!=B->val) return false;
        return recur(A->left,B->left)&&recur(A->right,B->right);
    }
};
/*
[1,0,1,-4,-3]
[1,-4]
*/