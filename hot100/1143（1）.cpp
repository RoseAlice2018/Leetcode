#include<string>
#include<vector>
using namespace std;
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        if(text1.size() == 0 || text2.size() == 0)
            return 0;
        vector<vector<int>> memo = vector(text1.size() + 1, vector(text2.size() + 1, 0)); // memo[i][j] 代表以 str1[i - 1]， str2[j - 1] 位置的元素为结尾的str1， str2 两个子字符串的 最长公共子序列
        for(int i = 0; i < text1.size(); i++)
            for(int j = 0; j < text2.size(); j++)
                if(text1[i] == text2[j])
                    memo[i + 1][j + 1] = memo[i][j] + 1;
                else
                    memo[i + 1][j + 1] = max(memo[i][j + 1], memo[i + 1][j]);
        return memo[text1.size()][text2.size()];
    }
};