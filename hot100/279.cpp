#include<iostream>
using namespace std;
class Solution {
public:
    int numSquares(int n)
     {
         int dp[n+1];
        dp[0]=0;
         for(int i=1;i<n+1;i++)
         {
             int mins=INT32_MAX;
             for(int j=1;j*j<=i;j++)
             {
                 mins=min(mins,dp[i-j*j]);
             }
             dp[i]=mins+1;
         }
         return dp[n];
    }
};