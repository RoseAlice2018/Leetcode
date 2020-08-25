#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
    int count=0;
    int findTargetSumWays(vector<int>& nums, int S) 
    {
        int sum=0,i=0;
        caculate(nums,S,sum,0);
        return count;
    }
    int caculate(vector<int>& nums,int S,int sum,int i)
    {
        if(i==nums.size())
        {
            if(S==sum)
                count++;
        }
        else
        {
            caculate(nums,S,sum+nums[i],i+1);
            caculate(nums,S,sum-nums[i],i+1);
        }
        
    }
};