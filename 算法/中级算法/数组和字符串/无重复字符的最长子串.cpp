#include<iostream>
#include<unordered_set>
using namespace std;
class Solution {
public:
     
    int lengthOfLongestSubstring(string s) 
    {
        int maxsize=0;
        int left=0,right=0;
        if(s.size()==0)
            return 0;
        unordered_set<char> dic;
        while(left<s.size())
        {
            while(right<s.size())
            {
               char temp=s[right];
               if(dic.count(temp))
               {
                   int t=right-left;
                   if(t>maxsize)
                    maxsize=t;
                    break;
               }
               else
               {
                   dic.insert(temp);
                   right++;
               }   
            }
            if(right>=s.size())
            {
                int t=right-left;
                if(t>maxsize)
                    maxsize=t;
                break;
            }
            dic.erase(s[left]);
            left++;
        }
        return maxsize;
    }
};