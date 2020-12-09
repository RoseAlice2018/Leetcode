#include<iostream>
#include<stack>
#include<queue>
using namespace std;
int main()
{
    bool a=false;
    cout<<a<<endl;
    a=5;
   // cout<<a;
   cout<<10;
    return 0;
}

template <class T>
struct TreeNode
{
	TreeNode* leftchild;
	TreeNode* rightchild;
	T data;
	TreeNode(T x)leftchild(NULL),rightchild(NULL),data(x){}
	~TreeNode();
};

void preorder(TreeNode<int>* root)
{
	if(root == NULL)
		return;
	stack<TreeNode<int>*> T_pre;
	T_pre.push(root);
    while(!T_pre.empty())
    {
        TreeNode<int>* temp=T_pre.top();
        T_pre.pop();
        cout<<temp->data;
        if(temp->rightchild)
            T_pre.push(temp->rightchild);
        if(temp->leftchild)
            T_pre.push(temp->leftchild);
    }
    return;
}
 void inorder(TreeNode<int>* root)
 {
     	if(root == NULL)
		    return;
	    stack<TreeNode<int>*> T_pre;
	    T_pre.push(root);
        while(!T_pre.empty())
 }