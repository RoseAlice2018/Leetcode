#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int main()
{
	int a=1;
	int b=2;
	int c=12;
	cout<<c;
	return 0;
 } 

//  Definition for a binary tree node.
 struct TreeNode {
     int val;
    TreeNode *left;
    TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
		vector<vector<int>> res;
		queue<TreeNode*> lay;
        TreeNode* p=NULL;
		lay.push(root);
		lay.push(p);
		while(!lay.empty()&&lay.front()!=p)
		{
			vector<int> levres;
			while(lay.front()!=p)
			{
				TreeNode* parent=lay.front();
				levres.push_back(parent->val);
				lay.pop();
				if(parent->left!=NULL)
					lay.push(parent->left);
				if(parent->right!=NULL)
					lay.push(parent->right);
			}
			lay.pop();
			lay.push(p);
			res.push_back(levres);
		}
		vector<vector<int>> re;
		while(!res.empty())
		{
			re.push_back(res.back());
			res.pop_back();
		}
		return re;
    }
};