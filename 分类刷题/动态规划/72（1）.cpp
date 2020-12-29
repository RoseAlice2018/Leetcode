#include<string>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        return dp(word1.size()-1,word2.size()-1,word1,word2);
    }
    int dp(int i,int j,string& s1,string& s2)
    {
        if(i>=0&&j>=0)
        {
            if(s1[i]==s2[j])
                return dp(i-1,j-1,s1,s2);
            else
            {
                return min(
                    dp(i,j-1,s1,s2)+1,//insert
                    min(
                        dp(i-1,j,s1,s2)+1,//delete
                        dp(i-1,j-1,s1,s2)+1//replace
                    )
                );
            }
        }
        else
        {
            if(i<0)
            {
                return j+1;//insert j
            }
            if(j<0)
            {
                return i+1;
            }
        }
        return 0;
    }
};
