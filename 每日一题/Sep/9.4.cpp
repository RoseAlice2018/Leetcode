#include<vector>
#include<string>
using namespace std;

//  Definition for a binary tree node.
  struct TreeNode {
      int val;
     TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 
class Solution {
public:
    vector<string> res;
    void dfs(TreeNode* root,string temp)
    {
        if(root->left==NULL&&root->right==NULL)
        {
            temp+="->";
            temp.push_back(root->val);
            res.push_back(temp);
            return;
        }
        else if(root->left&&root->right==NULL)
        {
            temp+="->";
            temp.push_back(root->val);
            dfs(root->left,temp);
        }
        else if(root->right&&root->left!=NULL)
        {
            temp+="->";
            temp.push_back(root->val);
            dfs(root->right,temp);
        }
        else 
        {
            temp+="->";
            temp.push_back(root->val);
            dfs(root->left,temp);
            dfs(root->right,temp);
        }
    }
    vector<string> binaryTreePaths(TreeNode* root)
     {
         if(root->left&&root->right)
         {
             string temp="";
             temp.push_back(root->val);
             dfs(root->left,temp);
             dfs(root->right,temp);
         }
         else if(root->left)
         {
            string temp="";
             temp.push_back(root->val);
             dfs(root->left,temp);
         }
         else if(root->right)
         {
              string temp="";
             temp.push_back(root->val);
             dfs(root->right,temp);
         }
         else
         {
             string temp="";
             temp.push_back(root->val);
             res.push_back(temp);
             return res;
         }
         
         return res;

    }
};