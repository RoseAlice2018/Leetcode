#include<string>
using namespace std;
class Solution {
public:
    bool differ(string s1,string s2)
    {
        if(s1.size()%s2.size()!=0)
            return false;
        for(int i=0;i<s1.size();i+=s2.size())
        {
            for(int j=i;j<s2.size();j++)
            {
                if(s1[j]!=s2[j-i])
                    return false;
            }
        }
        return true;
    }
    string gcdOfStrings(string str1, string str2) 
    {
        string res;
        string temp;
        for(int i=0;i<min(str1.size(),str2.size());i++)
        {
            temp.push_back(str1[i]);
            if(differ(str1,temp)&&differ(str2,temp))
            {
                res=temp;
            }
        }
        return res;
    }
};