#include<iostream>
using namespace std;
class Solution {
public:
    int countVowelStrings(int n)
     {
         if(n==1)
            return 5;
        else if(n==2)
            return 15;
        else if(n==0)
            return 0;
        int dp[5];
        dp[0]=5,dp[1]=4,dp[2]=3,dp[3]=2,dp[4]=1;
        int res=0;
        for(int i=3;i<=n;i++)
        {
            int a,b,c,d,e;
            a=dp[0]+dp[1]+dp[2]+dp[3]+dp[4];
            b=dp[1]+dp[2]+dp[3]+dp[4];
            c=dp[2]+dp[3]+dp[4];
            d=dp[3]+dp[4];
            e=dp[4];
            dp[0]=a;
            dp[1]=b;
            dp[2]=c;
            dp[3]=d;
            dp[4]=e;
        }
        res=dp[0]+dp[1]+dp[2]+dp[3]+dp[4];
        return res;
    }
};