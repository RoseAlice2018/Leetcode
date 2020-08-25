#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
bool suit(char& a)
{
    if(a>='0'&&a<='9')
    {
        return true;
    }
    else if(a>='a'&&a<='z')
    {
        a=a-32;
        return true;
    }
    else if(a>='A'&&a<='Z')
    {
        return true;
    }
    else
        return false;
}
    bool isPalindrome(string s) 
    {
        int left=0;
        int right=s.size()-1;
        if(!s.size())
            return true;
        while(left<=right)
        {
            while(!suit(s[left]))
            {
                left++;
                if(left>right)
                    return true;
            }
            while(!suit(s[right]))
            {
                right--;
                if(right<left)
                    return true;
            }
            if(s[left]==s[right])
            {
                left++;
                right--;
                continue;
            }
            else
            {
                return false;
            }
            
        }return true;
    }
};