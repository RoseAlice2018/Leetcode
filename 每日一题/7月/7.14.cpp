#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    void helper(vector<vector<int>>& triangle,int n,int m)
    {
        if(n==0&&m==0)
            return;
        helper(triangle,n-1,m);
        helper(triangle,n-1,m+1)
    }
    int minimumTotal(vector<vector<int>>& triangle)
     {
        
    }
};
