#include<string>
#include<iostream>
using namespace std;
class Solution {
public:
    
    string reverseWords(string s) 
    {   
        string res;
        if(s.length()==0)
            return res;
        string temp;
        for(int i=0;i<s.length();i++)
        {
            
            if(s[i]!=' '&&i<s.length()-1)
            {
                temp.push_back(s[i]);
            }
            else
            {
                //cout<<i<<endl;
                // reverse(temp,res);
                if(i==s.length()-1)
                    temp.push_back(s[i]);
                for(int j=temp.length()-1;j>=0;j--)
                 {
                     char c=temp[j];
                 //    cout<<c<<endl;
                     res.push_back(c);
                  //   cout<<res<<endl;
                }
               // cout<<temp<<endl;
                //cout<<res<<endl;
                temp="";
                 if(i!=s.length()-1)
                res.push_back(' ');
            }          
            
        }
        return res;
    }
};