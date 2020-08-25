#include<string>
using namespace std;
class Solution {
public:
    bool isReverse(string s,int first,int last)
    {
        while (first<=last)
        {
            if(s[first]!=s[last])
                return false;
            first++;
            last--;
        }
        return true;        
    }
    int countSubstrings(string s)
     {
         int res=0;
         if(s.size()==0)
            return res;
        res=1;
        for(int i=1;i<s.size();i++)
        {
            // last equals to i
            res++;// last itself can be a reverse string
            for(int j=0;j<i;j++)
            {
                if(isReverse(s,j,i))
                    res++;
            }
        }
        return res;
    }
};