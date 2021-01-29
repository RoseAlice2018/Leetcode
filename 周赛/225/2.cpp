#include<iostream>
using namespace std;
class Solution {
public:
    int minCharacters(string a, string b) {
        string word1=a,word2=b;
        int r1=dp(word1,word2);
        int r2=dp(word2,word1);
        int r3=a.size()+b.size()-findmax(a,b);
        return min(r1,min(r2,r3));
    }
    int findmax(string& a,string& b)
    {
        int set[26]={0};
        int ret=0;
        for(int i=0;i<a.size();i++)
            set[a[i]-'a']++;
        for(int i=0;i<b.size();i++)
            set[b[i]-'a']++;
        for(int i=0;i<26;i++)
            if(set[i]>ret)
                ret=set[i];
        return ret;
    }
    int dp(string& word1,string& word2)
    {
         int dp_matrix[word1.size()+2][word2.size()+2];
        for(int i=0;i<=word2.size();i++)
            dp_matrix[0][i]=0;
        for(int i=0;i<=word1.size();i++)
            dp_matrix[i][0]=0;
        for(int i=1;i<=word1.size();i++)
        {
            for(int j=1;j<=word2.size();j++)
            {
                if(word1[i-1]<word2[j-1])
                {
                    dp_matrix[i][j]=dp_matrix[i-1][j-1];
                }
                else
                {
                    dp_matrix[i][j]=dp_matrix[i-1][j-1]+1;
                }
            }
        }

        return dp_matrix[word1.size()][word2.size()];
    }
};