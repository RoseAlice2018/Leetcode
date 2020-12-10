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
        do
        {
            while(root!=NULL)
            {
                T_pre.push(root);
                root = root->leftchild;
            }
            if(!T_pre.empty())
            {
                TreeNode<int>* temp= T_pre.top();
                T_pre.pop();
                cout<<temp->data;
                root = temp->rightchild;
            }
        } while (!T_pre.empty()||root!=NULL);
        return ;
 }

 void postorder(TreeNode<int>* root)
 {
     if(root == NULL)
     {
         return ;
     }
     stack<TreeNode<int>*> T_post;
     stack<TreeNode<int>*> T;
     T_post.push(root);
     while(!T_post.empty())
     {
         TreeNode<int>* curr = T_post.top();
         T.push(curr);
         T_post.pop();
         if(curr->leftchild)
            T_post.push(curr->leftchild);
        if(curr->rightchild)
            T_post.push(curr->rightchild);
     }
     while(!T.empty())
     {
         cout<<T.top()->data<<endl;
         T.pop();
     }
 }