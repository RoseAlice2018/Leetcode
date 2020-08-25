#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Solution {
public:
    vector<string> res;
    void letter(int start,string S)
    {
        if(start>=S.size())
        {
            res.push_back(S);
            return ;
        }
        if(start==S.size()-1&&S[start]>='0'&&S[start]<='9')
        {
            
        }
        for(int i=start;i<S.size();i++)
        {
            char temp=S[i];
            if(temp>='A'&&temp<='Z')
            {
                letter(i+1,S);
                S[i]+=32;
                // change to lower case
                letter(i+1,S);
                S[i]-=32;
            }
            else if(temp>='a'&&temp<='z')
            {
                letter(i+1,S);
                S[i]-=32;
                letter(i+1,S);
                S[i]+=32;
            }
        }
    }
    vector<string> letterCasePermutation(string S)
     {
         letter(0,S);
         return res;
    }
};