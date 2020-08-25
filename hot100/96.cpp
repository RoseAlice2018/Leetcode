class Solution {
public:
    int numTrees(int n) 
    {
        int dp[1000];
        dp[0]=0,dp[1]=1,dp[2]=2,dp[3]=5;
        if(n<=3)
            return dp[n];
        dp[0]=1;
        for(int i=4;i<=n;i++)
        {
            for(int j=0;j<=i-1;j++)
            {
                int k=i-1-j;
                dp[i]+=dp[k]*dp[j];
            }
        }
        return dp[n];
    }
};