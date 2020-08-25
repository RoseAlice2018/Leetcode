#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    int firstUniqChar(string s) 
    {
        if(s.size()==0)
            return -1;
        if(s.size()==1)
            return 0;
        int temp[26][2];
        for(int i=0;i<s.size();i++)
        {
            int t=s[i]-'a';
            temp[t][0]++;
            temp[t][1]=i;
        }
        int res=INT32_MAX;
        int tag=0;
        for(int i=0;i<26;i++)
        {
            if(temp[i][0]==1)
            {
                if(temp[i][1]<res)
                 {   
                     res=temp[i][1] ;
                     tag=1;
                 }
            }
        }
        if(!tag)
            return -1;
        return res;
    }
};