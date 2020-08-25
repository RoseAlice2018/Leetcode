#include<iostream>
#include<unordered_map>
#include<string>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string ,vector<string>> temp;
        for(auto s:strs)
        {
            string t=s;
            sort(t.begin(),t.end());
            temp[t].push_back(s);
        }
        for(auto t1:temp)
            res.push_back(t1.second);
        return res;
    }
};

