#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    string res;   
    string sortString(string s)
    {
         while(findmin(s,res)||findmax(s,res));
        return res;
    }
    
    bool findmin(string s,string& res)
    {
        char min=120;
        //min 表示当前字符串中的最小值
        for(int i=0;i<s.size();i++)
        {
            if(s[i]<min&&isnotin(s[i]))
                min=s[i];                
        }
        if(min!=120)
        {
           res.push_back(min);
            return true;
        }
        return false;        
    }
       bool findmax(string s,string& res)
    {
        char min=20;
        //min 表示当前字符串中的最小值
        for(int i=0;i<s.size();i++)
        {
            if(s[i]>min&&isnotin(s[i]))
                min=s[i];                
        }
        if(min!=20)
        {
           res.push_back(min);
            return true;
        }
        return false;        
    }
    bool isnotin(char a)
    {
        for(int i=0;i<res.size();i++)
        {
            if(res[i]==a)
                return false;
        }
        return true;
    }
};