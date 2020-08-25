#include<string>
using namespace std;
class Solution {
public:
    string compressString(string S) 
    {
        string res;
        int count=0;
        for(int i=0;i<S.size();i++)
        {
            char c=S[i];
            for(int j=i;j<S.size();j++)
            {
                if(S[j]==c)
                {
                    count++;
                }
                else
                {
                    break;
                }
                
            }
            res.push_back(c);
            string d=to_string(count);
            res.append(d);
            i=i+count-1;
            count=0;
        }
        if(res.size()<S.size())
        {
            return res;
        }
        else
        {
            return S;
        }
        
    }
};