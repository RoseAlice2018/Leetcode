#include<iostream>
#include<vector>
#include<string>
#include<math.h>
using namespace std;
class Solution {
public:
    int minimumOneBitOperations(int n) 
    {
        int dp[100];
        for(int i=0;i<=n;i++)
            dp[i]=INT_MAX;
        dp[0]=0;
        dp[1]=1;
        dp[2]=3;
        dp[3]=4;
        for(int i=4;i<=n;i++)
        {
            
          
            string temp;
            ato(temp,i);
            //操作1
            int a=temp[temp.size()-1]-'0';
                a=!a;
            char tt=a+'0';
            temp.pop_back();
            temp.push_back(tt);
            int n_=to_num(temp);
            if(dp[n_]!=INT_MAX)
                 dp[i]=dp[n_]+1;
            //操作2
            // 复原
             a=temp[temp.size()-1]-'0';
            a=!a;
             tt=a+'0';
             temp.pop_back();
            temp.push_back(tt);
            for(int i=temp.size()-1;i>=0;i--)
            {
                if(temp[i]=='0')
                    ;
                else
                {
                    if(i-1>=0)
                    {
                         int a=temp[i-1]-'0';
                        a=!a;
                         char tt=a+'0';
                         temp[i-1]=tt;
                         int n_=to_num(temp);
                         if(dp[n_]+1<dp[i])
                            dp[i]=dp[n_]+1;
                        break;         
                    }
                    else
                    {
                        break;
                    }
                    
                }
                
            }

        }
        return dp[n];
    }
    int to_num(string a)
    {
        int res=0;
        for(int i=0;i<a.size();i++)
        {
            res+=(a[i]-'0')*pow(2,a.size()-i-1);
        }
        return res;
    }
    void ato(string& temp,int n)
    {
        int i;
    for(i = 1; i < 33; i++)
    {
       if((unsigned int)(n & 0x80000000) == (unsigned int)(0x80000000))
       {
           temp.push_back('1');
       }
       else
       {
           temp.push_back('0');
       }
        n = (n & 0x7fffffff) << 1; 
    }

    }
};