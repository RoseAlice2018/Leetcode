#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<string> generateParenthesis(int n)
    {
        string path;
        vector<string> res;
        int lc=0,rc=0;
        dfs(res,path,lc,rc,n);
        return res;
    }
    void dfs(vector<string>& res,string path,int lc,int rc,int n)
    {
        if(rc>n||lc>n||rc>lc)
            return;
        if(lc==rc&&lc==n)
        {
          res.push_back(path);
          return;
        }
        dfs(res,path+'(',lc+1,rc,n);
        dfs(res,path+')',lc,rc+1,n);         
    }
}; 