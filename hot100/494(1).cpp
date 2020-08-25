#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
    int offset=1000;
    int findTargetSumWays(vector<int>& nums, int S) 
    {
        int length=nums.size();
        int dp[length+1][2002];
        dp[0][1000+nums[0]]=1;
        dp[0][1000-nums[0]]=1;
        for(int i=1;i<length;i++)
        {
            for(int sum=-1000;sum<=1000;sum++)
            {
                if(dp[i-1][sum+1000]>0)
                {
                    dp[i][sum + nums[i] + 1000] += dp[i - 1][sum + 1000];
                    dp[i][sum - nums[i] + 1000] += dp[i - 1][sum + 1000];
                }
            }
        }
        return S > 1000 ? 0 : dp[length - 1][S + 1000];
    }
    
};