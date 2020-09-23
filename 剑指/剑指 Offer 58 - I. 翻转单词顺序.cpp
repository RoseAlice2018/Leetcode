#include<string>
#include<stack>
using namespace std;
class Solution {
public:
    string reverseWords(string s) {
        stack<string> temp;
        string t="";
        if(!s.size())
            return t;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]==' '||i==s.size()-1)
            {
                if(i==s.size()-1&&s[i]!=' ')
                    t.push_back(s[i]);
                if(t.size()>=1)
                    temp.push(t);
                t="";
            }
            else if(s[i]!=' ')
            {
                t.push_back(s[i]);
            }
        }
        t="";
        while(!temp.empty())
        {
            t.append(temp.top());
            if(temp.size()>1)
                t.push_back(' ');
            temp.pop();
        }
        return t;
    }
};