#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    int countS(string t)
    {
        int res=0;
        for(int i=0;i<t.size();i++)
        {
            if(t[i]=='/')
            {
                res++;
            }
        }
        return res;
    }
    string simplifyPath(string path) {
        string res;
        int count=0;// number of '/'
        int dot=0;// number of dot
        for(int i=0;i<path.size();i++)
        {
            if(path[i]=='/')
            {
                count++;
                if(count==1&&i!=path.size()-1)
                    res.push_back(path[i]);
                else
                {
                    continue;
                }
                
            }
            else if(path[i]=='.')
            {
                if(path[i+1]=='dot')
                {
                    // 回到上层
                    if(countS(res)<=1)
                    {
                        i++;
                        continue;
                    }
                    else
                    {
                        res.pop_back();// 退出上一个‘/’
                        while (res[res.size()-1]!='/')
                        {
                            res.pop_back();
                        }
                        res.pop_back();
                        count=0;
                        i++;
                    } 
                }
                else
                {
                    //
                    res.pop_back();
                    count=0;
                    continue;
                }
                
            }
            else
            {
                count=0;
                res.push_back(path[i]);
            }
            
        }
        return res;
    }
};