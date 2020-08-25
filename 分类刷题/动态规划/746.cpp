#include<vector>
#include<math.h>
using namespace std;
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost)
     {
         int length=cost.size();
         int dp[length+2];
         dp[1]=0;
         if(length==3)
         {
             dp[3]=min(cost[0]+cost[2],cost[1]);
             return dp[3];
         }
         if(length==2)
         {
             dp[2]=min(cost[0],cost[1]);
             return dp[2];
         } 
        dp[2]=min(cost[0],cost[1])+cost[2];
        dp[3]=min(cost[0]+cost[2],cost[1])+cost[3];                                                     
         for(int i=4;i<length;i++)
         {
             dp[i]=cost[i]+min(dp[i-1],dp[i-2]);
         }
        return min(dp[length-1],dp[length-2]);
    }
};