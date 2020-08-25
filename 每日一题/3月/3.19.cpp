#include<string>
using namespace std;
class Solution {
public:
    int longestPalindrome(string s) 
    {
        int len=0;
        for(int i=0;i<s.length()-1;i++)
        {
            char c=s[i];
            for(int j=i+1;j<s.length();j++)
            {
                if(c==s[j]&&c!='0')
                {
                    len+=2;
                    s[i]='0';
                    s[j]='0';
                    break;
                }
            }
        }
        for(int i=0;i<s.length();i++)
        {
            if(s[i]!='0')
            {
                len++;
                break;
            }
        }
        return len;
    }
};