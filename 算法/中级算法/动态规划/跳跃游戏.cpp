#include<vector>
using namespace std;
class Solution {
public:
    bool canJump(vector<int>& nums) {
        bool dp[nums.size()+1]={false};
        if(nums.size()<=1)
            return true;
        dp[0]=true;
        for(int i=1;i<nums.size();i++)
        {
            for(int j=0;j<i;j++)
            {
                int distance=i-j;
                if(nums[j]>=distance&&dp[j]==true)
                {
                    dp[i]=true;
                    break;
                }
            }
        }
        return dp[nums.size()-1];
    }
};