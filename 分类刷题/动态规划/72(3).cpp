#include<string>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int replace_skip=0;
        int insert=1;
        int delete_=1;
        int res=0;
        for(int i=1;i<=word1.size();i++)
        {
            for(int j=1;j<=word2.size();j++)
            {
                if(word1[i-1]==word2[j-1])
                {
                    res=replace_skip;
                }
                else
                {
                    res=min(insert+1,min(delete_+1,replace_skip+1));
                }
            }
              insert++;
                    delete_++;
                    replace_skip++;
        }
        return res;
    }
};
