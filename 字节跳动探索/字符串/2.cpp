#include<string>
#include<vector>
using namespace std;
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs)
     {
        string res="";
        if(strs.size()==0)
            return res;
        int minsize=strs[0].size();
        for(int i=0;i<strs.size();i++)
        {
            if(strs[i].size()==0)
                return res;
            if(strs[i].size()<minsize)
                minsize=strs[i].size();
        }
        int count=0;
        int tag=1;
        while (tag&&count<=minsize)
        {
            char t=strs[0][count];
            for(int i=0;i<strs.size();i++)
            {
                if(strs[i][count]!=t)
                    tag=0;
            }
            if(tag)
            {
                res+=t;
                count++;
            }   
            else 
            {
                break;
            }

        }
        return res;
            
    }
};