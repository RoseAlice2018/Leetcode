#include<string>
using namespace std;
class Solution {
public:
    bool isAnagram(string s, string t) 
    {
        int temp[26]={0};
        if(s.size()!=t.size())
            return false;
        for(int i=0;i<s.size();i++)
        {
            int tt=s[i]-'a';
            temp[tt]++;
        }
         for(int i=0;i<s.size();i++)
        {
            int tt=t[i]-'a';
            temp[tt]--;
        }
        for(int i=0;i<26;i++)
            if(temp[i]!=0)
                return false;
        return true;
    }
};