#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> res;
    void combinationsum(vector<int>&candidates ,int start,int target,vector<int> t)
    {
        if(target==0)
        {
            res.push_back(t);
            return ;
        }
        if(target< 0 )
            return ;
        for(int i=start;i<candidates.size();i++)
        {
            int temp=target-candidates[i];
            t.push_back(candidates[i]);
            combinationsum(candidates,i,temp,t);
            t.pop_back();
        }
        return;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target)
     {
         vector<int> t;
         combinationsum(candidates,0,target,t);
         return res;
    }
};