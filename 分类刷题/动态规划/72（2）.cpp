#include<iostream>
using namespace std;
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n=word1.size()-1;
        int m=word2.size()-1;
        int dp[100][100]={0};
        for(int i=0;i<n;i++)
            dp[i][0]=i;
        for(int j=0;j<m;j++)
            dp[0][j]=j;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(word1[i]==word2[j])
                {
                    dp[i][j]=dp[i-1][j-1];
                }
                else
                {
                    dp[i][j]=min(dp[i][j-1],min(dp[i-1][j],dp[i-1][j-1]));
                }
            }
        }
    return dp[n][m];
        } 
    };