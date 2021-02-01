
#include<iostream>
#include<string.h>
#include<unordered_map>
using namespace std;
class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> dic;
        for(int i=0;i<s.size();i++)
        {
            if(dic.count(s[i]))
                dic[s[i]]++;
            else 
                dic[s[i]]=1;
        }
        for(int i=0;i<t.size();i++)
        {
            if(dic.count(t[i]))
            {
                dic[t[i]]--;
                if(dic[t[i]]<0)
                    return false;
            }
            else 
                return false;
        }
        for(auto iter=dic.begin();iter!=dic.end();iter++)
        {
            if(iter->second!=0)
                return false;
        }
        return true;
    }
};