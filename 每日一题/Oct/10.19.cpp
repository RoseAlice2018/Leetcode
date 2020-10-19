#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    bool backspaceCompare(string S, string T) 
    {
        string S1,T1;
        for(int i=0;i<S.size();i++)
        {
            if(S[i]=='#')
             { if(!S1.empty())   S1.pop_back();}
            else{
                S1.push_back(S[i]);
            }
        }
         for(int i=0;i<T.size();i++)
        {
            if(T[i]=='#')
              { if(!T1.empty())  T1.pop_back();}
            else{
                T1.push_back(T[i]);
            }
        }
        if(S1==T1)
            return  true;
        else 
            return false;
    }
};