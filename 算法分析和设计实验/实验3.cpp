#include<iostream>
#include<string.h>
#include<vector>
#include<set>
using namespace std;
#define Max 100
int dp[Max][Max];
int flag[Max][Max];
set<int> location;
//
string LONGESTSUBSEQUENCE="";
int max(int a,int b)
{
    return a>b?a:b;
}
   int longestCommonSubsequence(string text1, string text2)
     {
         int len1=text1.size();
         int len2=text2.size();
         int maxlen=max(len1,len2);
         for(int i=0;i<len1;i++)
         {
             for(int j=0;j<len2;j++)
             {
                 if(text1[i]==text2[j])
                 {
                     dp[i+1][j+1]=dp[i][j]+1;
                     flag[i+1][j+1]=0;
                 }
                 else 
                 {
                     if(dp[i][j+1]>=dp[i+1][j])
                     {
                         dp[i+1][j+1]=dp[i][j-1];
                         flag[i+1][j+1]=1;
                     }
                     else
                     {
                         dp[i+1][j+1]=dp[i+1][j];
                         flag[i+1][j+1]=2;
                     }
                     
                     
                 }
                    
             }
         }
         return dp[len1][len2];
    }
void getsubsequce(int x,int y,string s)
{
    if(x==0||y==0)
        return;
    if(flag[x][y]==0)
    {
        getsubsequce(x-1,y-1,s);
        LONGESTSUBSEQUENCE+=s[x-1];
        location.insert((x-1));
    }
    else if(flag[x][y]==1)
        getsubsequce(x-1,y,s);
    else 
        getsubsequce(x,y-1,s);
}
int minInsertions(string s)
     {
        int n = s.size();
        string rs(s.rbegin(),s.rend());
        int longestcommomsub=longestCommonSubsequence(s,rs);
        getsubsequce(n,n,s);
        return n-longestcommomsub;
    }
 
int main()
{
    string p="Ab3";
    string rp(p.rbegin(),p.rend());
    memset(dp,0,sizeof(dp));
    int res=minInsertions(p);
    int len=p.size();
    cout<<res<<endl;
    string re="";
    for(int i=0;i<p.size();i++)
    {
        if(location.count(i))
        {
            re+=p[i];
        }
        else
        {
            re+=p[i];
            re+=rp[i];
        }
        
    }
    cout<<re;
    return 0;
}