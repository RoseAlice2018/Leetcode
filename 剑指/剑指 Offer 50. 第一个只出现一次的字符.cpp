#include<string>
#include<set>
#include<vector>
using namespace std;
class Solution {
public:
    char firstUniqChar(string s) {
        if(!s.size())
            return ' ';
        int dic[26]={0};
        set<int> res;
        vector<int> order;
        for(int i=0;i<s.size();i++)
        {
            dic[s[i]-'a']++;
            if(dic[s[i]-'a']==1)
            {
                res.insert(s[i]-'a');
                order.push_back(s[i]-'a');
            }
            else if(dic[s[i]-'a']>1)
            {
                res.erase(s[i]-'a');
            }
        }
        for(int i=0;i<order.size();i++)
        {
            if(res.count(order[i]))
            {
                return order[i]+'a';
            }
        }
    }
};