#include<string>
using namespace  std;
class Solution {
public:
    bool isSubsequence(string s, string t) 
    {
        int m=s.length();
        int n=t.length();
        bool dp[m+1][n+1];
        for(int j=0;j<=n;j++)
        {
            dp[0][j]=true;
        }
        for(int i=1;i<=m;i++)
        {
            for(int j=i;j<=n;j++)
            {
                if(s[i - 1] == t[j - 1]) { //由于i-1即第i个
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = dp[i][j - 1];
                }
                if(i == m && dp[i][j] == true) return true;  //剪枝
            }
        }
    }
};