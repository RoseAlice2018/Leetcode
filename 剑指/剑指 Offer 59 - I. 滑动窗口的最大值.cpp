#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        if(k==0)
            return res;
        for(int i=0;i<=nums.size()-k;i++)
        {
            int max=INT_MIN;
            for(int j=i;j<i+k;j++)
            {
                if(nums[j]>max)
                    max=nums[j];
            }
            res.push_back(max);
        }
        return res;
    }
};