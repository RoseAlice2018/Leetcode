#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
public:
    void setMatrix(vector<vector<int>>& matrix,int i,int j)
    {
        for(int k=0;k<matrix[i].size();k++)
            matrix[i][k]=0;
        for(int m=0;m<matrix.size();m++)
            matrix[m][j]=0;
    }
    void setZeroes(vector<vector<int>>& matrix) 
    {
        vector<pair<int,int>> zero;
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[0].size();j++)
            {
                if(matrix[i][j]==0)
                    zero.push_back(pair(i,j));
            }
        }
        for(int i=0;i<zero.size();i++)
        {
             setMatrix(matrix,zero[i].first,zero[i].second);
        }
           
    }
};