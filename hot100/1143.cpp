#include<string>
using namespace std;
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2)
     {
         int len1=text1.size();
         int len2=text2.size();
         int maxlen=max(len1,len2);
         int dp[maxlen+2][maxlen+2];
         memset(dp,0,sizeof(dp));
         for(int i=0;i<len1;i++)
         {
             for(int j=0;j<len2;j++)
             {
                 if(text1[i]==text2[j])
                 {
                     dp[i+1][j+1]=dp[i][j]+1;
                 }
                 else 
                    dp[i+1][j+1]=max(dp[i+1][j],dp[i][j+1]);
             }
         }
         return dp[len1][len2];
    }
};