#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        int character_[200]={0};
        int num=0;
        int left=0,right=0;
        int temp=0;
        if(s.size()==0)
            return 0;
        while (left<=right)
        {
            if(character_[s[right]]==0)
            {
                character_[s[right]]=1;
                right++;
                temp++;
                if(temp>num)
                    num=temp;
            }
            else 
            {
                //归0
                int i=0;
                for( i=left;i<right;i++)
                {
                   
                    if(s[i]==s[right])
                    {
                        break;
                    } 
                    character_[s[i]]=0;
                    temp--;
                }
                left=i+1;
                //
                right++;
                
            }
            if(right==s.size()-1)
                break;
        }
        return num;
    }
};