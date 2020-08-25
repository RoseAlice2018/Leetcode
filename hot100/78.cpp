#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> res;
    vector<int> temp;
    void subset(vector<int>nums,int k)
    {
        if(k==0)
        {
            res.push_back(temp);
            return;
        }
        temp.push_back(nums[k-1]);
        subset(nums,k-1);
        temp.pop_back();
        subset(nums,k-1);
    }
    vector<vector<int>> subsets(vector<int>& nums)
     {
        subset(nums,nums.size());
        return res;
    }
};