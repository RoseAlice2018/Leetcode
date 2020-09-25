#include<string>
using namespace std;
class Solution {
public:
    string replaceSpace(string s) {
        string res;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]==' ')
            {
                res.append("%20");
            }
            else
            {
                res.push_back(s[i]);
            }
            
        }
        return res;
    }
};