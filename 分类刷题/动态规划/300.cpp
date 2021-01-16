#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int dp[nums.size()+10];
        dp[0]=1;
        int res=1;
        for(int i=1;i<nums.size();i++)
        {
            int max=0;
            for(int j=0;j<i;j++)
            {
                if(nums[j]<nums[i])
                {
                    if(dp[j]>max)
                        max=dp[j];
                }
            }
            dp[i]=max+1;
            if(dp[i]>res)
                res=dp[i];
        }
        return nums.size()-1>=0?res:0;
    }
};