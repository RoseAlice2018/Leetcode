#include<vector>
#include<string>
#include<iostream>
using namespace std;
class Solution {
public:
    struct TreeNode
    {
        char label;
        vector<TreeNode*> sub;
        TreeNode(char x) : label(x),sub(NULL) {}
    };
    
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) 
    {
        vector<int> res;
        TreeNode* leaves[10005];
        TreeNode* root;
        root=constructTree(root,edges,labels,0,leaves);
        for(int i=0;i<n;i++)
        {
            char t=labels[i];
            int temp=rescount(t,leaves[i]);
            res.push_back(temp);
        }
        return res;
    }
    int rescount(char labell,TreeNode* root)
    {
        int res=0;
        if(root==NULL)
            return res;
        if(root->label==labell)
            res++;
        for(int i=0;i<root->sub.size();i++)
        {
            res+=rescount(labell,root->sub[i]);
        }
        return res;
    }
    TreeNode* constructTree(TreeNode* root,vector<vector<int>> edges,string labels,int position,TreeNode* leaves[])
    {
        root=new TreeNode(labels[position]);
        leaves[position]=root;
        vector<int> subb;
        int subpositions;
        for(int i=0;i<edges.size();i++)
        {
            if(edges[i][0]==position&&!leaves[edges[i][1]])
            {
                subpositions=edges[i][1];
                subb.push_back(subpositions);
            }
            if(edges[i][1]==position&&!leaves[edges[i][0]])
            {
                subpositions=edges[i][0];
                subb.push_back(subpositions);
            }
        }
        for(int i=0;i<subb.size();i++)
        {
            TreeNode* s;
            root->sub.push_back(constructTree(s,edges,labels,subb[i],leaves));
        }
        return root;      
    }
    
};