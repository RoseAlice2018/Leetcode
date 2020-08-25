#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Solution {
public:
    int translateNum(int num) 
    {
        if(num<10)
            return 1;
        else if(num>=10&&num<=25)
        {
            return 2;
        }
        else if(num>25&&num<100)
        {
            return 1;
        }
        string s=to_string(num);
        int length=s.length();
        int dp[100]={0};
        dp[0]=1;
        if((s[1]-'0'+(s[0]-'0')*10)<=25&&((s[1]-'0'+(s[0]-'0')*10)>=10))
        {
            dp[1]=2;
        }
        else 
            dp[1]=1;
        for(int i=2;i<length;i++)
        {
            if((s[i]-'0'+(s[i-1]-'0')*10)<=25&&((s[i]-'0'+(s[i-1]-'0')*10)>=10))
            {
                dp[i]=dp[i-1]+dp[i-2];
            }
            else
            {
                dp[i]=dp[i-1]*1;
            }
            
        }
        return dp[length-1];
    }
};