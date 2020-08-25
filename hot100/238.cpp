#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) 
    {
        vector<int> res;
        int k=1;
        for(int i=0;i<nums.size();i++)
        {
            res.push_back(k);
            k*=nums[i];
        }
        k=1;
        for(int i=nums.size()-1;i>=0;i--)
        {
            res[i]=k;
            k*=nums[i];
        }

        return res;
    }
};