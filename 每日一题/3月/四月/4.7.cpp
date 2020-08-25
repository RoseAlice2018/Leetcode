#include<vector>
using namespace std;
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) 
    {
        //2. not use additional space
        for(int i=0;i<matrix.size()/2;i++)
        {
            for(int j=0;j<matrix.size();j++)
            {
                int temp=matrix[i][j];
                matrix[i][j]=matrix[matrix.size()-i-1][j];
                matrix[matrix.size()-1-i][j]=temp;
            }
        }
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<i;j++)
            {
                int temp=matrix[i][j];
                matrix[i][j]=matrix[j][i];
                matrix[j][i]=temp;
            }
        }
    }
};