#include<iostream>
#include<queue>
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
    bool isEvenOddTree(TreeNode* root)
     {
        int level=0;
        queue<TreeNode*> dic;
        queue<int> tempdic;
        TreeNode* t=new TreeNode();
        dic.push(root);
        dic.push(t);
        if(root->val%2==0)
            return false;
        while(!dic.empty()&&dic.front()!=t)
        {
            TreeNode* p=dic.front();
            tempdic.push(p->val);
            dic.pop();
            if(p->left)
                dic.push(p->left);
             if(p->right)
                dic.push(p->right);
            if(dic.front()==t)
            {
                dic.pop();
                dic.push(t);
                if(!check(tempdic,level))
                    return false;
                level++;
            }
        }   
        return true;
    }
    bool check(queue<int>& tempdic,int level)
    {
        int before;
        if(level%2==0)
        {
            before=tempdic.front()-1;
        }
        else{
            before=tempdic.front()+1;
        }
        while(!tempdic.empty())
        {
            int t=tempdic.front();
            if(level%2==0)
            {
                if(t%2==0||t<=before)
                {
                    return false;
                }
                before=t;
                tempdic.pop();
            }
            else{
                if(t%2==1||t>=before)
                {
                    return false;
                }
                before=t;
                tempdic.pop();
            }
        }
        return true;
    }
};