#include<iostream>
#include<queue>
#include<vector>
using namespace std;
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};


class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) 
    {
          vector<vector<int>> ret;
          if(!root)
            return ret;
          queue<Node*> t;
          t.push(root);
          while(!t.empty())  
          {
              vector<int> temp_ret;
              int currentsize = t.size();
              for(int i=1;i<=currentsize;i++)
              {
                  auto tt=t.front();t.pop();
                  temp_ret.push_back(tt->val);
                  if(!tt->children.empty())
                    {
                        for(int j=0;j<tt->children.size();j++)
                    t.push(tt->children[j]);
                    }
                  
              }
              ret.push_back(temp_ret);
          }
          return ret;
    }
};