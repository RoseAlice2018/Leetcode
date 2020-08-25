class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root)
     {
        vector<int> temp;
        vector<vector<int>> res;
        queue<TreeNode*> p;
        TreeNode* q=NULL;
        p.push(root);
        p.push(q);
        while (!p.empty()&&p.front()!=NULL)
        {
            TreeNode* te=p.front();
            p.pop();
            temp.push_back(te->val);
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
               
                //
                res.push_back(temp);
                temp.clear();
                 if(p.front()==q)
                {
                    return res;
                }
            }

        }
        return res;
        
    }
};