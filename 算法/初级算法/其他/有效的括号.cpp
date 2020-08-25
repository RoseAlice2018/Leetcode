#include<string>
#include<stack>
using namespace std;
class Solution {
public:
    bool isValid(string s) 
    {
        if(s.size()==0)
            return true;
        if(s.size()%2!=0)
            return false;
        stack<char> brackt;
        for(int i=0;i<s.size();i++)
        {
            char temp=s[i];
            if(temp=='('||temp=='{'||temp=='[')
                brackt.push(temp);
            else if(brackt.size())
            {
                char op=brackt.top();
                brackt.pop();
                if(op=='('&&temp==')')
                    continue;
                else if(op=='{'&&temp=='}')
                    continue;
                else if(op=='['&&temp==']')
                    continue;
                else 
                    return false;
            }
            else
            {
                return false;
            }
            
            
        }
        if(!brackt.size())
            return true;
        return false;
    }
};