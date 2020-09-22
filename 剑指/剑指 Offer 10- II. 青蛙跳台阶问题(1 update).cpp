class Solution {
public:
    int numWays(int n) {
        long dp[n+10];
        dp[0]=1;
        dp[1]=1;
        dp[2]=2;
        for(int i=3;i<=n;i++)
        {
            dp[i]=(dp[i-1]+dp[i-2])%((int)1e9+7);
        }
        return dp[n];
    }
};