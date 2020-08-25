#include<iostream>
#include<stack>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        if(s.length()%2!=0)
        {
            return false;
        }
        if(s.empty())
            return true;
        stack<char> s1;
        stack<char> s2;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='('||s[i]=='['||s[i]=='{')
                s1.push(s[i]);
            else
            {
                s2.push(s[i]);
                if(s1.empty())
                {
                    return false;
                }
                char c=s1.top();
                if(s[i]==')'&&c=='(')
                    s1.pop();
                else if(s[i]==']'&&c=='[')
                    s1.pop();
                else if(s[i]=='}'&&c=='{')
                    s1.pop();
                else
                {
                    return false;
                }
                s2.pop();                
            }
            
        }
        if(!s1.empty()||!s2.empty())
        {
            return false;
        }
        return true;
    }
};