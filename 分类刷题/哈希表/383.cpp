#include<iostream>
#include<unordered_map>
using namespace std;
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> dic;
        for(int i=0;i<magazine.size();i++)
        {
           if(dic.count(magazine[i]))
            dic[magazine[i]]++;
            else
            {
                dic[magazine[i]]=1;
            }
        }
        for(int i=0;i<ransomNote.size();i++)
        {
            if(dic.count(ransomNote[i]))
            {
                dic[ransomNote[i]]--;
                if(dic[ransomNote[i]]<0)
                    return false;
            }
            else 
                return false;
        }
        return true;
    }
};