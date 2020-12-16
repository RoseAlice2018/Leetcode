#include<iostream>
#include<string>
#include<map>
using namespace std;
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        int index=0;
        int j=0;
        map<char,string> dic;
        for(int i=0;i<pattern.size();i++)
        {
            string word;
            for(j=index;j<s.size();j++)
            {
                if(s[j]!=' ')
                    word.push_back(s[j]);
                else 
                {
                    index=j+1;
                    break;
                }
            }
            if(dic.count(pattern[i]))
            {
                if(dic[pattern[i]]!=word)
                    return false;
            }
            else
            {
                auto iter=dic.begin();
                for(iter;iter!=dic.end();iter++)
                {
                    if(iter->second==word)
                        return false;
                }
                dic[pattern[i]]=word;
            }
            
        }
        if(j<s.size())
            return false;
        return true;
    }
};