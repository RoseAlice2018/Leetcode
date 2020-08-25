#include<vector>
using namespace std;
class Solution {
public:
    void reverseString(vector<char>& s)
    {
        if(s.size()==0)
        {
            return;
        }
        for(int i=0;i<s.size()/2;i++)
         {
            s[i]=s[s.size()-1-i]-s[i];
            s[s.size()-1-i]=s[s.size()-1-i]-s[i];
            s[i]=s[i]+s[s.size()-1-i];
         }
         return;
    }
};