#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
       
        // zero means do not hold the share
        // one means hold the share
        int length=prices.size(); 
        
        if(length<=1)
            return 0;
        else if(length==2&&prices[0]>=prices[1])
            return 0;
        else if(length==2)
            return prices[1]-prices[0];
        int dp[length][2];
        dp[0][0]=0;
        dp[0][1]=-prices[0];
        dp[1][0]=max(dp[0][0],dp[0][1]+prices[1]);
        dp[1][1]=max(dp[0][0]-prices[1],dp[0][1]);
        for(int i=2;i<length;i++)
        {
            dp[i][0]=max(dp[i-1][0],dp[i-1][1]+prices[i]);
            dp[i][1]=max(dp[i-2][0]-prices[i],dp[i-1][1]);
        }
        return dp[length-1][0];
    }
};