#include<vector>
using namespace std;
class Solution {
public:
    vector<int> res;
    void spiral(int beginx,int beginy,vector<vector<int>> matrix)
    {

        for(int i=beginy;i<matrix[0].size()-beginy;i++)
            res.push_back(matrix[beginx][i]);
        if(beginx+1>matrix.size()-beginx-1)
            return;
        for(int i=beginx+1;i<matrix.size()-beginx;i++)
            res.push_back(matrix[i][matrix[0].size()-beginy-1]);
        for(int i=matrix[0].size()-beginy-2;i>=beginy&&(matrix.size()-beginx-1!=beginx);i--)
            res.push_back(matrix[matrix.size()-beginx-1][i]);
        
        for(int i=matrix.size()-beginx-2;i>beginx;i--)
            res.push_back(matrix[i][beginy]);


    }
    vector<int> spiralOrder(vector<vector<int>>& matrix)
    {
        if(matrix.size()==0)
            return res;
        if(matrix[0].size()==1)
        {
            for(int i=0;i<matrix.size();i++)
                res.push_back(matrix[i][0]);
            return res;
        }
        for(int i=0;i<=matrix.size()/2;i++)
        {
            if(matrix[i].size()-1>=i)
            spiral(i,i,matrix);
        }
        return res;
    }
};