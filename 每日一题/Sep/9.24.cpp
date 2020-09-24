#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

  //Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 
class Solution {
public:
    int max=0;
    void dfs(TreeNode* root,unordered_map<int,int>& dic)
    {
        if(root==NULL)
            return;
        if(dic.count(root->val))
        {
            dic[root->val]++;
            if(dic[root->val]>max)
                max=dic[root->val];
        }
        else{
            dic[root->val]=1;
        }
        dfs(root->left,dic);
        dfs(root->right,dic);
    }
    vector<int> findMode(TreeNode* root) {
        unordered_map<int,int> dic;
        vector<int> res;
        for(auto iter = dic.begin();iter!=dic.end(); ++iter){
            if(iter->second==max)
                res.push_back(iter->first);
        }
        return res;
    }
};