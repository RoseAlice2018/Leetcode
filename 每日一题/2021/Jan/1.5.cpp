#include<vector>
#include<string>
using namespace std;
class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        vector<vector<int>> res;
        if(s.empty())
            return res;
        int begin=0,end=0;
        char temp=s[0];
        int count=1;
        vector<int> b_e;
        for(int i=1;i<s.size();i++)
        {
            if(s[i]==temp)
            {
                count++;
            }
            else
            {
                temp=s[i];
                if(count>=3)
                {
                    b_e.push_back(begin);
                    b_e.push_back(end);
                    res.push_back(b_e);
                    b_e.clear();
                }
               begin=i;
               count=1;
            }
            end=i;
        }
            if(count>=3)
                {
                    b_e.push_back(begin);
                    b_e.push_back(end);
                    res.push_back(b_e);
                }
        return res;
    }
};