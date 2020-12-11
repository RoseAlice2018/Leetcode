#include<iostream>
#include<queue>
#include<vector>
using namespace std;
// Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode*left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) 
    {
        vector<double> res;
        if(root == NULL)
            return res;
        queue<TreeNode*> t;
        t.push(root);
        while(!t.empty())
        {
            int currentszie = t.size();
            double sum=0;
            for(int i=1;i<=currentszie;i++)
            {
                auto temp=t.front();t.pop();
                sum+=temp->val;
                if(temp->left)
                    t.push(temp->left);
                if(temp->right)
                    t.push(temp->right);
            }
            res.push_back(sum/(double)currentszie);
        }
        return res;
    }
};