#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    int monotoneIncreasingDigits(int N) {
        string num=to_string(N);
        string res;
        monotone(res,num,0);
        int ress=atoi(res.c_str());
        return ress;
    }
    string monotone(string& res,string num,int index)
    {
        if(index>=num.size())
            return  res;
        char temp=num[index];
        for(int i=index;i<num.size();i++)
        {
            if(num[i]<temp)
            {
                /* to end */
                res.push_back(temp-1);
                for(int j=index+1;j<num.size();j++)
                    res.push_back('9');
                return res;
            }
            else if(num[i]>temp)
            {
                break;
            }
        }
        res.push_back(temp);
        return monotone(res,num,index+1);
    }
};