#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Solution {
public:
    string reverseWords(string s) {
       vector<string> res;
       string temp;
       for(int i=0;i<s.size();i++)
       {
           if(s[i]==' ')
           {
               if(temp=="")
               {
                   continue;
               }
               else
               {
                   res.push_back(temp);
                   temp.clear();
               }
               
           }
           else
           {
               temp.push_back(s[i]);
           }
       }
       if(!temp.empty())
        {
            res.push_back(temp);
            temp.clear();
        }
       string result;
       for(int i=res.size()-1;i>=0;i--)
       {
           result+=res[i];
           if(i>0)
           {
               result+=" ";
           }
       }
       return result;
    }
};