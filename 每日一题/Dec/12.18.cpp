#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;
class Solution {
public:
    char findTheDifference(string s, string t) {
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
                if(dic[t[i]]==-1)
                    return t[i];
            }
            else 
                return t[i];
        }
        return t[0];
    }
};