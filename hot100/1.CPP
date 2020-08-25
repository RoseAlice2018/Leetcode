#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> res;
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        for(int i=0;i<nums.size()-1;i++)
        {
            for(int j=i+1;j<nums.size();j++)
            {
                if(nums[i]+nums[j]==target)
                {
                    res.push_back(i);
                    res.push_back(j);
                    break;
                }
            }
            if(!res.empty())
            {
                break;
            }
        }
        return res;
    }
};