#include<vector>
using namespace std;
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) 
    {
        int maxsize=102;
        int dp[102][102];
        dp[0][0]=1;
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        for(int i=1;i<obstacleGrid[0].size();i++)
        {
            if(obstacleGrid[0][i]==1)
                dp[0][i]=0;
            else
            {
                dp[0][i]=dp[0][i-1];
            }
            
        }
         for(int i=1;i<obstacleGrid.size();i++)
        {
            if(obstacleGrid[i][0]==1)
                dp[i][0]=0;
            else
            {
                dp[i][0]=dp[i-1][0];
            }  
        }
        for(int i=1;i<obstacleGrid.size();i++)
        {
            for(int j=1;j<obstacleGrid[0].size();j++)
            {
                if(dp[i-1][j]==1&&dp[i][j-1]==0)
                    dp[i][j]=dp[i][j-1];
                else if(dp[i][j-1]==1&&dp[i-1][j]==0)
                    dp[i][j]=dp[i-1][j];
                else if(dp[i-1][j]==1&&dp[i][j-1]==1)
                    dp[i][j]=0;
                else
                {
                    dp[i][j]=dp[i-1][j]+dp[i][j-1];
                }
                
            }
        }
        return dp[m-1][n-1];
    }
};