#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    int longestPalindromeSubseq(string s) 
    {
        int size=s.size();
        int dp[size][size];
        memset(dp,0,sizeof(dp));
        for(int i=size-1;i>=0;i--)
        {
            dp[i][i]=1;
            for(int j=i+1;j<size;j++)
            {
                if(s[i]==s[j])
                {
                    dp[i][j]=dp[i+1][j-1]+2;
                }
                else 
                {
                    dp[i][j]=max(dp[i+1][j],dp[i][j-1]);

                }
            }
        }
        return dp[0][size-1];
    }
};