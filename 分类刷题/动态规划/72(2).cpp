#include<string>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int dp_matrix[word1.size()+2][word2.size()+2];
        for(int i=0;i<=word2.size();i++)
            dp_matrix[0][i]=i;
        for(int i=0;i<=word1.size();i++)
            dp_matrix[i][0]=i;
        for(int i=1;i<=word1.size();i++)
        {
            for(int j=1;j<=word2.size();j++)
            {
                if(word1[i-1]==word2[j-1])
                {
                    dp_matrix[i][j]=dp_matrix[i-1][j-1];
                }
                else
                {
                    dp_matrix[i][j]=min(dp_matrix[i][j-1]+1,min(dp_matrix[i-1][j]+1,dp_matrix[i-1][j-1]+1));
                }
            }
        }

        return dp_matrix[word1.size()][word2.size()];
    }
};
