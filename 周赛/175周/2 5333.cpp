#include<iostream>
using namespace std;
class Solution {
public:
    int minSteps(string s, string t) 
    {
        int nums[26]={0};
        int numst[26]={0};
        for(int i=0;i<s.size();i++)
        {
             int c=s[i]-'a';
             nums[c]++;
        }
        for(int i=0;i<t.size();i++)
        {
            int c=t[i]-'a';
            numst[c]++;
        }
        int res=0;
        for(int i=0;i<26;i++)
        {
            int temp=nums[i]-numst[i];
            if(temp>0)
            {
                res+=temp;
            }
        }  
        return res; 
    }
};