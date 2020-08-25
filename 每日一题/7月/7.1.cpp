#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) 
    {
        int n1=A.size();
        int n2=B.size();
        int dp[n1+2][n2+2];
        for(int i=1;i<=n1;i++)
        {
            for(int j=1;j<=n2;j++)
            {
               if(A[i-1]==B[j-1])
               {
                   dp[i][j]=max(dp[i-1][j-1]+1,max(dp[i-1][j],dp[i][j-1]));
               }
               else 
               {
                   dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
               }
            }
        }
        return dp[n1][n2];
    }
};