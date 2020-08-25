#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    bool compare(int s1[26],int s2[26])
    {
        for(int i=0;i<26;i++)
        {
            if(s1[i]!=s2[i])
                return false;
        }
        return true;
    }
    bool checkInclusion(string s1, string s2)
     {
         int character_[26]={0};
         for(int i=0;i<s1.size();i++)
         {
             character_[s1[i]-'a']+=1;
         }
         for(int j=0;j+s1.size()<=s2.size();j++)
         {
             int temp[26]={0};
             for(int i=j;i<j+s1.size();i++)
             {
                 temp[s2[i]-'a']+=1;
             }
            if(compare(character_,temp))
                return true;
         }
         return false;
    }
};