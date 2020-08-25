#include<iostream>
#include<string.h>
#include<vector>
using namespace std;
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) 
    { 
        string res="";
        if(strs.empty())
        {
            return res;
        }
       
        int minsize=strs[0].size();
        int tag=0;
        for(int i=0;i<strs.size();i++)
        {
            if(strs[i].size()<minsize)
            {
                minsize=strs[i].size();
                tag=i;
            }
        }
        //compare;
        for(int i=0;i<strs[tag].size();i++)
        {
            int flag=0;
            for(int j=0;j<strs.size();j++)
            {
                if(strs[j][i]!=strs[tag][i])
                    flag=1;
            }
            if(flag==1)
            {
                break;
            }
            else
            {
                char temp=strs[tag][i];
                res+=temp;
            }
            
        }
        return res;
    }
};