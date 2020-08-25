#include<vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> generate(int numRows)
     {
        vector<vector<int>> res;
        if(numRows==0)
            return res;
        for(int i=0;i<numRows;i++)
        {
            vector<int> temp;
            if(i==0)
            {
                temp.push_back(1);
                res.push_back(temp);
                continue;
            }
            temp.push_back(res[i-1][0]);
            for(int j=1;j<res[i-1].size();j++)
            {
                int t=res[i-1][j-1]+res[i-1][j];
                temp.push_back(t);
            }
            temp.push_back(res[i-1][res[i-1].size()-1]);
            res.push_back(temp);
        }
        return res;
    }
};