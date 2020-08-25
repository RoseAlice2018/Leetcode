#include<vector>
#include<string>
#include<iostream>
using namespace std;
class Solution {
public:
    bool comp(string s1,string s2)
    {
        int charecter_[26]={0};
        for(int i=0;i<s1.size();i++)
        {
            charecter_[s1[i]-'a']++;
        }
        for(int i=0;i<s2.size();i++)
        {
            charecter_[s2[i]-'a']--;
        }
        for(int i=0;i<26;i++)
        {
            if(charecter_[i]!=0)
                return false;
        }
        return true;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        vector<vector<string>> res;
        if(strs.size()==0)
            return NULL;
        int N=strs.size();
        int Path[100]={0};
        int count=0;
        for(int i=0;i<strs.size();i++)
        {
            if(Path[i]==0)
            {
                res[count].push_back(strs[i]);
                Path[i]=1;
                for(int j=0;j<strs.size();j++)
                {
                    if(Path[j]==0)
                    {
                        if(comp(strs[i],strs[j]))
                        {
                            Path[j]=1;
                            res[count].push_back(strs[j]);
                        }
                    }
                }
                count++;
            }
        }
        return res;
    }
};