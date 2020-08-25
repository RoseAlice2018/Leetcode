#include<iostream>
 #include<queue>
 #include<stack>
 #include<deque>
  using namespace std;
  
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
  class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
    {
        
        vector<int> temp;
        vector<vector<int>> res;
        deque<TreeNode*> p;
        TreeNode* q=NULL;
        p.push_back(q);
        p.push_back(root);
        if(root==NULL)
        {
            return res;
        }        
        int flag=-1;// flag==-1 from left to right flag==1 from right to left
       while(!p.empty())
       {
           TreeNode* te;
           if(flag==-1)// from left to right
           {
                te=p.back();
                p.pop_back();
           }
           if(flag==1)
           {
               te=p.front();
               p.pop_front();
           }
           temp.push_back(te->val);
           if(flag==-1)//
           {
               if(te->left!=NULL)
               {
                   p.push_front(te->left);
               }
               if(te->right!=NULL)
               {
                   p.push_front(te->right);
               }
           }
           if(flag==1)
           {
               
               if(te->right!=NULL)
                p.push_back(te->right);
                if(te->left!=NULL)
                    p.push_back(te->left);
           }
           if(flag==-1)
           {
               if(p.back()==q)
           {
               flag*=-1;
               res.push_back(temp);
               temp.clear();
               if(p.front()==NULL)
               {
                   return res;
               }
               if(flag==-1)
               {
                   p.pop_back();
                   p.push_front(q);
               }
           }
           }
           if(flag==1)
           {
               if(p.front()==q)
           {
               p.pop_front();
               p.push_back(q);
               flag*=-1;
               res.push_back(temp);
               temp.clear();
               if(p.front()==NULL)
               {
                   return res;
               }
               if(flag==-1)
               {
                   p.pop_back();
                   p.push_front(q);
               }
           }
           }
           
       }
        return res;
    }
};
