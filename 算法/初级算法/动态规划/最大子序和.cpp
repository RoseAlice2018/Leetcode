#include<vector>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums)
     {
        int n=nums.size();
        int dp[n+5];
        dp[0]=max(nums[0],0);
        int maxx=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            dp[i]=max(dp[i-1]+nums[i],nums[i]);
            if(dp[i]>maxx)
                maxx=dp[i];
        }
        return maxx;
    }
};