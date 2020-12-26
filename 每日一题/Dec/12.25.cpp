#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int index=0;
        int res=0;
        if(!g.size()||!s.size())
            return res;
        for(int i=0;i<g.size();i++)
        {
            if(s[index]>=g[i])
            {
                index++;
                res++;
                if(index>=s.size())
                    return res;
            }
            else
            {
                index++;
                i--;
                if(index>=s.size())
                    return res;
            }
            
        }
        return res;
    }
};