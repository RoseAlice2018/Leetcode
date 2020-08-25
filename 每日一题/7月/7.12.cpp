#include<vector>
using namespace std;
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) 
    {
        int M=dungeon.size();
        int N=dungeon[0].size();
        int dp[M[N];
        if(dungeon[0][0]>0)
            dp[0][0]=1;
        else
        {
            dp[0][0]=-1*dungeon[0][0]+1;
        }
        
        for(int i=0;i<N;i++)
        {
            if(dungeon[0][i])
        }
        for(int i=M-1;i>=0;i--)
        {
            for(int j=N-1;j>=0;j--)
            {
                int up=dungeon[i-1][j]+dungeon[i][j];
                int left=dungeon[i][j-1]+dungeon[i][j];
                if(left>up)
                {
                    if(left>0)
                        dp[i][j]=1;
                    
                }
            }
        }
    }
};