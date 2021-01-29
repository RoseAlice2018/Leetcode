#include<vector>
using namespace std;
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int dp[nums.size()+10];
        dp[0]=1;
        int res = nums.size()>0?1:0;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]>nums[i-1])
            {
                dp[i]=dp[i-1]+1;
            }
            else
            {
                dp[i] = 1;
            }
            if(dp[i]>res)
                res=dp[i];
        }
        return res;
    }
};