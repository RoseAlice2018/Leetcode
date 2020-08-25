#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) 
    {
        int len=T.size();
        vector<int> res(len);
        res[len-1]=0;
        for(int i=len-2;i>=0;i--)
        {
            for(int j=i+1;j<len;j+=res[j])
            {
                if(T[i]<T[j])
                {
                    res[i]=j-i;
                    break;
                }
                else if(res[j]==0)
                {
                    res[i]=0;
                    break;
                }
            }
        }
        return res;
    }
};