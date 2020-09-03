#include<vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> res;
    void subset(vector<int> t,int i,int n,vector<int> nums)
    {
        if(i==n-1)
        {
            t.push_back(nums[i]);
            res.push_back(t);
            t.pop_back();
            res.push_back(t);
        }
        else
        {
            t.push_back(nums[i]);
            subset(t,i+1,n,nums);
            t.pop_back();
            subset(t,i+1,n,nums);
        } 
    }
    vector<vector<int>> subsets(vector<int>& nums) 
    {
        vector<int> t;
        subset(t,0,nums.size(),nums);
        return res;
    }
};