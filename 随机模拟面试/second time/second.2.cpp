#include<string>
using namespace std;
class Solution {
    bool compare(string s1,string s2)
    {
        for(int i=0;i<s1.size();i++)
        {
            if(s1[i]!=s2[i])
                return false;
        }
        return true;
    }
public:
    bool repeatedSubstringPattern(string s) 
    {
        if(s.size()<2)
            return false;

        int i=1;
        while (i<s.size())
        {
            if(s.size()%i==0)
            {
                string s1=s.substr(0,i);
                int j=i,k=j+i;
                int flag=1;
                while(k<=s.size())
                {
                    string s2=s.substr(j,k);
                    if(compare(s1,s2))
                    {
                        j+=i;
                        k=k+i;
                        continue;
                    }
                    else
                    {
                        flag=0;
                        break;
                    }
                    
                }
                if(flag)
                    return true;
            }
            i++;
        }
        
        return false;
    }
};