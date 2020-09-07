#include<vector>
using namespace std;
class Solution {
public:
    void insert(vector<vector<int>>& res,vector<int> temp)
    {
        int left=temp[0];
        int right=temp[1];
        for(int i=0;i<res.size();i++)
        {
            if(left>=res[i][0]&&right>=res[i][1])
            {
                res[i][1]=right;
                return ;
            }
            else if(left<=res[i][0]&&right<=res[i][1])
            {
                res[i][0]=left;
                return ;
            }
            else if(left<res[i][0]&&right>res[i][1])
            {
                res[i][0]=left;
                res[i][1]=right;
            }
        }
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;

    }
};