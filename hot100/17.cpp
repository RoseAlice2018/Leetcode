#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;
class Solution {
public:
    unordered_map<char,string> dmap = {{'2',"abc"},{'3',"def"},{'4',"ghi"},{'5',"jkl"},
        {'6',"mno"},{'7',"qprs"},{'8',"tuv"},{'9',"wxyz"}};
    vector<string> letterCombinations(string digits) 
    {
         int len=digits.size();
         if(!len)
            return {};
        vector<string> ans;
        if(len==1)
        {
            string thisd=dmap[digits[0]];
            int len1=thisd.size();
            string temp="";
            for(int i=0;i<len1;i++)
            {
                ans.push_back(temp+thisd[i]);
            }
            return ans;
        }
        else
        {
            vector<string> last=letterCombinations(digits.substr(1,len-1));
            string nowstring=dmap[digits[0]];
            int len1=nowstring.size();
            int len2=last.size();
            for(int i=0;i<len1;i++)
            {
                for(int j=0;j<len2;j++)
                {
                    ans.push_back(nowstring[i]+last[j]);
                }
            }
        }
        return ans;
    }
};