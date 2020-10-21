#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Solution {
public:
    bool isLongPressedName(string name, string typed) 
    {
        int index=0;
        vector<pair<char,int>> dic1;
        vector<pair<char,int>> dic2;
        char nowchar=name[0];
        int count=1;
        for(int i=1;i<name.size();i++)
        {
            if(nowchar==name[i])
            {
                count++;
            }
            else
            {
                dic1.push_back(pair<char,int>(nowchar,count));
                nowchar=name[i];
                count=1;
            }  
        }
        dic1.push_back(pair<char,int>(nowchar,count));
        nowchar=typed[0];
        count=1;
        for(int i=1;i<typed.size();i++)
        {
            if(nowchar==typed[i])
            {
                count++;
            }
            else
            {
                dic2.push_back(pair<char,int>(nowchar,count));
                nowchar=typed[i];
                count=1;
            }  
        }
          dic2.push_back(pair<char,int>(nowchar,count));
        if(dic1.size()!=dic2.size())
        {
            return false;
        }
        for(int i=0;i<dic1.size();i++)
        {
            if(dic1[i].first==dic2[i].first)
            {
                if(dic1[i].second<=dic2[i].second)
                    ;
                else 
                    return false;
            }
            else
            {
                return false;
            }   
        }
        return true;
    }
};