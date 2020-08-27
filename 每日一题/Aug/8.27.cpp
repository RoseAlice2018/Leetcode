#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    int idCode(string s)
    {
        int hashcode=0;
        for(int i=0;i<3;i++)
        {
            hashcode=hashcode*10+s[i]-'A'+1;
        }
        return hashcode;
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        vector<string> res;
        string from="JFK";
        int begin=idCode(from);
        
    }
};