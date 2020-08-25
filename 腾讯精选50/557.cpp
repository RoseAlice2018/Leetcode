#include<iostream>
using namespace std;
class Solution {
public:
    string res;
    string reverseWords(string s) 
    {
        if(s.length()==0)
            return res;
        for(int i=0;i<s.length();i++)
        {
            string temp;
            if(s[i]!=' '&&i!=s.length()-1)
            {
                temp=temp+s[i];
            }
            else
            {
                reverse(temp);
                temp="";
                if(i!=s.length()-1)
                res=res+' ';
            }          
            
        }
        return res;
    }
    void reverse(string temp)
    {
        for(int i=temp.length()-1;i>=0;i--)
        {
            char c=temp[i];
            res=res+c;
        }
    }
};