// #include<iostream>
//  #include<queue>
//  #include<stack>
//   using namespace std;
  
//   struct TreeNode {
//       int val;
//       TreeNode *left;
//       TreeNode *right;
//       TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//   };
//   class Solution {
// public:
//     bool hasPathSum(TreeNode* root, int sum) 
//     {
        
//         if(root!=NULL)
//         {
//             stack<TreeNode*> dfs;
//         int check=0;
//         dfs.push(root);
//         check+=root->val;
//         TreeNode* p=NULL;
//         TreeNode* q=NULL;
//             while (!dfs.empty())
//         {
//              p=dfs.top();
//             if(check==sum&&p->right==NULL&&p->left==NULL)
//             {
//                 return true;
//             }
           
//             if(p->left!=NULL&&p->left!=q)
//             {
//                 check+=p->left->val;
//                 dfs.push(p->left);
//             }
//             else if(p->right!=NULL&&p->right!=q)
//             {
//                 check+=p->right->val;
//                 dfs.push(p->right);
//             }
//             else
//             { 
//                 check-=p->val;
//                 q=p;
//                 dfs.pop();               
//             }
            
            

//         }
//             return false;
//         }
//         else if(root==NULL)
//         {
//             return false;
//         }
        
      
        
//     }
// };

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) 
    {
        if(root==NULL)
        {
            return false;
        }
       if(root->left==NULL&&root->right==NULL)
       {
           return sum-root->val==0;
       }
       return hasPathSum(root->left,sum-root->val)||hasPathSum(root->right,sum-root->val);
    }
};