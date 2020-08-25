#include<string>
using namespace std;
class Solution {
public:
    bool isSubsequence(string s, string t) 
    {
        int left=0;
        for(int i=0;i<t.size();i++)
        {
            if(left==s.size())
                return true;
            if(t[i]==s[left])
                left++;
        }
        if(left==s.size())
            return true;
        return false;
    }
};