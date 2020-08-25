#include<iostream>
#include<vector>
#include<queue>
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
    vector<vector<int>> levelOrder(TreeNode* root)
     {
        vector<vector<int>> res;
        int count=0;
        queue<TreeNode*> temp;
        res[count].push_back(root->val);
        count++;
        TreeNode* set=new TreeNode(-1);
        temp.push(root);
        temp.push(set);
        while(!temp.empty())
        {
            TreeNode* head=temp.front();temp.pop();
            if(head==set&&temp.front()==set)
                break;
            if(head!=set)
            {
                res[count].push_back(head->val);
            }
            if (head==set)
            {
                count++;
                temp.push(set);
            }
            else if(head->left!=NULL)
            {
                temp.push(head->left);
            }
            else if(head->right!=NULL)
            {
                temp.push(head->right);
            }

            
        }
        return res;
    }
};