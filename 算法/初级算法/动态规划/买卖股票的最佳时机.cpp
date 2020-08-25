#include<vector>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        
        int n=prices.size();
        if(n<=1)
            return 0;
        int dp[n+2];
        dp[1]=0;
        int min=prices[0];
        for(int i=2;i<=n;i++)
        {
            if(prices[i-2]<min)
                min=prices[i-2];
            int temp=prices[i-1]-min;
            if(temp>dp[i-1])
                dp[i]=temp;
            else
            {
                dp[i]=dp[i-1];
            }  
        }
        return dp[n];

    }
};