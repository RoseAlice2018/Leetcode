#include<iostream>
 #include<queue>
 #include<stack>
  using namespace std;
  
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
  class Solution {
public:
    int findBottomLeftValue(TreeNode* root) 
    {
        queue<TreeNode*> p;
        TreeNode* q=NULL;
        p.push(root);
        p.push(q);
        vector<int> layer;
        while (!p.empty()&&p.front()!=NULL)
        {
            TreeNode* te=p.front();
            p.pop();
            layer.push_back(te->val);
            if(te->left!=NULL)
            {
                p.push(te->left);
            }
            if(te->right!=NULL)
            {
                p.push(te->right);
            }
            if(p.front()==q)
            {
                p.pop();
                p.push(q);
                if(p.front()!=NULL)
                {
                    layer.clear(); 
                }
                else
                {
                    return layer.front();
                }
                
               
            }

        }
        return layer.front();
    }
};